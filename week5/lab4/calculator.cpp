/* A simple calculator program,
controlled by a menu and
divided into separate functions */

/* Jake Gendreau
* Lab 4?
* Did all tasks
*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double,double);
double cylinderArea(double, double);
double cylinderVolume(double, double);
double cone(double, double);

double pi = 3.14;
//-------------- Main -------------------
int main()
{
    double operand1, operand2, answer;
    int choice, valid_choice;
    string symbol;
    string shape;
    do{
        print_menu();
        cin >> choice;
        valid_choice = 1; // assume choice is valid
        switch(choice){
            case 0: // program will exit
                break;
            case 1: // addition
                operand1 = get_value();
                operand2 = get_value();
                answer = operand1 + operand2;
                symbol = "+";
                break;
            case 2: // division
                operand1 = get_value();
                operand2 = get_value();
                answer = divide(operand1,operand2);
                symbol = "/";
                break;
            case 3: //subtraction
                operand1 = get_value();
                operand2 = get_value();
                answer = operand1 - operand2;
                symbol = "-";
                break;
            case 4: //Surface area of cylinder
                cout << "Radius ";
                operand1 = get_value();
                cout << "Height ";
                operand2 = get_value();
                answer = cylinderArea(operand1, operand2);
                symbol = "area";
                shape = "cylinder";
                break;
            case 5: //Surface area of cylinder
                cout << "Radius ";
                operand1 = get_value();
                cout << "Height ";
                operand2 = get_value();
                answer = cylinderVolume(operand1, operand2);
                symbol = "volume";
                shape = "cylinder";
                break;

            case 6: //Surface area of cone
                cout << "Radius ";
                operand1 = get_value();
                cout << "Height ";
                operand2 = get_value();
                answer = cone(operand1, operand2);
                symbol = "area";
                shape = "cone";
                break;

            default:
                valid_choice = 0; // choice is invalid
                cout << "Invalid Choice." << endl;
    }
    //Standard equation
    if(valid_choice && choice < 4 ){ // if choice is valid, print the answer
        printf("\n %g %s %g = %g\n\n", operand1, symbol.c_str(), operand2, answer);
    //More complicated
    } else if(valid_choice && choice > 3){
        printf("%s with radius %g and height %g = %s %g\n", shape.c_str(), operand1, operand2, symbol.c_str(), answer);
    }
    }while(choice != 0); // if not 0, loop back to start
        return 0;
}
//-------------- Functions -------------------
double divide(double dividend, double divisor){
    if(divisor == 0){
        cout << "Divide by zero error\n";
        return 0; // avoids divide by zero errors
    }
    else
    return (dividend/divisor);
}

double cylinderArea(double radius, double height){
    return ((2*pi*radius*height) + (2*pi*radius*radius));
}

double cylinderVolume(double radius, double height){
    return (height * (pi*radius*radius));
}

double cone(double radius, double height){
    return (pi*radius*(radius+sqrt((height * height) + (radius * radius))));
}
//----------------- get_value function ----------------
double get_value(){
    double temp_value;
    cout << "Value: ";
    cin >> temp_value;
    cout << "Thanks." << endl;
    return temp_value;
}
//-------------------- print_menu function -------------
void print_menu(){
    cout << endl;
    cout << "Add (1)" << endl;
    cout << "Divide (2)" << endl;
    cout << "Subtract (3)" << endl;
    cout << "Cylinder Area (4)" << endl;
    cout << "Cylinder Volume (5)" << endl;
    cout << "Right Circular Cone (6)" << endl;
    cout << "Exit (0)" << endl;
    cout << "Enter your choice: ";
}