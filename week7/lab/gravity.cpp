/* Lab 6
* 10/3/23
* Gravity lab
*/

using namespace std;

#include <iostream>
#include <limits>
#include <cmath>

void badInput();
double findTime(double, double);
double findVelocity(double, double);

int main(){
    int choice;
    double height;

    //Prompt user and get input
    cout << "Select your operation:\n1) Test height\n2) Exit program" << endl;

    while (cout << "> " && !(cin >> choice) || choice < 0 || choice > 2){
        badInput();
    }

    //Exit
    if(choice == 2){
        exit(1);
    }

    while (cout << "Height (meters): " && !(cin >> height)){
        badInput();
    }

    //Define vars
    string name[5] = {"Earth", "Mars", "The Moon", "The Sun", "Jupiter"};
    double gravity[5] = {9.81, 3.71, 1.62, 274, 24.79};

    //output
    for(int i=0; i<5; i++){
        //Calculate
        double time = findTime(height, gravity[i]);
        double velocity = findVelocity(time, gravity[i]);

        cout << "On " << name[i] << ", the object will hit the ground in " << time << " seconds and will be going " << velocity << " m/s" << endl;
    }
    
}

double findTime(double height, double gravity){
    return sqrt((2* height) / gravity);
}

double findVelocity(double time, double gravity){
    return time * gravity;
}


void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}