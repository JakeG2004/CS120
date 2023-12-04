/* Calculator -
 * Jake Gendreau
 * Section 01
 * Lab 3
 * Added input sanitization
 * Added sum feature
 */

#include <iostream>
#include <limits>
using namespace std;

//Prototypes
void badInput();

int main(){

    //Define Vars
    double num1;
    double num2;
    int action;
    int sum = 0;
    char goagain;

    //Get numbers
    while (cout << "Enter number 1: " && !(cin >> num1) || cout << "Enter number 2: " && !(cin >> num2)) {
        badInput();
    }
    
    //Select operation
    while (cout << "Enter the operation you want to perform: \n1) Add\n2) Subtract\n3) Multiply\n4) Divide\n5) Modulo\n6) Compare\n7) Sum\nOperation to perform: "  && !(cin >> action) || action < 0 || action > 7){
        badInput();
    }
    
    switch (action) {

    case 1: //Addition
        cout << "Result: " << num1 + num2 << endl;
        break;

    case 2: //Subtraction
        cout << "Result: " << num1 - num2 << endl;
        break;

    case 3: //Multiplication
        cout << "Result: " << num1 * num2 << endl;
        break;

    case 4: //Division
        if (num2 != 0)
            cout << "Result: " << num1 / num2 << endl;
        else
            cout << "Error: Divide by zero\n";
        break;

    case 5: //Modulo
        cout << "Result: " << (int)num1 % (int)num2 << endl;
        break;

    case 6: //Compare
        cout << "Result: ";
        if (num1 > num2)
            cout << num1 << " > " << num2 << endl;
        else if (num1 < num2)
            cout << num1 << " < " << num2 << endl;
        else
            cout << num1 << " = " << num2 << endl;
        break;

    case 7: //Sum
        int sum = 0;
        for (int i = num1; i <= num2; i++) {
            sum += i;
        }
        cout << "Result: " << sum << endl;
        break;
    }

    //Go again?
    cout << "Would you like to calculate another number? (y/n): ";
    cin >> goagain;

    if(goagain == 'y'){
        main();
    }
}

void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}