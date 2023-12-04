/* Pet program
* Secion 1
* Jake Gendreau
* 10/9/23
*/

#include <iostream>
#include <limits>
using namespace std;

void badInput();

class pet{
    public:
        string species;
        int hunger;//0-100, 100 is starving
        int health; //0-100, 100 is max
        int happiness; //0-100, 100 is max
        string name;
        void print(); // prototype
        void play();
        void feed();
        pet(); // constructor, same name as the class
};

int main(){
    srand(time(0));
    int choice;
    cout << "Welcome to The pet program" << endl;
    pet pet;
    do{
        cout << "What would you like to do with your pet?\n"
            << "1) Play\n"
            << "2) Feed\n"
            << "3) Display information\n"
            << "4) Exit program\n";
        while(cout << "> " && !(cin >> choice) || choice < 0 || choice > 4){
            badInput();
        }

        switch(choice){
            case 1:
                pet.play();
                break;
            case 2:
                pet.feed();
                break;
            case 3:
                pet.print();
                break;
        }
    }while (choice != 4);
}

void pet::print(){
    printf("Species: %s\nHunger: %i\nHappiness: %i\nHealth: %i\nName: %s\n\n", species.c_str(), hunger, happiness, health, name.c_str());
}

void pet::play(){
    int addHappy = rand()%10;
    cout << "You play with your pet! +" << addHappy << " happiness. -" << addHappy << " happy. +" << addHappy << " hunger." << endl;

    happiness += addHappy;
    if(happiness >= 100)
        happiness = 100;

    health -= addHappy;
    if(health <= 0){
        health = 0;
        cout << "Your pet has died from a lack of health." << endl;
        exit(1);
    }

    hunger += addHappy;
    if(hunger >= 100){
        hunger = 100;
        cout << "Your pet had died from a lack of feeding." << endl;
        exit(1);
    }
}

void pet::feed(){
    int addHealth = rand()%10;
    cout << "You feed your pet! +" << addHealth << " health. -" << addHealth << " happiness. -" << addHealth << " hunger." << endl;

    hunger -= addHealth;
    if(hunger <= 0)
        hunger = 0;

    health += addHealth;
    if(health >= 100)
        health = 100;

    happiness -= addHealth;
    if(happiness <= 0){
        health = 0;
        cout << "Your pet has died from a lack of happiness" << endl;
        exit(1);
    }
}

pet::pet(){
    //Vars
    int MAX_PETS = 5;
    int choice;
    string speciesTypes[MAX_PETS] = {"Zombie", "Cat", "Lizard", "Skeleton", "Slimeball"};

    //Get input
    cout << "Generating a new pet..." << endl;
    cout << "Enter a species" << endl;
    for(int i=0; i<MAX_PETS; i++){
        cout << i << ") " << speciesTypes[i] << endl;
    }
    while(cout << "> " && !(cin >> choice) || choice < 0 || choice > MAX_PETS){
        badInput();
    }

    //Define pet
    hunger = rand()%100 + 1;
    species = speciesTypes[choice];
    health = rand()%100 + 1;
    happiness = rand()%100 + 1;

    //Get name
    do{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter name (must not be empty): ";
        getline(cin, name);
    }while (name == "");
}

void badInput(){
    cin.clear(); //clear bad input flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
    cout << "Invalid input; please re-enter.\n";
}