#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }

    void insert(int value, int insertValue, char position)
    {
        Node *newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        Node *curr = findNode(root, insertValue);

        if (curr == NULL)
        {
            cout << "Invalid node value!" << endl;
            return;
        }

        if (position == 'L')
        {
            if (curr->left != NULL)
            {
                cout << "There is already a node at the left position!" << endl;
                return;
            }
            curr->left = newNode;
        }
        else if (position == 'R')
        {
            if (curr->right != NULL)
            {
                cout << "There is already a node at the right position!" << endl;
                return;
            }
            curr->right = newNode;
        }
        else
        {
            cout << "Invalid position! Use 'L' for left and 'R' for right." << endl;
            return;
        }
    }

    Node *findNode(Node *curr, int value)
    {
        if (curr == nullptr)
            return nullptr;

        if (curr->data == value)
            return curr;

        Node *left = findNode(curr->left, value);
        if (left != nullptr)
            return left;

        Node *right = findNode(curr->right, value);
        if (right != nullptr)
            return right;

        return nullptr;
    }

    void printTree(Node *curr, char type)
    {
        if (curr == nullptr)
            return;

        if (type == 'P')
            cout << curr->data << " ";

        printTree(curr->left, type);

        if (type == 'I')
            cout << curr->data << " ";

        printTree(curr->right, type);

        if (type == 'O')
            cout << curr->data << " ";
    }

    int findDepth(Node *node)
    {
        if (node == nullptr)
            return -1;

        int left_depth = 1 + findDepth(node->left);
        int right_depth = 1 + findDepth(node->right);

        return max(left_depth, right_depth);
    }

    int height(Node *node, int value)
    {
        if (node == nullptr)
            return 0;

        if (node->data == value)
            return 1 + findDepth(node);

        return max(height(node->left, value), height(node->right, value));
    }

    int level(Node *node, int value, int currentLevel)
    {
        if (node == NULL)
            return 0;

        if (node->data == value)
            return currentLevel;

        int leftLevel = level(node->left, value, currentLevel + 1);

        if (leftLevel != 0)
            return leftLevel;

        int rightLevel = level(node->right, value, currentLevel + 1);

        if (rightLevel != 0)
            return rightLevel;

        return 0;
    }
    void deleteTree(Node *node)
    {
        if (node)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    bool search(Node *node, int value)
    {
        if (!node)
            return false;

        if (node->data == value)
            return true;

        return search(node->left, value) || search(node->right, value);
    }
};
int main()
{

    Tree binaryTree;

    int choice;
    while (true)
    {
        cout << "\n1. Insert\n"
             << "2. Print\n"
             << "3. Find Depth\n"
             << "4. Find Level\n"
             << "5. Search\n"
             << "6. Delete Tree\n"
             << "7. Exit\n"
             << endl;
        cin >> choice;
        int num;
        switch (choice)
        {
        case 1:
            int insertValue;
            char position;
            cout << "Enter your value: ";
            cin >> num;
            cout << "Enter value of the node where new node will be inserted: ";
            cin >> insertValue;
            cout << "Enter position (L for left, R for right): ";
            cin >> position;
            binaryTree.insert(num, insertValue, position);
            break;

        case 2:
            char printType;
            cout << "Enter print type (P/I/O): ";
            cin >> printType;
            binaryTree.printTree(binaryTree.root, printType);
            break;

        case 3:
            cout << "Depth of tree is: " << binaryTree.findDepth(binaryTree.root) << endl;
            break;

        case 4:
            int heightValue;
            cout << "Enter value to find Level: ";
            cin >> heightValue;
            cout << "Level of node containing " << heightValue << " is: "
                 << binaryTree.level(binaryTree.root, heightValue, 1) << endl;
            break;

        case 5:
            int searchValue;
            cout << "Enter value to search: ";
            cin >> searchValue;
            if (binaryTree.search(binaryTree.root, searchValue))
                cout << searchValue << " found!" << endl;
            else
                cout << searchValue << " not found!" << endl;
            break;

        case 6:
            binaryTree.deleteTree(binaryTree.root);
            binaryTree.root = nullptr;
            cout << "Tree deleted" << endl;
            break;
        case 7:
            cout << "Exiting...";
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}