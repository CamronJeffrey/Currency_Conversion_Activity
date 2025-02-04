// Currency_Conversion_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function declarations
void convertCurrency(double amount, double rate);
void adjustRateTemporarily(double& rate, double adjustment);

int main() {
    // Conversion rates (USD to others)
    const double USD_TO_EUR = 0.85;
    const double USD_TO_GBP = 0.75;
    const double USD_TO_JPY = 110.0;

    // Non-const pointers to allow const_cast
    double* rateEUR = const_cast<double*>(&USD_TO_EUR);
    double* rateGBP = const_cast<double*>(&USD_TO_GBP);
    double* rateJPY = const_cast<double*>(&USD_TO_JPY);

    // Temporary promotion adjustment
    adjustRateTemporarily(*rateEUR, 0.05);  // Increase EUR rate for promotion

    // User interaction
    double amount;
    string fromCurrency, toCurrency;

    cout << "Welcome to the Currency Converter!" << endl;
    cout << "Enter amount to convert: ";
    cin >> amount;
    cout << "Enter the currency you are converting from (USD, EUR, GBP, JPY): ";
    cin >> fromCurrency;
    cout << "Enter the currency you are converting to (USD, EUR, GBP, JPY): ";
    cin >> toCurrency;

    // Perform conversion based on user input
    if (fromCurrency == "USD" && toCurrency == "EUR") {
        convertCurrency(amount, *rateEUR);
    }
    else if (fromCurrency == "USD" && toCurrency == "GBP") {
        convertCurrency(amount, *rateGBP);
    }
    else if (fromCurrency == "USD" && toCurrency == "JPY") {
        convertCurrency(amount, *rateJPY);
    }
    else {
        cout << "Invalid currency conversion option." << endl;
    }

    return 0;
}

void convertCurrency(double amount, double rate) {
    cout << fixed << setprecision(2);
    cout << "Converted amount: " << amount * rate << endl;
}

void adjustRateTemporarily(double& rate, double adjustment) {
    rate += adjustment;
    cout << "Promotional rate applied! New rate: " << rate << endl;
}

