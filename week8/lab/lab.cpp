/*Lab 7
* Jake Gendreau
10/10/23
*/

using namespace std;

#include <iostream>
#include <limits>

void sort(string[3]);

int main(){
    string first = "", middle = "", last = "";
    string fullName = "", schoolName = "", alphabetical = "";

    //Get input
    do {
        cout << "Enter your first name: ";
        getline(cin, first);
    }while(first == "");
    

    cout << "Enter your middle name: ";
    getline(cin, middle);

    do {
        cout << "Enter your last name: ";
        getline(cin, last);
    }while(last == "");

    //Clean names
    string nameChar[3];
    nameChar[0] = first;
    nameChar[1] = middle;
    nameChar[2] = last;

    for(int i=0; i<3; i++){
        if(nameChar[i][0] >= 97){
            nameChar[i][0] -= 32;
        }
    }

    //First middle last
    if(middle != "")
        fullName = first + " " + middle + " " + last;
    else
        fullName = first + " " + last;

    cout << "Full name is: " << fullName << endl;

    //last, first, middle
    if(middle != "")
        schoolName = last + ", " + first + " " + middle;
    else
        schoolName = last + ", " + first;

    cout << "School name is: " << schoolName << endl;

    //Alphabetical
    sort(nameChar);

    for(int i=0; i<3; i++){
        alphabetical += nameChar[i] + " ";
    }
    cout << "Alphabetical: " << alphabetical << endl;

}

//bubble sort
//Yes i know this is stupid but I Wanted to practice sorting
void sort(string nameChar[3]){
    string tmp;
    int swaps = 0;
    for(int i=0; i<2; i++){
        if(nameChar[i][0] > nameChar[i+1][0]){
            tmp = nameChar[i];
            nameChar[i] = nameChar[i+1];
            nameChar[i+1] = tmp;
            swaps++;
        }
    }
    if(swaps != 0)
        sort(nameChar);
}