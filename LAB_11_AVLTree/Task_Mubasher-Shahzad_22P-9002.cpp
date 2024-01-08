#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

class AVLTree
{
public:
    Node *root;

    AVLTree()
    {
        root = NULL;
    }

    int getHeight(Node *node)
    {
        if (node == NULL)
            return 0;

        return node->height;
    }

    int getBalance(Node *node)
    {
        if (node == NULL)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }

    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        Node *temp = newRoot->right;

        newRoot->right = node;
        node->left = temp;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        Node *temp = newRoot->left;

        newRoot->left = node;
        node->right = temp;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node *insertValue(Node *node, int value)
    {
        if (node == NULL)
        {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->height = 1;

            return newNode;
        }

        if (value < node->data)
            node->left = insertValue(node->left, value);
        else if (value > node->data)
            node->right = insertValue(node->right, value);
        else
            return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalance(node);

        if (balance > 1)
        {
            if (value < node->left->data)
                return rotateRight(node);
            else
            {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        else if (balance < -1)
        {
            if (value > node->right->data)
                return rotateLeft(node);
            else
            {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node *minValue(Node *node)
    {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;

        return current;
    }
    Node *maxValue(Node *node)
    {
        Node *current = node;
        while (current->right != NULL)
            current = current->right;

        return current;
    }

    Node *deleteValue(Node *root, int value)
    {
        if (root == NULL)
            return root;

        if (value < root->data)
            root->left = deleteValue(root->left, value);
        else if (value > root->data)
            root->right = deleteValue(root->right, value);
        else
        {
            if (root->left == NULL || root->right == NULL)
            {
                Node *temp = root->left ? root->left : root->right;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else
            {
                Node *temp = minValue(root->right);
                root->data = temp->data;
                root->right = deleteValue(root->right, temp->data);
            }
        }

        if (root == NULL)
            return root;

        root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
        int balance = getBalance(root);

        if (balance > 1)
        {
            if (getBalance(root->left) >= 0)
                return rotateRight(root);
            else
            {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }
        else if (balance < -1)
        {
            if (getBalance(root->right) <= 0)
                return rotateLeft(root);
            else
            {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }

        return root;
    }
    Node *updateValue(Node *root, int oldValue, int newValue)
    {
        root = deleteValue(root, oldValue);
        root = insertValue(root, newValue);
        return root;
    }
    void inOrderTraversal(Node *node)
    {
        if (node != NULL)
        {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    Node *Search(Node *root, int data)
    {
        if (root == NULL || root->data == data)
            return root;

        if (root->data < data)
            return Search(root->right, data);

        return Search(root->left, data);
    }

    void printMenu()
    {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. InOrder Traversal\n";
        cout << "4. Search\n";
        cout << "5. Update Value\n";
        cout << "6. Find Min\n";
        cout << "7. Find Max\n";
        cout << "8. Exit\n";
    }
};

int main()
{
    AVLTree tree;
    int choice, value;

    do
    {
        tree.printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            tree.root = tree.insertValue(tree.root, value);
            cout << "Tree after insertion:" << endl;
            tree.inOrderTraversal(tree.root);
            cout << endl;
            break;
        case 2:
            cout << "Enter the value to be deleted: ";
            cin >> value;
            tree.root = tree.deleteValue(tree.root, value);
            cout << "Tree after deletion:" << endl;
            tree.inOrderTraversal(tree.root);
            cout << endl;
            break;
        case 3:
            cout << "In Order Traversal: ";
            tree.inOrderTraversal(tree.root);
            cout << endl;
            break;
        case 4:
            cout << "Enter the value to be searched: ";
            cin >> value;
            if (tree.Search(tree.root, value) != NULL)
                cout << "Value Found\n";
            else
                cout << "Value Not Found\n";
            break;

        case 5:
            int oldValue, newValue;
            cout << "Enter the value to update: ";
            cin >> oldValue;
            cout << "Enter the new value: ";
            cin >> newValue;
            tree.root = tree.updateValue(tree.root, oldValue, newValue);
            break;
        case 6:
            cout << "Minimum value in the tree: " << tree.minValue(tree.root)->data << endl;
            break;
        case 7:
            cout << "Maximum value in the tree: " << tree.maxValue(tree.root)->data << endl;
            break;
        case 8:
            exit(0);
        default:
            cout << "Incorrect choice. Please make a correct selection.\n";
        }
    } while (choice != 8);

    return 0;
}
