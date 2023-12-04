/* Calculator -
 * Jake Gendreau
 * Section 01
 * Started 9/1/23 @ 10:35 AM
 * Completed 9/1/23 @ 10:51 PM
 */

#include <iostream>
#include <limits>
using namespace std;

int main(){

    //Define Vars
    double num1;
    double num2;
    int action;

    //Get input
    cout << "Welcome to the calculator. Begin by inputting your first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the operation you want to perform: \n1) Add\n2) Subtract\n3) Multiply\n4) Divide\n5) Modulo\n6) Compare\nOperation to perform: ";
    cin >> action;
    
    //Sanitize input
    while(action != 1 && action != 2 && action != 3 && action != 4 && action != 5 && action != 6){
        cout << "Invalid input. Try again: ";
        cin >> action;
    }

    //Add
    if(action == 1)
        cout << "Result: " << num1+num2 << endl;
    //Subtract
    else if (action == 2)
        cout << "Result: " << num1-num2 << endl;
    //Multiply
    else if (action == 3)
        cout << "Result: " << num1*num2 << endl;
    //Divide
    else if (action == 4)
        //Print error code if dividing by zero
        if(num2 != 0)
            cout << "Result: " << num1/num2 << endl;
        else
            cout << "Error: Divide by zero\n";
    //Modulo
    else if (action == 5)
        cout << "Result: " << (int)num1%(int)num2 << endl;
    //Compare
    else if (action == 6){
        cout << "Result: ";
        if(num1 > num2)
            cout << num1 << " > " << num2 << endl;
        else if(num1 < num2)
            cout << num1 << " < " << num2 << endl;
        else
            cout << num1 << " = " << num2 << endl;
    }
}