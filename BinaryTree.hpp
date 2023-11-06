#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <iostream>

class BinaryTree {
private:
    struct Node {
        int data;
        Node* parent;
        Node* leftNext;
        Node* rightNext;
    };

    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }
    
    ~BinaryTree() {
        clear(root); // Call the clear function in the destructor
    }

    //root cannot be accessed in main function error fix, remember to delete if it does work
    Node* getRoot() const {
        return root;
    }

    void insertNode(int value);
    void inOrder(Node* currentNode);
    void preOrder(Node* currentNode);
    void postOrder(Node* currentNode);

    // Public clear function
    void clear(Node* currentNode);
};

#endif /* BinaryTree_hpp */