#include <iostream>

int main() {
    int num_layers;
    std::cout << "Enter the number of layers: ";
    std::cin >> num_layers;

    for (int i = 1; i <= num_layers; i++) {
        for (int j = 1; j <= num_layers - i; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "#";
        }
        std::cout << std::endl;
    }

    return 0;
}
