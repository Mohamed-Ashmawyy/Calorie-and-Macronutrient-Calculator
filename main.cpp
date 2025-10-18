#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits
#include <vector> // Used for returning multiple values from a function

using namespace std;

void displayWelcomeMessage();
void getUserInfo(string &gender, int &age, double &height, double &weight);
double getValidNumber(const string &prompt);
double getActivityMultiplier();
double calculateBMR(const string &gender, int age, double height, double weight);
void calculateAndDisplayResults(double bmr, double activityMultiplier);
void calculateAndDisplayMacros(double weight);

// --- Main Program Execution ---
int main() {
    displayWelcomeMessage();

    // Variables to store user data
    string gender;
    int age;
    double height, weight;

    // 1. Get user information
    getUserInfo(gender, age, height, weight);

    // 2. Get activity level
    double activityMultiplier = getActivityMultiplier();

    // 3. Calculate Basal Metabolic Rate (BMR)
    double bmr = calculateBMR(gender, age, height, weight);
    if (bmr == 0) {
        // Exit if gender was invalid
        return 1;
    }

    // 4. Calculate and display final calorie results
    calculateAndDisplayResults(bmr, activityMultiplier);

    // 5. Calculate and display macronutrients
    calculateAndDisplayMacros(weight);

    return 0; // Program finished successfully
}

// --- Function Definitions ---


void displayWelcomeMessage() {
    cout << "--- Calorie and Macronutrient Calculator ---\n" << endl;
}

double getValidNumber(const string &prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a valid number: ";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
    }
    return value;
}


void getUserInfo(string &gender, int &age, double &height, double &weight) {
    cout << "Enter your gender (male/female): ";
    cin >> gender;

    // Simple validation for gender
    while (gender != "male" && gender != "female") {
        cout << "Invalid gender. Please enter 'male' or 'female': ";
        cin >> gender;
    }

    age = getValidNumber("Enter your age (years): ");
    height = getValidNumber("Enter your height (cm): ");
    weight = getValidNumber("Enter your weight (kg): ");
}

double getActivityMultiplier() {
    int choice;
    cout << "\n--- Select Your Activity Level ---\n";
    cout << "(1) Sedentary (no exercise)\n";
    cout << "(2) Lightly active (exercise 1-3 times/week)\n";
    cout << "(3) Moderately active (exercise 4-5 times/week)\n";
    cout << "(4) Very active (exercise 6-7 times/week)\n";
    cout << "(5) Extra active (intense daily exercise or physical job)\n";
    
    choice = getValidNumber("Your choice (1-5): ");

    switch (choice) {
        case 1: return 1.2;
        case 2: return 1.375;
        case 3: return 1.55;
        case 4: return 1.725;
        case 5: return 1.9;
        default:
            cout << "Invalid choice. Defaulting to Sedentary (1.2)." << endl;
            return 1.2;
    }
}

double calculateBMR(const string &gender, int age, double height, double weight) {
    if (gender == "male") {
        // Mifflin-St Jeor formula for men
        return (10 * weight) + (6.25 * height) - (5 * age) + 5;
    } else if (gender == "female") {
        // Mifflin-St Jeor formula for women
        return (10 * weight) + (6.25 * height) - (5 * age) - 161;
    } else {
        cout << "Error: Invalid gender for BMR calculation." << endl;
        return 0; // Return 0 to indicate an error
    }
}

/**
 * @brief Calculates and displays the calorie needs for maintenance, loss, and gain.
 */
void calculateAndDisplayResults(double bmr, double activityMultiplier) {
    double maintenanceCalories = bmr * activityMultiplier;
    
    cout << "\n--- Your Daily Calorie Needs ---\n";
    cout << "Maintenance: " << maintenanceCalories << " calories/day\n";
    cout << "Weight Loss (~0.5 kg/week): " << maintenanceCalories - 500 << " calories/day\n";
    cout << "Weight Gain (~0.5 kg/week): " << maintenanceCalories + 500 << " calories/day\n";
}

/**
 * @brief Calculates and displays macronutrients based on user-provided target calories.
 */
void calculateAndDisplayMacros(double weight) {
    cout << "\n--- Macronutrient Calculator ---\n";
    double targetCalories = getValidNumber("Enter your target daily calories: ");

    // A common macro split: 40% Carbs, 30% Protein, 30% Fat
    // 1g Protein = 4 calories, 1g Carb = 4 calories, 1g Fat = 9 calories
    double proteinGrams = (targetCalories * 0.30) / 4;
    double fatGrams = (targetCalories * 0.30) / 9;
    double carbGrams = (targetCalories * 0.40) / 4;

    cout << "\n--- Recommended Macros for " << targetCalories << " Calories ---\n";
    cout << "Protein: " << proteinGrams << " g\n";
    cout << "Fats: " << fatGrams << " g\n";
    cout << "Carbohydrates: " << carbGrams << " g\n";
}


