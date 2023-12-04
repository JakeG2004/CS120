/*
Jake Gendreau
Assignment 11? I think?
Map assignment
I added a terrain smoothing function so that it generates realistic terrain
The smoothing is more apparent on larger scales
*/

#include <iostream>
#include <limits>

using namespace std;

const int SIZEY = 70;
const int SIZEX = 70;

class cell{
    public:
        string animal;
        string terrain;
        int altitude;
        void printColor();
        void printAscii();
        void printAnimal();

        //Constructor
        cell(){
            switch(rand()%3){
            case 0:
                terrain = "water";
                break;
            case 1:
                terrain = "prarie";
                break;
            case 2:
                terrain = "mountain";
                break;
            }
        }
};

cell map[SIZEX][SIZEY];

void fillMap();
void fillData();
void badInput();
void makeIslands();
void findAltitude();
string findTerrain(int, int);

int main(int argc, char* argv[]){

    srand(time(0));

    //Determine the correct amount of smoothing given the minimum dimention
    int SMOOTHING = SIZEY;
    if(SIZEX < SIZEY){
        SMOOTHING = SIZEX;
    }

    int choice;

    //Smooth terrain
    for(int i =0; i<SMOOTHING; i++){
        makeIslands();
        fillMap();
    }

    fillData();

    do{
        //Menu
        cout << "Welcome to the grand map. Choose what you would like to do\n"
        << "1) View Map (color)\n"
        << "2) View Map (ascii)\n"
        << "3) View Animals\n"
        << "4) Find Altitude\n"
        << "5) Exit Program\n";

        while(cout << "> " && !(cin >> choice) || choice < 1 || choice > 5){
            badInput();
        }

        switch(choice){
            case 1:
                //For each cell, run printColor
                for(int y=0; y<SIZEY; y++){
                    for(int x=0; x<SIZEX; x++){
                        map[x][y].printColor();
                    }
                    cout << "\033[0m" << endl;
                }
                break;

            case 2:
                cout << "KEY:\n. = Water, # = Prarie, ^ = Mountain" << endl;
                //For each cell, run printAscii
                for(int y=0; y<SIZEY; y++){
                    for(int x=0; x<SIZEX; x++){
                        map[x][y].printAscii();
                    }
                    cout << endl;
                }
                break;

            case 3:
                cout << "KEY:\nP = Prarie Dog, F = Ferret, K = Kingsnake, M = Mountain Goat, E = Eagle, B = Brown Bear" << endl;
                //For each cell, run printAscii
                for(int y=0; y<SIZEY; y++){
                    for(int x=0; x<SIZEX; x++){
                        map[x][y].printAnimal();
                    }
                    cout << endl;
                }
                break;

            case 4:
                findAltitude();
                break;

            }
        
    }while (choice != 5);
}

void fillData(){
    int randInt;
    //Iterate through array
    for(int y=0;y<SIZEY;y++){
        for(int x=0;x<SIZEX;x++){
            //Set animals to be random
            randInt = rand()%3;
            if(map[x][y].terrain == "prarie"){
                switch(randInt){
                    case 0:
                        map[x][y].animal = "Prarie Dog";
                        break;
                    case 1:
                        map[x][y].animal = "Ferret";
                        break;
                    case 2:
                        map[x][y].animal = "Kingsnake";
                        break;
                }

                //Set altitude
                map[x][y].altitude = rand()%1500 + 20;

            } else if(map[x][y].terrain == "mountain"){
                switch(randInt){
                    case 0:
                        map[x][y].animal = "Mountain Goat";
                        break;
                    case 1:
                        map[x][y].animal = "Eagle";
                        break;
                    case 2:
                        map[x][y].animal = "Brown Bear";
                        break;
                }

                map[x][y].altitude = rand()%1500 + 1501;
            } else {
                //Water
                map[x][y].altitude = 0;
                map[x][y].animal = "None";
            }
                
        }
    }
}

void makeIslands(){

    //Set num of islands based on smaller dimention
    int ISLAND_NUM = SIZEY;
    if(SIZEX < SIZEY){
        ISLAND_NUM = SIZEX;
    }
    //Make n islands to break up blocks of terrain
    for(int i=0; i<ISLAND_NUM; i++){
        //Ensure islands fit in grid
        int xpos = rand()%SIZEX;
        if(xpos = 0)
            xpos = 1;
        if(xpos = SIZEX)
            xpos = SIZEX-1;

        int ypos = rand()%SIZEY;
        if(ypos = 0)
            ypos = 1;
        if(ypos = SIZEY)
            ypos = SIZEY-1;
        string type;
        
        //Define type
        switch(rand()%3){
            case 0:
                type = "prarie";
                break;
            case 1:
                type = "water";
                break;
            case 2:
                type = "mountain";
                break;
        }
        //Make island
        for(int y=ypos-1;y<ypos+1;y++){
            for(int x =xpos-1; x<xpos+1; x++){
                map[x][y].terrain = type;
            }
        }
    }
}

void fillMap(){
    string buffer[SIZEX][SIZEY];
    for(int y=0;y<SIZEY;y++){
        for(int x=0;x<SIZEX;x++){
            //Write to buffer
                //Fill upper right
                buffer[x][y] = findTerrain(x,y);
                //Fill bottom left
                buffer[SIZEX - x - 1][SIZEY - y - 1] = findTerrain(SIZEX - x - 1,SIZEY - y - 1);
        }
    }

    //Write back to map
    for(int y=0; y<SIZEY;y++){
        for(int x=0;x<SIZEX;x++){
            map[x][y].terrain = buffer[x][y];
        }
    }
}

void findAltitude(){
    int xpos;
    int ypos;

    cout << "Origin is (1,1) in the bottom left corner" << endl;
    while(cout << "Enter X coordinate of desired terrain (1-" << SIZEX << "): " && !(cin >> xpos) || xpos < 1 || xpos > SIZEX){
        badInput;
    }

    while(cout << "Enter Y coordinate of desired terrain (1-" << SIZEY << "): " && !(cin >> ypos) || ypos < 1 || ypos > SIZEY){
        badInput;
    }

    cout << "\nAltitude is " << map[xpos - 1][SIZEY - ypos].altitude << " feet" << endl;
}

// I call this bad boy the jakenoise function
// It takes the random array of terrain and smoothes it to create more realistic looking regions of terrain
string findTerrain(int x2, int y2){
    int arrSize = 0;

    string bias[9] = {};

    for(int x=x2-1; x<x2+1; x++){
        for(int y=y2-1; y<y2+1; y++){

            //Make sure it's in bounds
            if(y < 0)
                y = 0;
            if(y > SIZEY)
                y = SIZEY;

            if(x < 0)
                x = 0;
            if(x > SIZEX)
                x = SIZEX;

            //Fill bias array value with surrounding terrain
            bias[arrSize] = map[x][y].terrain;
            arrSize++;
        }
    }

    //Select from bias array
    return bias[rand()%arrSize];
}

void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}

void cell::printColor(){
    if(terrain == "water")
        cout << "\033[44m ";
    if(terrain == "prarie")
        cout << "\033[42m ";
    if(terrain == "mountain")
        cout << "\033[47m ";

    cout << " ";
}

void cell::printAscii(){
    if(terrain == "water")
        cout << ". ";
    if(terrain == "prarie")
        cout << "= ";
    if(terrain == "mountain")
        cout << "Ʌ ";
}

void cell::printAnimal(){
    if(animal != "None"){
        cout << animal[0] << " ";
    } else {
        cout << "  ";
    }
}

