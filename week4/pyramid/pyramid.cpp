/* Pyramid program
 * Jake Gendreau
 * Section 1
 * 
 * I am doing this on 9/6 and I'm predicting it will be next
 * It would be really ccool if I was right
 * 
 * Started 9/6 11:-- AM
 * Finished 9/6 11:14 AM (what i suspect to be the assignment)
*/

#include <iostream>
using namespace std;

int main(){

    //Init Vars
    int layers;
    int blocks = 1;

    //Get user input
    cout << "Enter the number of layers (1-4): ";
    cin >> layers;

    //Place boundaries on input
    while(layers < 1 || layers > 4){
        cout  << "Incorrect input. Enter 1-4: ";
        cin >> layers;
    }

    //For every row
    for(int i=0; i<(layers); i++){

        //print spaces then blocks then end line
        cout << string(layers - i - 1, ' ') << string(blocks, '#') << endl;
        
        //increment
        blocks += 2;
    }
}