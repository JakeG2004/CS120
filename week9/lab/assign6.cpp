#include <iostream>
using namespace std;

int score = 0;

int room1() {
    cout << "You are in a dark forest. You see a path leading north.\n";
    cout << "Options:\n";
    cout << "1. Go north\n";
    cout << "2. Stay here\n";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        return 2; // Moving to room 2
    }
    return 1; // Staying in the same room
}

int room2() {
    static bool firstTime = true;
    if (firstTime) {
        cout << "You find a treasure chest in the clearing. You gain 10 gold!\n";
        score += 10;
        firstTime = false;
    }
    
    cout << "You are in a peaceful clearing with the treasure chest. A path leads east.\n";
    cout << "Options:\n";
    cout << "1. Go east\n";
    cout << "2. Go back to the forest\n";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        return 3; // Moving to room 3
    }
    return 1; // Going back to room 1
}

int room3() {
    cout << "You enter a cave. It's dark inside.\n";
    cout << "Options:\n";
    cout << "1. Go deeper into the cave\n";
    cout << "2. Go back to the clearing\n";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        return 4; // Moving to room 4
    }
    return 2; // Going back to room 2
}

int room4() {
    cout << "You find a glowing crystal. It's illuminating the cave.\n";
    
    if (score < 50) {
        cout << "You gain 20 gold for finding the crystal!\n";
        score += 20;
    }
    
    cout << "Options:\n";
    cout << "1. Take the crystal and go back\n";
    cout << "2. Leave the crystal and go back\n";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        return 2; // Going back to room 2
    }
    return 3; // Going back to room 3
}

int room5() {
    cout << "You are on top of a hill, with a great view. A path leads south.\n";
    cout << "Options:\n";
    cout << "1. Go south\n";
    cout << "2. Stay on the hill\n";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        return 6; // Moving to room 6
    }
    return 5; // Staying on the hill
}

int room6() {
    static bool firstTime = true;
    if (firstTime) {
        cout << "You find a butterfly trapped in a jar. You release it!\n";
        score += 1;
        firstTime = false;
    }
    
    cout << "You are in a garden with colorful butterflies. A path leads north.\n";
    cout << "Options:\n";
    cout << "1. Go north\n";
    cout << "2. Explore the garden\n";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        return 5; // Moving to room 5
    }
    return 6; // Staying in the garden
}

void printScore() {
    cout << "Gold Collected: " << score << endl;
}

int main() {
    int currentRoom = 1;

    while (true) {
        switch (currentRoom) {
            case 1:
                currentRoom = room1();
                break;
            case 2:
                currentRoom = room2();
                break;
            case 3:
                currentRoom = room3();
                break;
            case 4:
                currentRoom = room4();
                break;
            case 5:
                currentRoom = room5();
                break;
            case 6:
                currentRoom = room6();
                break;
            default:
                cout << "Invalid room number. Exiting." << endl;
                return 1;
        }

        printScore();
    }

    return 0;
}
