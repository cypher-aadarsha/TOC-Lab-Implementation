# Theory of Computation Lab Codes

## Overview

This repository contains a collection of C++ programs developed for the Theory of Computation lab exam. These programs implement various automata and string validation algorithms. Additionally, a Python script is provided to automate the compilation, execution, and report generation process.

**Student Details:**
- **Name:** Aadarsha Jha
- **Symbol No:** 023BSCIT050

## Repository Structure

The repository consists of the following key components:

### C++ Programs
The core logic for different theory of computation concepts:
1.  **`1_validate_strings.cpp`**: Validates strings against specific patterns.
2.  **`2_prefix.cpp`**: Generates or validates prefixes of a string.
3.  **`3_suffix.cpp`**: Generates or validates suffixes of a string.
4.  **`4_substring.cpp`**: Checks for substrings.
5.  **`5_dfa_aa.cpp`**: Deterministic Finite Automaton (DFA) related to 'aa'.
6.  **`6_dfa_mult3.cpp`**: DFA to check if a binary number is a multiple of 3.
7.  **`7_nfa_consecutive.cpp`**: Non-deterministic Finite Automaton (NFA) for consecutive characters.
8.  **`8_moore_aab.cpp`**: Moore machine implementation for sequence 'aab'.
9.  **`9_mealy_increment.cpp`**: Mealy machine to increment a binary number.
10. **`10_valid_c_id.cpp`**: Validates C identifiers.
11. **`11_valid_gmail.cpp`**: Validates Gmail addresses.
12. **`12_valid_mac.cpp`**: Validates MAC addresses.
13. **`13_re_aa.cpp`**: Regular Expression matching.
14. **`14_pda_anbn.cpp`**: Pushdown Automaton for language $a^n b^n$.
15. **`15_tm_anbncn.cpp`**: Turing Machine for language $a^n b^n c^n$.

### Automation
-   **`generate_pdf.py`**: A Python script that compiles each C++ program, runs it with defined inputs, captures the output, and compiles everything into a single PDF Lab Report (`Lab_Report_Aadarsha_Jha.pdf`).

## Prerequisites

To run the codes in this repository, you need the following installed on your system:

1.  **C++ Compiler**: MinGW (`g++`) or any standard C++ compiler added to your system's PATH.
2.  **Python 3.x**: For running the automation script.
3.  **Python Libraries**:
    -   `fpdf`: For PDF generation.
    -   `Pillow`: For image manipulation (capturing console-like outputs).

## Installation

1.  **Clone the repository** (or download the files):
    ```bash
    git clone <repository_url>
    cd <repository_name>
    ```

2.  **Install Python Dependencies**:
    ```bash
    pip install fpdf pillow
    ```

## Usage

### Running Individual C++ Programs
You can compile and run any of the C++ files individually using `g++`. For example:

```bash
g++ -o output 1_validate_strings.cpp
./output
```

### Generating the Lab Report
To compile all programs and generate the PDF report:

1.  Open your terminal in the project directory.
2.  Run the Python script:
    ```bash
    python generate_pdf.py
    ```
3.  Upon successful execution, a file named `Lab_Report_Aadarsha_Jha.pdf` will be created in the same directory.

## Output Format
Each program is designed to output:
-   The specific logic result (e.g., String Accepted/Rejected).
-   A signature line: `executed by Aadarsha Jha (023BSCIT050)`.

## License
This project is for academic purposes for the Theory of Computation lab.

