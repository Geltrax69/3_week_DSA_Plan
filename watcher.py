#!/usr/bin/env python3
"""
Auto-commit watcher that runs in background
Monitors file changes and auto-commits with code analysis
"""

import os
import sys
import time
import subprocess
from pathlib import Path
from datetime import datetime

def run_analysis_and_commit(file_path):
    """Run code analysis and commit"""
    repo_path = os.path.dirname(file_path)
    
    try:
        # Check if git is initialized
        if not os.path.exists(os.path.join(repo_path, '.git')):
            return False
        
        # Stage the file
        subprocess.run(['git', 'add', os.path.basename(file_path)], 
                      cwd=repo_path, capture_output=True)
        
        # Check if there are changes
        result = subprocess.run(['git', 'diff', '--cached', '--quiet'], 
                              cwd=repo_path)
        
        if result.returncode == 0:  # No changes
            return False
        
        # Analyze and generate message
        with open(file_path, 'r') as f:
            content = f.read()
        
        changes = []
        if 'std::vector' in content:
            changes.append("vector usage")
        if '#include' in content:
            changes.append("includes")
        
        msg = f"Auto-commit: Update {os.path.basename(file_path)} - {', '.join(changes) if changes else 'minor changes'}"
        
        # Commit
        result = subprocess.run(['git', 'commit', '-m', msg], 
                              cwd=repo_path, capture_output=True, text=True)
        
        if result.returncode == 0:
            print(f"✓ {msg}")
            return True
        
    except Exception as e:
        print(f"Error: {e}")
    
    return False


def main():
    if len(sys.argv) < 2:
        print("Usage: python3 watcher.py <file_path>")
        sys.exit(1)
    
    file_path = sys.argv[1]
    
    if not os.path.exists(file_path):
        print(f"File not found: {file_path}")
        sys.exit(1)
    
    last_mtime = 0
    
    print(f"🔍 Watching: {file_path}")
    print("Auto-commit enabled on file save")
    
    while True:
        try:
            current_mtime = os.path.getmtime(file_path)
            if current_mtime > last_mtime and last_mtime > 0:
                time.sleep(0.5)  # Wait for file to be fully saved
                run_analysis_and_commit(file_path)
            last_mtime = current_mtime
            time.sleep(1)  # Check every second
        except KeyboardInterrupt:
            print("\nWatcher stopped")
            break
        except Exception as e:
            print(f"Error: {e}")
