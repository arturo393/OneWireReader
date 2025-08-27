# Contributing to OneWireReader

We love your input! We want to make contributing to OneWireReader as easy and transparent as possible, whether it's:

- Reporting a bug
- Discussing the current state of the code
- Submitting a fix
- Proposing new features
- Becoming a maintainer

## Development Process

We use GitHub to host code, to track issues and feature requests, as well as accept pull requests.

### We Use [Github Flow](https://guides.github.com/introduction/flow/index.html)

All code changes happen through pull requests. They are the best way to propose changes to the codebase:

1. Fork the repo and create your branch from `master`
2. If you've added code that should be tested, add tests
3. If you've changed APIs, update the documentation
4. Ensure the test suite passes
5. Make sure your code lints
6. Issue that pull request!

## Development Setup

### Prerequisites

- [PlatformIO](https://platformio.org/) (recommended) or Arduino IDE
- Git for version control
- A SparkFun Pro Micro or compatible Arduino Leonardo-style board for testing

### Setting Up Your Development Environment

1. **Fork and clone the repository**
   ```bash
   git clone https://github.com/YOUR_USERNAME/OneWireReader.git
   cd OneWireReader
   ```

2. **Install PlatformIO** (if not already installed)
   ```bash
   pip install platformio
   ```

3. **Build the project**
   ```bash
   platformio run
   ```

4. **Upload to your test hardware**
   ```bash
   platformio run --target upload
   ```

## Code Style Guidelines

### C++ Code Standards

- **Indentation**: Use 2 spaces, no tabs
- **Naming conventions**:
  - Variables: `camelCase`
  - Functions: `camelCase()`
  - Constants: `UPPER_CASE`
- **Comments**: Use `//` for single-line comments, `/* */` for multi-line
- **Line length**: Keep lines under 80 characters when possible

### Example Code Style

```cpp
// Good
OneWire ds(10);  // OneWire on pin 10 (4.7K resistor required)

void setup(void) {
  Serial.begin(9600);
  Keyboard.begin();
}

// Function with proper spacing and comments
void readOneWireDevice() {
  byte addr[8];
  char str[20];
  
  if (!ds.search(addr)) {
    Serial.println("No more addresses.");
    ds.reset_search();
    delay(250);
    return;
  }
  
  // Format and output the ROM address
  Serial.print("ROM =");
  for (byte i = 1; i <= 8; i++) {
    sprintf(str, "%02x", addr[8-i]);
    Serial.print(str);
    Keyboard.print(str);
  }
  
  Keyboard.println();
  delay(500);
}
```

## Commit Message Conventions

We follow conventional commit format for clear and searchable history:

### Format
```
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

### Types
- `feat`: A new feature
- `fix`: A bug fix
- `docs`: Documentation only changes
- `style`: Changes that do not affect the meaning of the code
- `refactor`: A code change that neither fixes a bug nor adds a feature
- `perf`: A code change that improves performance
- `test`: Adding missing tests or correcting existing tests
- `chore`: Changes to the build process or auxiliary tools

### Examples
```
feat: add support for different OneWire pins
fix: correct hex formatting for single-digit values
docs: update wiring diagram in README
refactor: simplify device scanning loop
```

## Pull Request Process

1. **Update documentation** if you change functionality
2. **Test your changes** on actual hardware if possible
3. **Update the CHANGELOG.md** with details of changes
4. **Ensure all checks pass** (build, style, etc.)

### Pull Request Template

When submitting a PR, please include:

```markdown
## Description
Brief description of changes

## Type of Change
- [ ] Bug fix (non-breaking change which fixes an issue)
- [ ] New feature (non-breaking change which adds functionality)
- [ ] Breaking change (fix or feature that would cause existing functionality to not work as expected)
- [ ] Documentation update

## Testing
- [ ] Code compiles without errors
- [ ] Tested on hardware (if applicable)
- [ ] All existing functionality still works

## Checklist
- [ ] Code follows the style guidelines
- [ ] Self-review of code completed
- [ ] Commented code, particularly in hard-to-understand areas
- [ ] Corresponding changes to documentation made
```

## Reporting Bugs

We use GitHub issues to track public bugs. Report a bug by [opening a new issue](https://github.com/arturo393/OneWireReader/issues).

### Good Bug Reports Include:

- **Summary**: A quick summary of the issue
- **Environment**: 
  - Arduino board model
  - PlatformIO/Arduino IDE version
  - Operating system
- **Steps to reproduce**: Detailed steps to reproduce the issue
- **Expected behavior**: What should happen
- **Actual behavior**: What actually happened
- **Additional context**: Screenshots, error messages, etc.

### Bug Report Template

```markdown
**Describe the bug**
A clear and concise description of what the bug is.

**To Reproduce**
Steps to reproduce the behavior:
1. Connect hardware as described...
2. Upload firmware...
3. Present OneWire device...
4. See error

**Expected behavior**
A clear and concise description of what you expected to happen.

**Environment:**
- Board: [e.g. SparkFun Pro Micro 16MHz]
- IDE: [e.g. PlatformIO 6.1.18]
- OS: [e.g. Windows 10, macOS 12.0]

**Additional context**
Add any other context about the problem here.
```

## Suggesting Features

We welcome feature suggestions! Please:

1. **Check existing issues** to avoid duplicates
2. **Provide a clear use case** for the feature
3. **Consider the scope** - keep features focused and relevant
4. **Be willing to contribute** code if possible

## Code of Conduct

### Our Pledge

We are committed to making participation in this project a harassment-free experience for everyone, regardless of age, body size, disability, ethnicity, gender identity and expression, level of experience, nationality, personal appearance, race, religion, or sexual identity and orientation.

### Our Standards

Examples of behavior that contributes to creating a positive environment include:

- Using welcoming and inclusive language
- Being respectful of differing viewpoints and experiences
- Gracefully accepting constructive criticism
- Focusing on what is best for the community
- Showing empathy towards other community members

## Getting Help

- **Documentation**: Check the [README.md](README.md) first
- **Issues**: Search existing [GitHub issues](https://github.com/arturo393/OneWireReader/issues)
- **Discussions**: Start a [GitHub discussion](https://github.com/arturo393/OneWireReader/discussions) for questions

## License

By contributing, you agree that your contributions will be licensed under the same license as the project (MIT License).

## Recognition

Contributors will be recognized in:
- Git commit history
- CHANGELOG.md for significant contributions
- README.md acknowledgments section

Thank you for contributing to OneWireReader! 🎉