<div align="center">
  <table>
    <tr>
      <td valign="middle">
        <img
          src="https://res.cloudinary.com/dqpszz96x/image/upload/v1788529194/favicon_ry6wga.svg"
          width="100px"
          alt="Mystic Framework Logo"
        />
      </td>
      <td valign="middle">
        <h1>mystic framework</h1>
      </td>
    </tr>
  </table>
  <div>
    <h1>Github Actions</h1>
    <p>A consolidated group of composite GitHub Actions to streamline CI/CD workflows.</p>
  </div>
</div>

<p align="center">
 <img
    src="https://img.shields.io/badge/GitHub_Actions-444444?style=flat&logo=github&logoColor=white"
    alt="GitHub Actions"
  />
 <img
    src="https://img.shields.io/badge/Apache%202.0-444444?style=flat&logo=apache&logoColor=white"
    alt="License: Apache 2.0"
  />
  <img
    src="https://img.shields.io/badge/Ver_1.0.0-007acc?style=flat"
    alt="Version: 1.0.0"
  />
</p>

<details>
<summary>Table of Contents (click to show)</summary>

- [About](#about)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Actions - Pre Commit](#actions---pre-commit)
  - [Actions - C++ Compatibility](#actions---c-compatibility)
  - [Actions - Python Compatibility](#actions---python-compatibility)
  - [Actions - SonarQube Coverage](#actions---sonarqube-coverage)
- [Contributing](#contributing)
- [License](#license)

</details>

# About

`mystic-framework/github-actions` is a consolidated group of composite [GitHub Actions](https://docs.github.com/en/actions) designed to
streamline CI/CD workflows. It is highly customizable, cross-platform, and enforces best practices for writing good actions.

It includes actions for:
- Pre-Commit Checks
- C++ Compatibility & Linting and Static Analysis
- Python Compatibility & Linting
- SonarQubeCloud Integration

To view the in-depth documentation of this project, please refer to [MFW's GitHub Actions module documentation](https://mystic-framework.github.io/docs/modules/github-actions).

# Features

- **Cross Platform:** Supports various platforms such as Windows, Linux, and macOS.
- **Customizable:** Highly flexible via comprehensive options to customize the action.
- **Builtin Cache Support:** Supports caching the resources for faster re-runs.
- **Actions-idiomatic:** Written with best practices in mind. Clear and performant.

# Getting Started

The module provides following actions:

| Action | Description |
| ------ | ----------- |
| `pre-commit` | Runs pre-commit to ensure code passes basic expectations. |
| `cpp-compatibility` | Builds the project (support for various OSes) and tests it against the provided test files. |
| `python-compatibility` | Runs the python project against the provided test files to ensure correct logic. |
| `sonarqube` | Generates test coverage files and uploads it to SonarQubeCloud. |

## Actions - Pre Commit

[![Test Pre Commit Action](https://github.com/mystic-framework/github-actions/actions/workflows/test-pre-commit.yaml/badge.svg)](https://github.com/thedevmystic/github-actions/actions/workflows/test-pre-commit.yaml)

This action configures python and pre-commit and runs it to ensure basic code hygiene.

| Argument | Description |
| -------- | ---------- |
| `use-cache` | Whether to use cache or not. Defaults to `true`. |
| `args` | Additional arguments passed to pre-commit. |

**Example:**
```yaml
name: "Pre Commit"

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main
  workflow_dispatch:

jobs:
  pre-commit:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout Repository
        uses: actions/checkout@v7

      - name: Pre Commit
        uses: mystic-framework/github-actions/pre-commit@v1
```

## Actions - C++ Compatibility

[![Test C++ Compatibility Action](https://github.com/mystic-framework/github-actions/actions/workflows/test-cpp-compatibility.yaml/badge.svg)](https://github.com/thedevmystic/github-actions/actions/workflows/test-cpp-compatibility.yaml)

This action builds a CMake-based C++ project (via Ninja) and optionally runs its test suite with CTest. It supports cross-compiler
configuration and caching of build artifacts and ccache data for faster re-runs.

| Argument | Description |
| -------- | ----------- |
| `use-cache` | Whether to use cache or not. Defaults to `true`. |
| `compiler` | Compiler to run the compatibility check. Defaults to `gcc`. |
| `install-command` | Install command to run before setup (e.g., installing system dependencies). Defaults to `""`. |
| `build-type` | Build type of the project. Defaults to `Release`. |
| `working-directory` | Current working directory (i.e., where `CMakeLists.txt` is located). Defaults to `.`. |
| `additional-cmake-args` | Additional CMake arguments. Defaults to `""`. |
| `run-tests` | Whether to run tests or not. Defaults to `true`. |

**Example:**
```yaml
name: "C++ Compatibility"

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main
  workflow_dispatch:

jobs:
  cpp-compatibility:
    strategy:
      matrix:
        os: [ubuntu-latest, windows-latest, macos-latest]
        compiler: [gcc, clang]
    runs-on: ${{ matrix.os }}
    steps:
      - name: Checkout Repository
        uses: actions/checkout@v7

      - name: C++ Compatibility
        uses: mystic-framework/github-actions/cpp-compatibility@v1
        with:
          compiler: ${{ matrix.compiler }}
          build-type: Release
```

## Actions - Python Compatibility

[![Test Python Compatibility Action](https://github.com/mystic-framework/github-actions/actions/workflows/test-python-compatibility.yaml/badge.svg)](https://github.com/thedevmystic/github-actions/actions/workflows/test-python-compatibility.yaml)

This action sets up a Python environment, optionally lints/format-checks the project with Ruff, and runs its test suite with
pytest. Dependency and virtual environment caching is supported out of the box.

| Argument | Description |
| -------- | ----------- |
| `python-version` | Python version to use for the compatibility check. Defaults to `3.x`. |
| `use-cache` | Whether to use cache or not. Defaults to `true`. |
| `install-command` | Install command to run. Defaults to `pip install --group dev .`. |
| `working-directory` | Where the Python project (`requirements.txt` / `pyproject.toml`) is located. Defaults to `.`. |
| `lint` | Whether to run Ruff format check and lint or not. Defaults to `true`. |
| `run-tests` | Whether to run tests or not. Defaults to `true`. |

**Example:**
```yaml
name: "Python Compatibility"

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main
  workflow_dispatch:

jobs:
  python-compatibility:
    strategy:
      matrix:
        python-version: ["3.11", "3.12", "3.x"]
    runs-on: ubuntu-latest
    steps:
      - name: Checkout Repository
        uses: actions/checkout@v7

      - name: Python Compatibility
        uses: mystic-framework/github-actions/python-compatibility@v1
        with:
          python-version: ${{ matrix.python-version }}
```

## Actions - SonarQube Coverage

[![Test SonarQube Action - C++](https://github.com/mystic-framework/github-actions/actions/workflows/cpp-coverage.yaml/badge.svg)](https://github.com/thedevmystic/github-actions/actions/workflows/cpp-coverage.yaml)
[![Test SonarQube Action - Python](https://github.com/mystic-framework/github-actions/actions/workflows/python-coverage.yaml/badge.svg)](https://github.com/thedevmystic/github-actions/actions/workflows/python-coverage.yaml)

This action generates test coverage reports for either a C++ or Python project and uploads them to SonarQube Cloud. Behavior
branches based on the `language` input, so C++-only and Python-only arguments only apply when the matching language is selected.

**Common Arguments**

| Argument | Description |
| -------- | ----------- |
| `language` | The language of the project. Valid options: `cpp` or `python`. **Required.** |
| `sonar-token` | SonarQube Cloud token. **Required** — pass this from a repository secret. |
| `use-cache` | Whether to use cache or not. Defaults to `true`. |
| `working-directory` | Current working directory (i.e., where `CMakeLists.txt` / `pyproject.toml` is located). Defaults to `.`. |

**C++-specific Arguments**

| Argument | Description |
| -------- | ----------- |
| `cpp-coverage-tool` | Coverage tool used for C++. Valid options: `gcov` or `llvm-cov`. Defaults to `llvm-cov`. |
| `cpp-coverage-tool-args` | Any additional arguments passed to gcov or llvm-cov. Defaults to `""`. |
| `cpp-coverage-option` | CMake option that enables coverage building for your project. Defaults to `MYSTIC_ENABLE_COVERAGE`. |
| `additional-cmake-args` | Additional CMake arguments. Defaults to `""`. |

**Python-specific Arguments**

| Argument | Description |
| -------- | ----------- |
| `python-coverage-tool-args` | Any additional arguments passed to the Python coverage tool. Defaults to `""`. |

**Example (C++):**
```yaml
name: "SonarQube Coverage"

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main

jobs:
  sonarqube:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout Repository
        uses: actions/checkout@v7
        with:
          fetch-depth: 0

      - name: SonarQube Coverage
        uses: mystic-framework/github-actions/sonarqube@v1
        with:
          language: cpp
          sonar-token: ${{ secrets.SONAR_TOKEN }}
          cpp-coverage-tool: llvm-cov
          cpp-coverage-option: MYSTIC_ENABLE_COVERAGE
```

**Example (Python):**
```yaml
name: "SonarQube Coverage"

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main

jobs:
  sonarqube:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout Repository
        uses: actions/checkout@v7
        with:
          fetch-depth: 0

      - name: SonarQube Coverage
        uses: mystic-framework/github-actions/sonarqube@v1
        with:
          language: python
          sonar-token: ${{ secrets.SONAR_TOKEN }}
```

# Contributing

Thank you for your interest in contributing on this project! To streamline the review process and maintain a healthy community please follow:
- [Community Guidelines](https://mystic-framework.github.io/docs/contributing)
- [Code of Conduct](https://mystic-framework.github.io/docs/code-of-conduct)

# License

The project is licensed under the Apache 2.0 License. For more information regarding the licensing visit: [License](./LICENSE) or
[Framework Licnese](https://mystic-framework.github.io/docs/license).
