#include <iostream>
#include <queue>
using namespace std;

// Definition of the node structure for the Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Class representing the Binary Search Tree
class BinarySearchTree {
private:
    Node* root;

    // Helper function for Insert operation
    Node* insert(Node* node, int val) {
        // If the tree is empty, return a new node
        if (node == nullptr)
            return new Node(val);

        // Otherwise, recur down the tree
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        // Return the (unchanged) node pointer
        return node;
    }

    // Helper function to perform In-order traversal
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function to calculate the depth of the tree
    int depth(Node* node) {
        if (node == nullptr)
            return 0;
        else {
            // Recursively find the depth of both subtrees and take the max
            int leftDepth = depth(node->left);
            int rightDepth = depth(node->right);
            return max(leftDepth, rightDepth) + 1;
        }
    }

    // Helper function to display leaf nodes
    void displayLeafNodes(Node* node) {
        if (node != nullptr) {
            if (node->left == nullptr && node->right == nullptr) {
                cout << node->data << " ";
            }
            displayLeafNodes(node->left);
            displayLeafNodes(node->right);
        }
    }

    // Helper function to search for a value
    bool search(Node* node, int val) {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        else if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Public method to insert a node
    void insert(int val) {
        root = insert(root, val);
    }

    // Public method to perform In-order traversal
    void inorderTraversal() {
        inorderTraversal(root);
    }

    // Public method to calculate the depth of the tree
    int depth() {
        return depth(root);
    }

    // Public method to display leaf nodes
    void displayLeafNodes() {
        displayLeafNodes(root);
    }

    // Public method to search for an element
    bool search(int val) {
        return search(root, val);
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    do {
        cout << "\nBinary Search Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display Tree (In-order Traversal)\n";
        cout << "4. Display Depth of Tree\n";
        cout << "5. Display Leaf Nodes\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insert(value);
            cout << value << " inserted into the tree.\n";
            break;

        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (bst.search(value)) {
                cout << value << " found in the tree.\n";
            } else {
                cout << value << " not found in the tree.\n";
            }
            break;

        case 3:
            cout << "In-order Traversal of the tree: ";
            bst.inorderTraversal();
            cout << endl;
            break;

        case 4:
            cout << "Depth (Height) of the tree: " << bst.depth() << endl;
            break;

        case 5:
            cout << "Leaf nodes in the tree: ";
            bst.displayLeafNodes();
            cout << endl;
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
