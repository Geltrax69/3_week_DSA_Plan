#!/usr/bin/env python3
"""
MCP Auto-Commit Script
Analyzes C++ code and automatically commits changes to git when files are saved.
"""

import os
import json
import subprocess
import sys
from datetime import datetime
from pathlib import Path

class CodeAnalyzerCommitter:
    def __init__(self, repo_path):
        self.repo_path = repo_path
        self.git_path = os.path.join(repo_path, '.git')
        
    def analyze_code(self, file_path):
        """Analyze the C++ code and return insights"""
        try:
            with open(file_path, 'r') as f:
                content = f.read()
            
            analysis = {
                'file': os.path.basename(file_path),
                'lines': len(content.split('\n')),
                'has_includes': '#include' in content,
                'has_main': 'int main' in content,
                'has_vector': 'std::vector' in content,
                'has_iostream': 'iostream' in content,
                'timestamp': datetime.now().isoformat()
            }
            return analysis
        except Exception as e:
            print(f"Error analyzing code: {e}")
            return None
    
    def get_commit_message(self, analysis):
        """Generate an intelligent commit message based on analysis"""
        messages = []
        
        if analysis['has_vector']:
            messages.append("Add vector implementation")
        if analysis['has_main']:
            messages.append("Add main function")
        
        if not messages:
            messages.append("Update code")
        
        msg = " and ".join(messages)
        msg += f" ({analysis['lines']} lines)"
        return msg
    
    def stage_changes(self):
        """Stage all changes"""
        try:
            subprocess.run(['git', 'add', '.'], cwd=self.repo_path, check=True, 
                          capture_output=True)
            return True
        except subprocess.CalledProcessError as e:
            print(f"Error staging changes: {e}")
            return False
    
    def commit_changes(self, message):
        """Commit changes with the generated message"""
        try:
            # Check if there are changes to commit
            result = subprocess.run(['git', 'diff', '--cached', '--quiet'], 
                                  cwd=self.repo_path)
            
            if result.returncode != 0:  # There are changes
                subprocess.run(['git', 'commit', '-m', message], 
                             cwd=self.repo_path, check=True,
                             capture_output=True)
                print(f"✓ Committed: {message}")
                return True
            else:
                print("✓ No changes to commit")
                return False
        except subprocess.CalledProcessError as e:
            print(f"Error committing changes: {e}")
            return False
    
    def process_file(self, file_path):
        """Main process: analyze and commit"""
        print(f"\n📝 Processing: {os.path.basename(file_path)}")
        
        # Analyze the code
        analysis = self.analyze_code(file_path)
        if not analysis:
            return False
        
        print(f"   Lines: {analysis['lines']}")
        print(f"   Has main: {analysis['has_main']}")
        print(f"   Has vector: {analysis['has_vector']}")
        
        # Stage changes
        if not self.stage_changes():
            return False
        
        # Generate commit message
        commit_msg = self.get_commit_message(analysis)
        
        # Commit
        return self.commit_changes(commit_msg)


def watch_and_commit(repo_path, file_to_watch):
    """Watch file and commit on changes"""
    if not os.path.isdir(os.path.join(repo_path, '.git')):
        print(f"Error: {repo_path} is not a git repository")
        sys.exit(1)
    
    committer = CodeAnalyzerCommitter(repo_path)
    
    print(f"🔍 Watching: {file_to_watch}")
    print(f"📦 Repository: {repo_path}")
    print("Press Ctrl+C to stop\n")
    
    last_mtime = os.path.getmtime(file_to_watch)
    
    try:
        while True:
            current_mtime = os.path.getmtime(file_to_watch)
            if current_mtime != last_mtime:
                committer.process_file(file_to_watch)
                last_mtime = current_mtime
    except KeyboardInterrupt:
        print("\n\n✓ Watcher stopped")
        sys.exit(0)


if __name__ == "__main__":
    # Get repo path and file to watch
    repo_path = os.getcwd()
    file_to_watch = "vector.cpp"
    
    if len(sys.argv) > 1:
        file_to_watch = sys.argv[1]
    
    full_path = os.path.join(repo_path, file_to_watch)
    
    if not os.path.exists(full_path):
        print(f"Error: File not found: {full_path}")
        sys.exit(1)
    
    watch_and_commit(repo_path, full_path)
