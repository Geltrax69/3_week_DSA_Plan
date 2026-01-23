# Auto-Commit Script - MCP Code Analyzer

This script automatically analyzes your C++ code and commits changes to git when you save files.

## Features

✓ **Code Analysis** - Analyzes C++ code structure (includes, main function, vector usage, etc.)
✓ **Auto-Commit** - Commits changes automatically with intelligent commit messages
✓ **File Watching** - Monitors file changes in real-time
✓ **Git Integration** - Seamlessly integrates with your git workflow

## Setup

### Option 1: Run Watcher in Background (Recommended)

1. Open terminal in VS Code: **Ctrl + ~**
2. Run the watcher:
```bash
python3 watcher.py vector.cpp
```

This will continuously monitor `vector.cpp` and auto-commit on save.

### Option 2: One-Time Analysis & Commit

Run the analysis script for a single file:
```bash
python3 auto_commit.py vector.cpp
```

### Option 3: VS Code Task

Press **Cmd + Shift + P** and run:
```
Tasks: Run Task → Auto Commit on Save
```

## How It Works

1. **Detects Changes** - Monitors when you save your C++ file
2. **Analyzes Code** - Scans for:
   - Vector implementations
   - Main function
   - Include statements
   - Line counts
3. **Generates Message** - Creates intelligent commit messages like:
   - "Add vector implementation (25 lines)"
   - "Update code and main function (30 lines)"
4. **Auto-Commits** - Stages and commits changes to git

## Example Output

```
📝 Processing: vector.cpp
   Lines: 15
   Has main: True
   Has vector: True
✓ Committed: Add vector implementation (15 lines)
```

## Requirements

- Python 3.x
- Git
- Working git repository in your project

## Keyboard Shortcuts

- **Shift + Enter** - Compile and Run
- **Cmd + Shift + B** - Build Task
- **Ctrl + ~** - Toggle Terminal

## Stop Watcher

Press **Ctrl + C** in the terminal to stop the auto-commit watcher.
