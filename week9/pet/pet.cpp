/* Pet program
* Secion 1
* Jake Gendreau
* 10/9/23
*/

#include <iostream>
#include <limits>
#include <string>
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
        void trick();
        void event();
        void checkHealth();
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
            << "3) Do a trick\n"
            << "4) Display information\n"
            << "5) Exit program\n";
        while(cout << "> " && !(cin >> choice) || choice < 0 || choice > 5){
            badInput();
        }

        pet.checkHealth();

        switch(choice){
            case 1:
                pet.play();
                break;
            case 2:
                pet.feed();
                break;
            case 4:
                pet.print();
                break;
            case 3:
                pet.trick();
                break;
        }

        pet.event();

    }while (choice != 5);
}

void pet::print(){
    cout << "Species: " << species << "\n"
    << "Name: \t" << name << "\n"
    << "Hunger: \t[" << string(hunger, '#') << string(100-hunger, '*') << "]\n"
    << "Happiness: \t[" << string(happiness, '#') << string(100-happiness, '*') << "]\n"
    << "Health: \t[" << string(health, '#') << string(100-health, '*') << "]\n";
}

void pet::checkHealth(){
    if(health <= 0){
        cout << "Your pet has died of poor health." << endl;
        exit(0);
    }
    if(hunger >= 100){
        cout << "Your pet starved to death" << endl;
        exit(0);
    }
    if(happiness <= 0){
        cout << "Your pet died of unhappiness" << endl;
        exit(0);
    }
    if(happiness > 100)
        happiness = 100;
    if(hunger < 0)
        hunger = 0;
    if(health > 100)
        health = 100;
}

void pet::event(){
    int event = rand()%10;
    int value = rand()%10;

    switch(event){
        case 8:
            cout << "Your pet finds a rat on the street and tries to eat it. -" << value << " health. -" << value << " hunger." << endl;
            health -= value;
            hunger -= value;
            break;
        case 9:
            cout << "Your pet runs away from you for a little bit. -" << value << " health. +" << value << " hunger. +" << value << "happiness" << endl;
            health -= value;
            hunger += value;
            happiness += value;
            break;
        case 0:
            cout << "Your pet looks you dead in the eyes and tells you your full date of birth, SSN, and credit card number, followed by \"nobody will believe you\". -" << value << "comfort" << endl;
            break;
    }
}

void pet::play(){
    int addHappy = rand()%10 + 1;
    cout << "You play with your pet! +" << addHappy << " happiness. -" << addHappy << " happy. +" << addHappy << " hunger." << endl;

    happiness += addHappy;
    if(happiness >= 100)
        happiness = 100;

    health -= addHappy;
}

void pet::trick(){
    int trick;
    while (cout << "Trick:\n1) Spin\n2) Backflip\n3) Paint\n4) Math\n> " && !(cin >> trick) || trick < 1 || trick > 4){
        badInput();
    }
    int add = rand()%10 + 1;

    switch(trick - 1){
        case 0:
            cout << "Your pet does a spin! +" << add << " happiness!" << endl;
            happiness += add;
            break;
        case 1:
            if(rand()%2 == 0){
                cout << "Your pet does a sick backflip. Your pet is very proud. +" << add*2 << " happiness!" << endl;
                happiness += add*2;
            } else {
                cout << "Your pet attempts to do a sick double-dog-dare backflip but does not land it. -" << add*2 << " health" << endl;
                happiness -= add*2;
            }
            break;
        case 2:
            cout << "Your pet rapidly paints a 1 for 1 reproduction of the mona lisa. +10 artistic ability, +" << add << " happiness" << endl;
            happiness += add;
            break;
        case 3:
            cout << "Your pet solves the reimann hypothesis. +250 money, +531 intelligence, +" << add << "happiness" << endl;
            happiness += add;
            break;
    }
    if(happiness > 100)
        happiness = 100;
}

void pet::feed(){
    int addHealth = rand()%10 + 1;
    cout << "You feed your pet! +" << addHealth << " health. -" << addHealth << " happiness. -" << addHealth << " hunger." << endl;

    hunger -= addHealth;
    if(hunger <= 0)
        hunger = 0;

    health += addHealth;
    if(health >= 100)
        health = 100;

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