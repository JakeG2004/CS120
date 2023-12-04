//Command line args

#include <iostream>
#include <string>


using namespace std;

int main(int argc, char* argv[]){

    //Store data
    double num1 = stod(argv[1]);
    double num2;
    char operation = argv[2][0];

    //Parse input
    if(argc != 4 && operation != 'a'){
        cout << "Invalid usage! Usage: num1 <operator> num2" << endl;
    }

    if(operation != 'a'){
        num2 = stod(argv[3]);
    }

    double result;

    //Since operator is stored as a char, we can use a switch. This is much faster and more readable than using strcmp()
    switch(operation){
        case 'a':
            result = abs(num1);
            break;
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case 'x':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            cout << "Invalid Sign" << endl;
            exit(1);
    }

    //Print result
    cout << "Result: " << result << endl;

}