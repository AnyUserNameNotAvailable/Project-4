#include <iostream>
#include "BinaryTree.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    const int numMax = 35;
    const int maxNum = 100;
    int choice;
    BinaryTree B;

    do {
        std::cout << "1. Insert random numbers" << std::endl;
        std::cout << "2. Pre-order traversal" << std::endl;
        std::cout << "3. Post-order traversal" << std::endl;
        std::cout << "4. In-order traversal" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::srand(static_cast<unsigned int>(std::time(nullptr)));
                for (int i = 0; i < numMax; i++) {
                    int value = std::rand() % maxNum;
                    B.insertNode(value);
                }
                break;
            case 2:
                B.preOrder(B.getRoot());
                break;
            case 3:
                B.postOrder(B.getRoot());
                break;
            case 4:
                B.inOrder(B.getRoot());
                break;
            case 5:
                std::cout << "Exiting Program... Bye";
                break;
            default:
                std::cout << "Invalid Choice" << std::endl;
        }
    } while (choice != 5);

    return 0;
}