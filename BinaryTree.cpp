#include "BinaryTree.hpp"
#include <iostream>

// Private traversal methods

void BinaryTree::inOrder(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    } else {
        inOrder(currentNode->leftNext);
        std::cout << currentNode->data << " ";
        inOrder(currentNode->rightNext);
    }
}

void BinaryTree::postOrder(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    } else {
        postOrder(currentNode->leftNext);
        postOrder(currentNode->rightNext);
        std::cout << currentNode->data << " ";
    }
}

void BinaryTree::preOrder(Node* currentNode) {
    if (currentNode == nullptr) {
        return;
    } else {
        std::cout << currentNode->data << " ";
        preOrder(currentNode->leftNext);
        preOrder(currentNode->rightNext);
    }
}
//called in deconstructor to clear out allocated memory
void BinaryTree::clear(Node* currentNode) {
    if (currentNode == nullptr) {
        return; // Base case: the tree or subtree is empty.
    } else {
    // Recursively clear the left and right subtrees.
    clear(currentNode->leftNext);
    clear(currentNode->rightNext);
    }
    // Delete the current node and set its parent's appropriate pointer to nullptr.
    if (currentNode->parent != nullptr) {
        if (currentNode->parent->leftNext == currentNode) {
            currentNode->parent->leftNext = nullptr;
        } else if (currentNode->parent->rightNext == currentNode) {
            currentNode->parent->rightNext = nullptr;
        }
    }

    delete currentNode;
    
    if (currentNode == root) {
        root = nullptr; // Reset the root to nullptr when clearing the entire tree.
    }
}
// inserts newnode, checks if the value is greater than or less than its parent then assigns as left or right
void BinaryTree::insertNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->parent = nullptr;
    newNode->leftNext = nullptr;
    newNode->rightNext = nullptr;

    if (root == nullptr) {
        root = newNode; // If the tree is empty, make the new node the root.
    } else {
        Node* currentNode = root;
        while (currentNode != nullptr) {
            if (value < currentNode->data) {
                if (currentNode->leftNext == nullptr) {
                    newNode->parent = currentNode;
                    currentNode->leftNext = newNode;
                    break;
                } else {
                    currentNode = currentNode->leftNext;
                }
            } else {
                if (currentNode->rightNext == nullptr) {
                    newNode->parent = currentNode;
                    currentNode->rightNext = newNode;
                    break;
                } else {
                    currentNode = currentNode->rightNext;
                }
            }
        }
    }
}