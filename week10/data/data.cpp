/* Data program using CSV
* Made by Jake Gendreau
* Completed 10/20 @ 5:55 PM
* Week 10 assignment
*/

#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

class rowData{
    public:
        string name;
        string species;
        string gender;
        string personality;
        string hobby;
        string birthday;
        string catchphrase;
        string favorite_song;
        string style1;
        string style2;
        string color1;
        string color2;
        string wallpaper;
        string flooring;
        string furniture_list;
        string filename;
        string id;
        void print();
        void speak();
};

void badInput();
string toUpper(string);

int main(int argc, char* argv[]){

    if(argc != 2){
        cout << "Improper usage! use ./data.cpp <filename.csv>" << endl;
        exit(1);
    }
    
    int choice;
    int rows = 0;
    string word;
    string line;

    ifstream infile;

    //oooh command line arguments
    infile.open(argv[1]);

    //Check if file doesn't exist
    if(!(infile)){
        cout << "Couldn't open file " << argv[1] << endl;
        exit(1);
    }

    //Calculate rows
    while(getline(infile, line)){
        rows++;
    }

    //Create array
    rowData data[rows];

    //Reset getline position
    infile.clear();
    infile.seekg(0, ios_base::beg);

    //Load data into array
    for(int i=0; i<rows; i++){
        getline(infile, data[i].name, ',');
        getline(infile, data[i].species, ',');
        getline(infile, data[i].gender, ',');
        getline(infile, data[i].personality, ',');
        getline(infile, data[i].hobby, ',');
        getline(infile, data[i].birthday, ',');
        getline(infile, data[i].catchphrase, ',');
        getline(infile, data[i].favorite_song, ',');
        getline(infile, data[i].style1, ',');
        getline(infile, data[i].style2, ',');
        getline(infile, data[i].color1, ',');
        getline(infile, data[i].color2, ',');
        getline(infile, data[i].wallpaper, ',');
        getline(infile, data[i].flooring, ',');
        getline(infile, data[i].furniture_list, ',');
        getline(infile, data[i].filename, ',');
        getline(infile, data[i].id, '\n');
    }
    
    cout << "NOTE: I wanted to use a reduced size dataset for testing, so the filename is loaded through command-line arguments." << endl;
    cout << "This program was created by Jake Gendreau" << endl << endl;
    
    //Main loop
    do{
        //Menu
        cout << "\nWhat would you like to learn about?\n"
        << "1) An individual\n"
        << "2) A species\n"
        << "3) Individuals who like a particular color\n"
        << "4) Quit\n";

        //Clean input
        while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 4){
            badInput();
        }

        //Flag
        bool success;
        switch(choice){

            //Search name
            case 1:
                success = false;
                while(cout << "Name of individual: " && !(cin >> word)){
                    badInput();
                }

                //Search array
                for(int i=0; i<rows; i++){
                    if(toUpper(data[i].name) == toUpper(word)){
                        data[i].print();
                        data[i].speak();
                        success = true;
                    }
                }

                //Fail
                if(!success){
                    cout << "No animal by name " << word << endl;
                }

                break;

            //Search species
            case 2:
                success = false;
                while(cout << "Name of species: " && !(cin >> word)){
                    badInput();
                }

                //Search array
                for(int i=0; i<rows; i++){
                    if(toUpper(data[i].species) == toUpper(word)){
                        data[i].print();
                        success = true;
                    }
                }

                //Fail
                if(!success){
                    cout << "No animal with species " << word << " found" << endl;
                }

                break;

            //Search color
            case 3:
                success = false;
                while(cout << "Name of color: " && !(cin >> word)){
                    badInput();
                }

                //Search array
                for(int i=0; i<rows; i++){
                    if((toUpper(data[i].color1) == toUpper(word)) || (toUpper(data[i].color2) == toUpper(word))){
                        data[i].print();
                        success = true;
                    }
                }

                //Fail
                if(!success){
                    cout << "No animal with favorite color " << word << " found" << endl;
                }
                break;
        }
    } while (choice != 4);
}

void rowData::print(){
    cout << name << " is a " << personality <<" " << species << " who likes " << hobby << endl;
}

void rowData::speak(){
    cout << name << " says \"" << catchphrase << "\"" << endl;
}

string toUpper(string word){
    //Make all letters uppercase
    for(int i=0; i<(word.length()); i++){
        if(word[i] >= 97)
            word[i] -= 32;
    }
    return word;
}

void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}
