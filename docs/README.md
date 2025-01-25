
# **Probability Calculator CLI Tool Documentation**

This document provides detailed information on the structure, functionality, and usage of the **Probability Calculator CLI Tool**.

---

## **Overview**

The **Probability Calculator** is a command-line tool that helps in calculating various types of probabilities, including:

- **Simple Probability**
- **Conditional Probability**
- **Random Variable Probability**

The program is divided into multiple modules for easier maintenance and understanding. It is written in **C** and can be compiled and run on both **Linux** and **Windows** systems.

---

## **Directory Structure**

The project is organized into the following directories and files:

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

### **src/**

- `main.c`: The entry point for the application. It includes the logic for displaying the main menu and invoking the correct functions for different probability calculations.
- `simple_probability.c`: Contains functions for handling simple probability calculations, including functions to gather input, calculate probabilities, and display results.
- `conditional_probability.c`: Contains functions for handling conditional probability calculations (e.g., calculating `P(N|X)`).
- `random_variable_probability.c`: This file will include the logic for handling random variable probabilities, though this functionality is to be developed.
- `utils.c`: Contains utility functions such as validation functions, display functions, and helper functions used across other files.

### **include/**

- `simple_probability.h`: Header file declaring functions related to simple probability.
- `conditional_probability.h`: Header file declaring functions related to conditional probability.
- `random_variable_probability.h`: Header file declaring functions related to random variable probability.
- `utils.h`: Header file declaring utility functions.

---

## **Key Functions**

### **main.c**
- **`main()`**: Displays the main menu and handles user input to navigate to different modules (simple probability, conditional probability).
  
### **simple_probability.c**
- **`simpleProbabilityFunc()`**: The function that handles the logic for simple probability calculations, including data input, displaying results, and interacting with the user.
- **`getSimpleProbabilityData()`**: Gathers data on the number of favorable attempts and computes the total attempts.
- **`calculateSimpleProbability()`**: Calculates and returns the simple probability for a given index.
- **`displaySimpleProbabilityData()`**: Displays the values of the elements and probabilities for simple probability.
- **`displaySimpleProbabilityQuestions()`**: Displays the questions related to simple probability, prompting the user for input.
- **`validateAttempt()`**: Validates whether the input is a positive integer.
  
### **conditional_probability.c**
- **`conditionalProbabilityFunc()`**: Handles the logic for conditional probability calculations (e.g., calculating `P(N|X)`), including input collection, displaying results, and interacting with the user.
- **`getConditionalProbabilityData()`**: Collects data for conditional probabilities, validating inputs.
- **`calculateConditionalProbability()`**: Calculates and returns the conditional probability for a given statement.
- **`displayConditionalProbabilityData()`**: Displays the conditional probability values.
- **`displayConditionalProbabilityQuestions()`**: Displays the questions related to conditional probability, prompting the user for input.
  
### **random_variable_probability.c**
- **`randomVariableProbabilityFunc()`**: Handles the logic for random variable probability calculations.
- **`getRandomVarProbabilityDistributionData()`**: Collects the probability distribution data for the random variable.
- **`calculateRandomVarProbability()`**: Calculates the probability for a random variable based on the provided distribution.
- **`displayRandomVarProbabilityDistribution()`**: Displays the random variable probability distribution.
- **`displayRandomVarProbabilityQuestions()`**: Displays the questions related to random variable probability.

### **utils.c**
- **`printLine()`**: Prints a line of dashes for formatting output.
- **`validateProbability()`**: Ensures that a probability value entered by the user is valid (between 0 and 1).
- **`validateAttempt()`**: Validates whether an attempt is a positive integer.

---

## **Functionality**

### **Simple Probability**

1. **Input**: The user is prompted to enter the number of elements and the favorable attempts for each element.
2. **Calculation**: The program calculates the simple probability `P(A) = favorable attempts / total attempts`.
3. **Output**: Displays the result for the selected element.

### **Conditional Probability**

1. **Input**: The user is asked to input `P(A)` and `P(B|A)` for a set of elements.
2. **Calculation**: The program calculates conditional probability using the formula `P(A|B) = P(A and B) / P(B)`.
3. **Output**: Displays the result for the selected conditional probability.

### **Random Variable Probability**

1. **Input**: The user is prompted to input the probability distribution for a random variable.
2. **Calculation**: The program calculates the probability for the given random variable using the provided distribution.
3. **Output**: Displays the result for the selected random variable probability.

---

## **Contributing**

We welcome contributions to improve the project. If you find any bugs or want to add new features, feel free to open an issue or submit a pull request.

To contribute:

1. Fork the repository.
2. Create a new branch for your changes.
3. Commit your changes.
4. Push to the branch and submit a pull request.

---

## **License**

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---