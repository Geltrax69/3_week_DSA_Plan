#!/usr/bin/env python3
"""
Auto-commit watcher - Monitors file changes and auto-commits
"""

import os
import sys
import time
import subprocess

def commit_changes(file_path, repo_path):
    """Stage and commit changes"""
    try:
        file_name = os.path.basename(file_path)
        
        # Stage the file
        subprocess.run(['git', 'add', file_name], cwd=repo_path, 
                      capture_output=True, timeout=5)
        
        # Check if there are staged changes
        result = subprocess.run(['git', 'diff', '--cached', '--quiet'], 
                              cwd=repo_path, timeout=5)
        
        if result.returncode != 0:  # There are changes
            # Read file to analyze
            with open(file_path, 'r') as f:
                content = f.read()
            
            # Detect features
            features = []
            if 'vector<' in content or 'std::vector' in content:
                features.append("vector")
            if 'push_back' in content:
                features.append("push_back")
            if 'pop_back' in content:
                features.append("pop_back")
            if 'insert' in content:
                features.append("insert")
            if 'erase' in content:
                features.append("erase")
            
            feature_str = ", ".join(features[:3]) if features else "update"
            msg = f"Update: {feature_str} ({len(content.split(chr(10)))} lines)"
            
            # Commit
            result = subprocess.run(['git', 'commit', '-m', msg], 
                                  cwd=repo_path, capture_output=True, text=True)
            
            if result.returncode == 0:
                print(f"✓ Committed: {msg}")
                return True
    except Exception as e:
        print(f"Error: {e}")
    
    return False


def main():
    if len(sys.argv) < 2:
        file_path = os.path.abspath("vector.cpp")
    else:
        file_path = os.path.abspath(sys.argv[1])
    
    if not os.path.exists(file_path):
        print(f"Error: File not found - {file_path}")
        sys.exit(1)
    
    repo_path = os.path.dirname(file_path)
    
    # Check git
    if not os.path.exists(os.path.join(repo_path, '.git')):
        print(f"Error: Not a git repository - {repo_path}")
        sys.exit(1)
    
    print(f"🔍 Watching: {file_path}")
    print(f"📦 Repository: {repo_path}")
    print("Auto-commit enabled - Press Ctrl+C to stop\n")
    
    last_mtime = os.path.getmtime(file_path)
    
    try:
        while True:
            time.sleep(1)
            try:
                current_mtime = os.path.getmtime(file_path)
                if current_mtime > last_mtime:
                    last_mtime = current_mtime
                    time.sleep(0.5)  # Wait for file write to complete
                    commit_changes(file_path, repo_path)
            except OSError:
                pass
    except KeyboardInterrupt:
        print("\n✓ Watcher stopped")
        sys.exit(0)


if __name__ == "__main__":
    main()
