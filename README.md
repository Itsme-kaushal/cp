# Competitive Programming Repository

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue)
![Language](https://img.shields.io/badge/language-C%2B%2B%2FPython-orange)

## Repository Purpose

This repository contains solutions and utilities for competitive programming practice. It includes problem solutions, debugging utilities, testing frameworks, and workflow automation for efficient problem-solving in contests like Codeforces, AtCoder, LeetCode, and other competitive programming platforms.

## Project Structure

```
cp/
├── .vscode/                 # VS Code configuration
│   ├── settings.json        # Editor settings
│   ├── tasks.json          # Build tasks
│   └── launch.json         # Debug configuration
├── potd/                    # Problem of the Day solutions
│   ├── 2025-01/            # Monthly organization
│   └── archive/            # Archived solutions
├── debugging/               # Debugging utilities and macros
│   ├── debug.h             # Debug macro definitions
│   ├── fast_io.h          # Fast I/O templates
│   └── stress_test.py     # Stress testing utilities
├── contests/               # Contest-specific solutions
│   ├── codeforces/
│   ├── atcoder/
│   └── leetcode/
├── templates/              # Code templates
│   ├── template.cpp
│   └── template.py
├── utils/                  # Utility scripts
│   ├── parser.py          # Problem parser
│   └── submitter.py       # Auto-submission tools
└── README.md
```

## Getting Started

### Prerequisites
- C++ compiler (g++ 11 or later recommended)
- Python 3.8+
- VS Code (recommended IDE)
- Git

### Quick Setup
```bash
git clone https://github.com/Itsme-kaushal/cp.git
cd cp
# Install Python dependencies
pip install -r requirements.txt
# Compile debug utilities
g++ -o debug debugging/debug.cpp
```

## Debugging Utilities

### Debug Macros
Use the debug macros from `debugging/debug.h`:

```cpp
#include "debugging/debug.h"

// Debug single variable
debug(x);

// Debug multiple variables
debug(x, y, z);

// Debug containers
vector<int> v = {1, 2, 3};
debug(v);

// Debug with custom message
debug("Processing step", step, "with value", value);
```

### Fast I/O
Include fast I/O optimizations:

```cpp
#include "debugging/fast_io.h"

int main() {
    fast_io();
    // Your code here
    return 0;
}
```

### Local Testing
```bash
# Compile with debug flags
g++ -DLOCAL -std=c++17 -O2 -Wall -Wextra -o solution solution.cpp

# Run with input/output files
./solution < input.txt > output.txt

# Compare with expected output
diff output.txt expected.txt
```

### Stress Testing
Use the stress testing utility:

```bash
python3 debugging/stress_test.py --generator gen.cpp --solution sol.cpp --brute brute.cpp --tests 1000
```

## POTD (Problem of the Day) Workflow

### Daily Routine
1. **Pick a Problem**: Select from your target platform
2. **Create Solution File**: 
   ```bash
   # Create new POTD entry
   mkdir -p potd/$(date +%Y-%m)
   cp templates/template.cpp potd/$(date +%Y-%m)/$(date +%d)_problem_name.cpp
   ```
3. **Solve & Debug**: Use debugging utilities while solving
4. **Test Thoroughly**: Run stress tests and edge cases
5. **Document**: Add comments and complexity analysis
6. **Commit**: Use consistent commit messages

### POTD Commands
```bash
# Quick POTD setup
make potd PROBLEM="two_sum"

# Test POTD solution
make test-potd DATE="2025-01-10"

# Archive completed POTD
make archive-potd MONTH="2025-01"
```

## Contribution Guidelines

### Code Style
- Use consistent indentation (2 spaces)
- Follow naming conventions: `snake_case` for variables, `PascalCase` for classes
- Add complexity analysis in comments
- Include test cases for each solution

### Commit Message Format
```
type(scope): description

Types:
- feat: new solution or feature
- fix: bug fix in existing solution
- docs: documentation updates
- refactor: code refactoring
- test: adding tests
- style: formatting changes

Examples:
feat(potd): add two sum solution with O(n) approach
fix(debug): correct macro expansion for containers
docs: update README with stress testing guide
```

### Pull Request Process
1. Create feature branch: `git checkout -b feature/problem-name`
2. Make changes with proper commits
3. Test thoroughly
4. Submit PR with clear description

## Folder Conventions

### Naming Conventions
- **Problem files**: `problem_name.cpp` or `problem_name.py`
- **Contest folders**: `platform_contest_name/`
- **Date format**: `YYYY-MM-DD` for daily problems
- **Archive format**: `YYYY-MM/` for monthly archives

### File Organization
- One problem per file
- Include problem statement link in comments
- Add time/space complexity analysis
- Include sample test cases

## Build & Run Commands

### C++ Commands
```bash
# Development build (with debug)
g++ -DLOCAL -std=c++17 -O2 -Wall -Wextra -g -o solution solution.cpp

# Contest build (optimized)
g++ -std=c++17 -O2 -o solution solution.cpp

# Run with timing
time ./solution < input.txt

# Memory check (if valgrind available)
valgrind --tool=memcheck ./solution < input.txt
```

### Python Commands
```bash
# Run Python solution
python3 solution.py < input.txt

# Run with timing
time python3 solution.py < input.txt

# Profile Python code
python3 -m cProfile solution.py < input.txt

# Check with PyPy (faster execution)
pypy3 solution.py < input.txt
```

### Makefile Targets
```bash
# Build current solution
make build

# Test with sample input
make test

# Clean build artifacts
make clean

# Run stress test
make stress

# Submit solution (if configured)
make submit
```

## VS Code Setup Tips

### Recommended Extensions
- C/C++ (Microsoft)
- Python (Microsoft) 
- Code Runner
- GitLens
- Competitive Programming Helper

### Key Settings
Add to `.vscode/settings.json`:
```json
{
    "code-runner.executorMap": {
        "cpp": "cd $dir && g++ -DLOCAL -std=c++17 -O2 -Wall -Wextra -o $fileNameWithoutExt $fileName && ./$fileNameWithoutExt",
        "python": "cd $dir && python3 $fileName"
    },
    "code-runner.runInTerminal": true,
    "files.associations": {
        "*.h": "cpp"
    }
}
```

### Useful Shortcuts
- `Ctrl+Alt+N`: Run code
- `F5`: Debug
- `Ctrl+Shift+P`: Command palette
- `Ctrl+` `: Toggle terminal

## Testing with Sample I/O

### Input/Output Files
```bash
# Create test files
echo "5 3\n1 2 3 4 5" > input.txt
echo "3" > expected.txt

# Run test
./solution < input.txt > output.txt
diff output.txt expected.txt
```

### Automated Testing Script
```bash
#!/bin/bash
# test.sh
for i in {1..5}; do
    echo "Testing case $i..."
    ./solution < test$i.txt > out$i.txt
    if diff out$i.txt expected$i.txt > /dev/null; then
        echo "✓ Test $i passed"
    else
        echo "✗ Test $i failed"
        exit 1
    fi
done
echo "All tests passed!"
```

## Git Hooks (Optional)

### Pre-commit Hook
Create `.git/hooks/pre-commit`:
```bash
#!/bin/bash
# Compile check for C++ files
for file in $(git diff --cached --name-only | grep '\.cpp$'); do
    g++ -std=c++17 -Wall -Wextra -fsyntax-only "$file"
    if [ $? -ne 0 ]; then
        echo "Compilation failed for $file"
        exit 1
    fi
done

# Python syntax check
for file in $(git diff --cached --name-only | grep '\.py$'); do
    python3 -m py_compile "$file"
    if [ $? -ne 0 ]; then
        echo "Python syntax error in $file"
        exit 1
    fi
done
```

### Pre-push Hook
Create `.git/hooks/pre-push`:
```bash
#!/bin/bash
# Run tests before push
make test
if [ $? -ne 0 ]; then
    echo "Tests failed. Push aborted."
    exit 1
fi
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Badges

- ![Solved Problems](https://img.shields.io/badge/solved-0-blue) (Update with actual count)
- ![Last Commit](https://img.shields.io/github/last-commit/Itsme-kaushal/cp)
- ![Repo Size](https://img.shields.io/github/repo-size/Itsme-kaushal/cp)
- ![Contributors](https://img.shields.io/github/contributors/Itsme-kaushal/cp)

---

**Happy Coding! 🚀**

*Remember: Consistency is key in competitive programming. Solve at least one problem daily!*
