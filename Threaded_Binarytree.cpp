#include <iostream>
using namespace std;

// Define the structure of a node in the threaded binary tree
struct Node {
    int data;
    Node *left, *right;
    bool leftThread, rightThread;  // Thread indicators

    // Constructor
    Node(int val) : data(val), left(nullptr), right(nullptr), leftThread(false), rightThread(false) {}
};

// Class for the Threaded Binary Tree
class ThreadedBinaryTree {
private:
    Node* root;

public:
    // Constructor
    ThreadedBinaryTree() : root(nullptr) {}

    // Function to insert a node in the threaded binary tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Function to traverse the tree in In-order
    void inOrderTraversal() {
        Node* current = leftMost(root);
        while (current != nullptr) {
            cout << current->data << " ";
            if (current->rightThread) {
                current = current->right;
            } else {
                current = leftMost(current->right);
            }
        }
        cout << endl;
    }

    // Function to traverse the tree in Pre-order
    void preOrderTraversal() {
        preOrder(root);
        cout << endl;
    }

private:
    // Helper function to insert a node recursively
    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        // Insertion logic for the threaded binary tree
        if (value < root->data) {
            if (root->leftThread == false) {
                root->left = insertNode(root->left, value);
            } else {
                Node* temp = new Node(value);
                temp->left = root->left;
                temp->right = root;
                root->left = temp;
                root->leftThread = true;
            }
        } else if (value > root->data) {
            if (root->rightThread == false) {
                root->right = insertNode(root->right, value);
            } else {
                Node* temp = new Node(value);
                temp->right = root->right;
                temp->left = root;
                root->right = temp;
                root->rightThread = true;
            }
        }
        return root;
    }

    // Function to find the leftmost node
    Node* leftMost(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->left != nullptr && !root->leftThread) {
            root = root->left;
        }
        return root;
    }

    // Recursive function for Pre-order traversal
    void preOrder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        if (node->leftThread == false) preOrder(node->left);
        if (node->rightThread == false) preOrder(node->right);
    }
};

int main() {
    ThreadedBinaryTree tbt;

    int n, value;
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    // Taking input from the user
    cout << "Enter " << n << " values to insert into the tree:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        tbt.insert(value);
    }

    cout << "\nIn-order Traversal: ";
    tbt.inOrderTraversal();

    cout << "Pre-order Traversal: ";
    tbt.preOrderTraversal();

    return 0;
}
