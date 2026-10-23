# Solidity Static Vulnerability Analyzer

A lightweight and fast static analysis tool built to detect critical vulnerabilities in smart contracts. I developed this project to combine low-level performance with a clean rule-checking pipeline.

## Architecture

The project uses a hybrid approach:
- **C Lexer (`lexer.c`):** Parses Solidity source files at high speed, tokenizing keywords, state variables, and low-level call patterns.
- **Python Engine (`engine.py`):** Processes the token stream and executes rule sets to flag security risks.

## Target Vulnerabilities

The analyzer currently focuses on the top 3 critical smart contract vulnerabilities:
1. **Reentrancy:** Detects state modifications happening after external calls.
2. **Access Control (`tx.origin`):** Flags dangerous authentication patterns using `tx.origin`.
3. **Unchecked Low-Level Calls:** Identifies risky `.call()` implementations without proper return value checks.

## Usage

1. Compile the C lexer:
   ```bash
   gcc lexer.c -o lexer
   ```

2. Run the analysis engine against a target contract:
   ```bash
   python engine.py VulnerableBank.sol
   ```
