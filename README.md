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
    src="https://img.shields.io/badge/Ver_0.0.1-007acc?style=flat"
    alt="Version: 0.0.1 Under Development"
  />
</p>

<details>
<summary>Table of Contents (click to show)</summary>

Add ToC here.

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

Add documentation here.

# Contributing

Thank you for your interest in contributing on this project! To streamline the review process and maintain a healthy community please follow:
- [Community Guidelines](https://mystic-framework.github.io/docs/contributing)
- [Code of Conduct](https://mystic-framework.github.io/docs/code-of-conduct)

# License

The project is licensed under the Apache 2.0 License. For more information regarding the licensing visit: [License](./LICENSE) or
[Framework Licnese](https://mystic-framework.github.io/docs/license).
