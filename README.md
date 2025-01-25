
# **Probability Calculator CLI Tool**

A command-line interface (CLI) tool for calculating various types of probabilities, including simple, conditional, and random variable probabilities.

-  [Documentation](./docs/README.md)
- [Design](./docs/Design.md)

---

## **Installation Guide**

### **On Linux**

1. Clone the repository:

   ```bash
   git clone https://github.com/DilipKhunti/Probability-Calculator_CLI_Tool.git
   cd Probability-Calculator_CLI_Tool
   ```


2. Build the project using `Makefile`:

   ```bash
   make
   ```

3. After a successful build, run the tool:

   ```bash
   ./probability_calculator
   ```

### **On Windows**

1. Clone the repository:

   ```bash
   git clone https://github.com/DilipKhunti/Probability-Calculator_CLI_Tool.git
   cd Probability-Calculator_CLI_Tool
   ```

2. Install [MinGW](https://sourceforge.net/projects/mingw/) to get GCC for Windows, or use any other compatible compiler.

3. Compile the source files using GCC:

   ```bash
   gcc -Wall -Wextra -Iinclude src/*.c -o probability_calculator
   ```

4. After compiling, run the tool in the Command Prompt:

   ```bash
   probability_calculator.exe
   ```

---

## **Usage**

Once the program is built and running, you can interact with the CLI to calculate different probabilities.

---

## Directory Structure
```
Directory structure:
└── dilipkhunti-probability-calculator_cli_tool/
    ├── README.md
    ├── LICENSE
    ├── Makefile
    ├── docs/
    │   ├── README.md
    │   └── Design.md
    ├── include/
    │   ├── conditional_probability.h
    │   ├── random_variable_probability.h
    │   ├── simple_probability.h
    │   └── utils.h
    └── src/
        ├── conditional_probability.c
        ├── main.c
        ├── random_variable_probability.c
        ├── simple_probability.c
        └── utils.c
```

---

## **Contributing**

Feel free to fork the repository and submit pull requests for improvements. Issues and feature requests are welcome.

---

## **License**

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---