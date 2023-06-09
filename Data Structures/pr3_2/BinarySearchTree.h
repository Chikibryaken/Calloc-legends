#include <iostream>

unsigned long cntCmp2;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BSTree {
private:
    Node* root;

    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insertNode(root->left, value);
        }
        else {
            root->right = insertNode(root->right, value);
        }

        return root;
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        }
        else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* minNode = findMinNode(root->right);
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);
        }

        return root;
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BSTree() {
        root = nullptr;
    }

    BSTree(const BSTree& other) {
        root = copyNodes(other.root);
    }

    BSTree& operator=(const BSTree& other) {
        if (this != &other) {
            // Очистить существующее дерево
            clear(root);

            // Создать копию дерева из other
            root = copyNodes(other.root);
        }

        return *this;
    }

    Node* copyNodes(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* newNode = new Node(node->data);
        newNode->left = copyNodes(node->left);
        newNode->right = copyNodes(node->right);

        return newNode;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void del(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        Node* current = root;
        cntCmp2 = 0;

        while (current != nullptr) {
            if (value == current->data) {
                cntCmp2++;
                return true;
            }
            else if (value < current->data) {
                cntCmp2++;
                current = current->left;
            }
            else {
                cntCmp2++;
                current = current->right;
            }
        }

        return false;
    }
};
