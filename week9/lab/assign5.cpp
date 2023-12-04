#include <iostream>
#include <ctime>
#include <cstdlib>

int playerPosition = 0;
int candies = 20;
int health = 100;  // Player's health
int distanceToCandyland = 20;  // Total distance to Candyland

// Function to simulate rolling a die
int rollDie() {
    return rand() % 6 + 1;  // Returns a random number between 1 and 6
}

// Function to handle an event when the player advances
void handleEvent() {
    int event = rollDie();

    switch (event) {
        case 1:
            std::cout << "You found a candy cane! +2 candies." << std::endl;
            candies += 2;
            break;
        case 2:
            std::cout << "You stumbled and dropped some candies. -3 candies." << std::endl;
            candies -= 3;
            break;
        case 3:
            std::cout << "You reached a chocolate river! +5 candies." << std::endl;
            candies += 5;
            break;
        case 4:
            std::cout << "You encountered a candy thief! -4 candies." << std::endl;
            candies -= 4;
            break;
        case 5:
            std::cout << "You found a shortcut! +1 progress." << std::endl;
            playerPosition += 1;
            break;
        case 6:
            std::cout << "You hit a gumdrop swamp! -2 progress." << std::endl;
            playerPosition -= 2;
            break;
    }
}

// Function to simulate random events affecting health
void healthEvent() {
    int event = rand() % 3;

    switch (event) {
        case 0:
            std::cout << "You feel great, +10 health." << std::endl;
            health += 10;
            break;
        case 1:
            std::cout << "You ate too much candy, -5 health." << std::endl;
            health -= 5;
            break;
        case 2:
            std::cout << "You got a sugar rush, +15 health." << std::endl;
            health += 15;
            break;
    }

    if (health < 0) {
        health = 0;
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));  // Seed the random number generator

    std::cout << "Welcome to Candyland! You need to make it to the end without running out of candies." << std::endl;

    while (playerPosition < distanceToCandyland && candies > 0 && health > 0) {
        std::cout << "Current Progress: " << playerPosition << " / " << distanceToCandyland << std::endl;
        std::cout << "Candies: " << candies << std::endl;
        std::cout << "Health: " << health << std::endl;

        std::cout << "Press enter to roll the die...";
        std::cin.get();

        handleEvent();
        healthEvent();

        if (playerPosition < 0) {
            playerPosition = 0;
        }
    }

    if (playerPosition >= distanceToCandyland) {
        std::cout << "Congratulations! You made it to Candyland!" << std::endl;
    } else if (candies <= 0) {
        std::cout << "Game Over! You ran out of candies before reaching Candyland." << std::endl;
    } else {
        std::cout << "Game Over! Your health dropped to zero." << std::endl;
    }

    return 0;
}
