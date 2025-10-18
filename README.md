# C++ Calorie Calculator

A simple, console-based application written in C++ to calculate daily calorie and macronutrient needs based on user input.

## Description

This project provides a straightforward way for users to estimate their daily caloric intake for weight maintenance, loss, or gain. It uses the well-regarded **Mifflin-St Jeor equation** to calculate Basal Metabolic Rate (BMR) and then adjusts it based on the user's activity level to find their Total Daily Energy Expenditure (TDEE).

The application also includes a macronutrient calculator to provide a recommended breakdown of protein, fats, and carbohydrates for a given calorie target.

## Features

-   **Gender-Specific Formulas**: Uses the correct Mifflin-St Jeor equation for both males and females.
-   **Activity Level Adjustment**: Accounts for five different levels of physical activity, from sedentary to extra active.
-   **Clear Calorie Goals**: Displays clear estimates for:
    -   Weight Maintenance
    -   Weight Loss (a 500-calorie deficit)
    -   Weight Gain (a 500-calorie surplus)
-   **Macronutrient Calculation**: Calculates a balanced macro split (Protein, Fats, Carbs) based on a user-defined calorie goal.
-   **Input Validation**: Basic checks to prevent crashes from non-numeric input.

## How to Compile and Run

To use this program, you need a C++ compiler (like g++ or any c++ online compiler).

1.  **Clone the repository or download the source code.**

2.  **Open your terminal or command prompt.**

3.  **Navigate to the directory containing the `main.cpp` file.**

4.  **Compile the code using g++:**
    ```sh
    g++ main.cpp -o calorie_calculator
    ```

5.  **Run the executable:**
    ```sh
    ./calorie_calculator
    ```

The program will then prompt you to enter your information.

## Formulas Used

-   **Basal Metabolic Rate (BMR)**: Calculated using the Mifflin-St Jeor Equation.
    -   For Men: `BMR = 10W + 6.25H - 5A + 5`
    -   For Women: `BMR = 10W + 6.25H - 5A - 161`
    *(Where W = weight in kg, H = height in cm, A = age in years)*

-   **Total Daily Energy Expenditure (TDEE)**: `TDEE = BMR × Activity Multiplier`

---
*This project created for educational purposes and my passion*
