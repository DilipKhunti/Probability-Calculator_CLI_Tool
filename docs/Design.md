

# **Probability Calculator CLI Tool - Design Document**

This document outlines the design of the **Probability Calculator CLI Tool**. It provides an overview of the system architecture, data flow, and how the modules and functions work together to calculate probabilities.

---

## **Overview**

The **Probability Calculator CLI Tool** is designed to calculate different types of probabilities, including:

- **Simple Probability**
- **Conditional Probability**
- **Random Variable Probability**

The tool is structured into multiple modules for maintainability and modularity. It is written in **C** and is designed to run on both **Linux** and **Windows** systems.

---

## **System Architecture**

The **Probability Calculator** follows a modular approach with separate files for each major functionality:

### **Modules**

- **Main Module**: The entry point of the application. It displays a menu to the user and provides options to calculate different types of probabilities.
- **Simple Probability Module**: Contains the logic for calculating simple probabilities. This module allows the user to enter the number of favorable attempts and the total attempts to calculate `P(A)`.
- **Conditional Probability Module**: Provides functionality to calculate conditional probabilities using the formula `P(A|B) = P(A and B) / P(B)`. This module asks the user for probabilities like `P(A)` and `P(B|A)` and calculates the result.
- **Random Variable Probability Module**: This module is responsible for calculating the probabilities for random variables. It uses a given distribution and returns the probability based on the provided data.
- **Utilities Module**: Contains helper functions for validating inputs and formatting output. It is used across all the modules to ensure data integrity and user-friendly display.

---

## **Data Flow**

1. **User Interaction**: The user starts by running the program, which displays a main menu with options to select a probability type (Simple, Conditional, Random Variable). The user selects an option and enters the required data.

2. **Data Input**: Based on the selected probability type, the corresponding module (e.g., Simple Probability, Conditional Probability, etc.) prompts the user for the necessary inputs. These inputs are validated to ensure correctness.

3. **Calculation**: The corresponding module performs the required calculations:
   - **Simple Probability**: Calculates the probability based on the number of favorable and total attempts.
   - **Conditional Probability**: Calculates conditional probability using the formula `P(A|B) = P(A and B) / P(B)`.
   - **Random Variable Probability**: Calculates the probability using the provided distribution.

4. **Result Output**: After performing the calculation, the result is displayed to the user in a formatted manner.

---

## **Design Details**

### **1. Main Function**

The main function handles the interaction between the user and the program. It displays the main menu and invokes the appropriate functions based on user input. The flow of the program is as follows:
1. Display the main menu.
2. Accept the user’s choice.
3. Call the respective function for Simple Probability, Conditional Probability, or Random Variable Probability.
4. Handle errors or invalid inputs by providing error messages and prompting for re-entry of data.

### **2. Simple Probability Module**

This module is responsible for calculating simple probabilities. The steps followed are:

1. **Input**: The user is asked to enter the total number of elements and the favorable attempts for each element.
2. **Calculation**: The probability `P(A)` is calculated using the formula:
   
   \[
   P(A) = \frac{\text{favorable attempts}}{\text{total attempts}}
   \]

3. **Output**: The calculated probability is displayed.

Functions involved:
- **`getSimpleProbabilityData()`**: Gathers the data from the user (favorable attempts and total attempts).
- **`calculateSimpleProbability()`**: Performs the probability calculation.
- **`displaySimpleProbabilityData()`**: Displays the elements and their corresponding probabilities.

### **3. Conditional Probability Module**

This module is designed to calculate conditional probabilities. The steps are:

1. **Input**: The user is prompted to input `P(A)` and `P(B|A)` for a set of elements.
2. **Calculation**: The conditional probability is calculated using the formula:

   \[
   P(A|B) = \frac{P(A \cap B)}{P(B)}
   \]

3. **Output**: The result of the conditional probability is displayed.

Functions involved:
- **`getConditionalProbabilityData()`**: Gathers input values for `P(A)` and `P(B|A)`.
- **`calculateConditionalProbability()`**: Calculates the conditional probability.
- **`displayConditionalProbabilityData()`**: Displays the results.

### **4. Random Variable Probability Module**

This module handles calculations for random variables and their distributions.

1. **Input**: The user is asked to input the probability distribution for the random variable.
2. **Calculation**: The probability of a random variable `X` is computed based on the provided distribution.

Functions involved:
- **`getRandomVarProbabilityDistributionData()`**: Collects the probability distribution data for the random variable.
- **`calculateRandomVarProbability()`**: Computes the probability of the random variable.
- **`displayRandomVarProbabilityDistribution()`**: Displays the random variable distribution.

### **5. Utilities Module**

This module contains helper functions that are used throughout the program. Key functions include:
- **`printLine()`**: Prints a line of dashes for output formatting.
- **`validateProbability()`**: Validates if the probability entered by the user is within the range [0, 1].
- **`validateAttempt()`**: Ensures that the input attempt is a positive integer.

---

## **Error Handling**

The tool is designed to handle common errors gracefully:
- Invalid inputs (e.g., negative numbers, non-numeric values) are detected and the user is prompted to re-enter valid data.
- Calculation errors are caught and appropriate error messages are displayed.

---

## **Function Interaction**

Here’s a basic overview of how the functions interact with each other:

1. **Main function** invokes the appropriate functions from the probability modules.
2. **Input functions** (e.g., `getSimpleProbabilityData()`, `getConditionalProbabilityData()`) gather user input and validate it.
3. **Calculation functions** (e.g., `calculateSimpleProbability()`, `calculateConditionalProbability()`) perform the calculations based on the inputs.
4. **Display functions** (e.g., `displaySimpleProbabilityData()`, `displayConditionalProbabilityData()`) format and display the results to the user.
5. The **utility functions** (`validateProbability()`, `printLine()`) assist in input validation and output formatting.

---

## **Future Enhancements**

1. **Random Variable Module Development**: The random variable probability module can be expanded to handle more complex probability distributions and calculations.
2. **Advanced Error Handling**: Further validation and error messages can be added for edge cases like division by zero.
3. **Graphical Interface**: A future version of the tool could include a GUI for easier interaction.

---

## **Conclusion**

This design document outlines the structure and flow of the **Probability Calculator CLI Tool**. By separating the tool into distinct modules, the system is easily maintainable, and users can calculate various types of probabilities in a straightforward manner.
