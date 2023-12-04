/*
* review program
* Jake Gendreau
* Sep 29 2023
* hash printer DONE
* pos, neg, or zero test DONE
* prime test DONE
* count to x by y DONE
* multiplication table DONE
*/

using namespace std;

//Libraries
#include <iostream>
#include <limits>
#include <cmath>

//Prototypes
void badInput();
void printHash();
void testValue();
void testPrime();
void countXY();
void multTable();

int main(){
    int choice;

    do {
        cout << "\nWelcome to the REVIEWINATOR. Choose your operation.\n\n"
        << "1) Print N hashes\n"
        << "2) Determine whether a value is positive, negative, or zero\n"
        << "3) Test if a number is prime\n"
        << "4) Count to X by Ys\n"
        << "5) Make a multiplication table\n"
        << "6) Exit program" << endl;

        while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 6){
            badInput();
        }

        switch(choice){
            case 1:
                printHash();
                break;

            case 2:
                testValue();
                break;

            case 3:
                testPrime();
                break;

            case 4:
                countXY();
                break;

            case 5:
                multTable();
                break;

        }
    } while(choice != 6);
}

void printHash(){
    int hashes = 0;

    while(cout << "Hashes:  " && !(cin >> hashes) || hashes < 0){
            badInput();
    }

    cout << string(hashes, '*') << endl;
}

void testValue(){
    int value = 0;

    while(cout << "Value: " && !(cin >> value)){
            badInput();
    }

    if(value < 0){
        cout << value << " is negative" << endl;
    } else if(value == 0){
        cout << value << " is 0" << endl;
    } else {
        cout << value << " is positive" << endl;
    }
}

void testPrime(){
    int num = 0;

    while(cout << "Number to test: " && !(cin >> num)){
            badInput();
    }

    if(num == 1 || num == 2){
        cout << num << " is prime" << endl;
        return;
    }

    for(int i = 1; i < num / 2; i++){
        if((num % i) == 0){
            cout << num << " is not prime" << endl;
            return;
        }
    }

    cout << num << " is prime" << endl;
}

void countXY(){
    int goal = 0;
    int increment = 0;

    while((cout << "Goal number: " && !(cin >> goal)) || (cout << "Increment: " && !(cin >> increment))){
            badInput();
    }

    if(goal <  0 && increment > 0 || goal > 0 && increment < 0){
        increment *= -1;
    }

    if(goal >= 0){
        for(int i = 0; i <= goal; i += increment){
            cout << i  << endl;
        }
    } else {
        for(int i = 0; i >= goal; i += increment){
            cout << i << endl;
        }
    }

}

void multTable(){
    int x;
    int y;

    while((cout << "X: " && !(cin >> x)) || (cout << "Y: " && !(cin >> y))){
            badInput();
    }

    cout << "\t";

    for(int i=1; i<=y; i++){
        cout << i << "\t";
    }

    cout << endl << endl;;

    for(int i=1; i<=x; i++){
        cout << i << "\t";
        for (int j=1; j<=y; j++){
            cout << j * i << "\t";
        }
        cout << endl;
    }
}

void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}