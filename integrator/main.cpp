//
//  main.cpp
//  integrator
//
//  Created by Tejas Patel on 6/21/22.
//
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
// End header inclusions
// Start Global Variables
long double lowerBound;
long double upperBound;
long double sum;
long double integral;
long double coefficient;
long double power;
int option;
int trigonometricOption;
long double input;
long double switch1;
long double switch2;
long double accuracy;
long double currentposition;
long double currentvalue;
long double total;
long double increment;
long double accuracyOption;
long double funcCoefficient;
long double e = 2.71828182845904523;
long double horizontalOffset;
string again;
string base;
long double logBase;
// End Global Variables
//Functions
void calculateIntegral(){
    /*List of options*/
    cout << "Option 1: Constant" << endl;
    cout << "Option 2: Linear Function" << endl;
    cout << "Option 3: Exponential Function" << endl;
    cout << "Option 4: Logarithmic Function" << endl;
    cout << "Option 5: Trigonometric Function/Reciprocal" << endl;
    cout << "Option 6: Inverse Trigonometric Function" << endl;
    cout << "After all others, absolute value functions will be added" << endl;
    cin >> option;
    /*Function for selected option 1*/
    if (option == 1){
        cin >> input;
        total = input * (upperBound - lowerBound);
        sum += total;
        cout << total << endl;
        total = 0;
    }
    /*End funtion for 1 and start function for 2*/
    if (option == 2){
        cout << "Slope: ";
        cin >> input;
        total = (((input * lowerBound) + (input * upperBound)) / 2.0) * (upperBound - lowerBound);
        sum += total;
        cout << total << endl;
        total = 0;
    }
    /*End function for 2 and start function for 3*/
    if (option == 3){
        cout << "Choose accuracy 1-100: ";
        cin >> accuracy;
        cout << "Coefficient: ";
        cin >> coefficient;
        accuracyOption = accuracy * 10.0;
        cout << "Exponent: ";
        cin >> power;
        increment = (upperBound - lowerBound) / accuracyOption;
        currentposition = lowerBound + ((upperBound - lowerBound) / (accuracyOption * 2));
        for (int i = 0; i < accuracyOption; i++){
            currentvalue = increment * pow(currentposition, power);
            total += currentvalue;
            currentposition += increment;
        }
        total *= coefficient;
        cout << setprecision(10) << total << endl;
        sum += total;
        total = 0;
        /*        cout << pow(lowerBound, power);*/
    }
    /* Option 4 function works but there are many more options to add so work is not done */
    if (option == 4){
        cout << "What is the coefficient of the function? ";
        cin >> funcCoefficient;
        cout << "What is the coefficient inside the brackets? ";
        cin >> coefficient;
        cout << "Choose Accuracy 1-100: ";
        cin >> accuracy;
        cout << "Logarithm Base:" << endl << "Is it a natural logarithm? (y/n): ";
        cin >> base;
        if (base == "y"){logBase = 2.71828182845904523;}
        else{
            cout << "Base: ";
            cin >> logBase;
        }
        accuracyOption = accuracy * 10.0;
        increment = ((upperBound - lowerBound) * coefficient) / accuracyOption;
        currentposition = (lowerBound * coefficient) + increment / 2;
        for (int i = 0; i < accuracyOption; i++){
            currentvalue = (log2(currentposition) / log2(logBase)) * increment;
            total += currentvalue;
            currentposition += increment;
        }
        total /= coefficient;
        total *= funcCoefficient;
        cout << setprecision(10) << total << endl;
        sum += total;
        total = 0;
    }
    if (option == 5){
        cout << "Option 1: Sine" << endl;
        cout << "Option 2: Cosine" << endl;
        cout << "Option 3: Tangent" << endl;
        cout << "Option 4: Cosecant" << endl;
        cout << "Option 5: Secant" << endl;
        cout << "Option 6: Cotangent" << endl;
        cout << "Option 7: Sine Squared" << endl;
        cout << "Option 8: Cosine Squared" << endl;
        cout << "Option 9: Tangent Squared" << endl;
        cout << "Option 10: Cosecant Squared" << endl;
        cout << "Option 11: Secant Squared" << endl;
        cout << "Option 12: Cotangent Squared" << endl;
        cout << "Your choice: ";
        cin >> trigonometricOption;
        cout << "What is the coefficient of the function? ";
        cin >> funcCoefficient;
        cout << "What is the coefficient inside the brackets? ";
        cin >> coefficient;
        cout << "Horizontal offset: ";
        cin >> horizontalOffset;
        accuracyOption = 100000000;
        increment = ((upperBound - lowerBound) * coefficient) / accuracyOption;
        currentposition = (lowerBound * coefficient) + increment / 2;
        
        if (trigonometricOption == 1){
            for (int i = 0; i < accuracyOption; i++){
                currentvalue = (sin(currentposition)) * increment;
                total += currentvalue;
                currentposition += increment;
            }
        }
        if (trigonometricOption == 2){
            for (int i = 0; i < accuracyOption; i++){
                currentvalue = (cos(currentposition)) * increment;
                total += currentvalue;
                currentposition += increment;
            }
        }
        if (trigonometricOption == 3){
            currentvalue = ((((-1 * funcCoefficient / coefficient) * (log2(cos(coefficient * upperBound + horizontalOffset)) / log2(e)))) - (((-1 * funcCoefficient / coefficient) * (log2(cos(coefficient * lowerBound + horizontalOffset)) / log2(e)))));
            sum += currentvalue;
            cout << setprecision(10) << currentvalue;
        }
        if (trigonometricOption == 4){
            currentvalue = (-1 * funcCoefficient / coefficient) * (((log2(cos(0.5 * (coefficient * upperBound + horizontalOffset))) / log2(e)) - (log2(sin(0.5 * (coefficient * upperBound + horizontalOffset))) / log2(e))) - ((log2(cos(0.5 * (coefficient * lowerBound + horizontalOffset))) / log2(e)) - (log2(sin(0.5 * (coefficient * lowerBound + horizontalOffset))) / log2(e))));
            cout << setprecision(10) << currentvalue;
        }
            
            /*for (int i = 0; i < accuracyOption; i++){
             currentvalue = (sin(currentposition)) * increment;
             total += currentvalue;
             currentposition += increment;
             }*/
            
            
            total /= coefficient;
            total *= funcCoefficient;
            cout << setprecision(10) << total << endl;
            sum += total;
            total = 0;
        }
        cout << "Again? ";
        cin >> again;
    }
    // Main Function
int main(){
    cout << "Lower bound: "; cin >> lowerBound;
    cout << "Upper bound: "; cin >> upperBound;
    if (upperBound < lowerBound){
        switch1 = lowerBound;
        switch2 = upperBound;
        upperBound = switch1;
        lowerBound = switch2;
    }
    do{
        calculateIntegral();
    } while ((again == "yes") || (again == "Yes") || (again == "YES") || (again == "Y") || (again == "y"));
    cout << "The total of the integral for the equation you provided is " << sum << endl;
    return 0;
}

