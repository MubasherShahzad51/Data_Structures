#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int ID;
    string name;
    string designation;
    Node *left;
    Node *right;
    int height;

    Node(int id, string n, string d) {
        ID = id;
        name = n;
        designation = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
        
};

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

Node *rightRotate(Node *unbalancedNode)
{
    Node *leftChild = unbalancedNode->left;
    Node *rightOfLeftChild = leftChild->right;

    leftChild->right = unbalancedNode;
    unbalancedNode->left = rightOfLeftChild;

    unbalancedNode->height = max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right)) + 1;
    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;

    return leftChild;
}

Node *leftRotate(Node *leftChild)
{
    Node *unbalancedNode = leftChild->right;
    Node *rightOfLeftChild = unbalancedNode->left;

    unbalancedNode->left = leftChild;
    leftChild->right = rightOfLeftChild;

    leftChild->height = max(getHeight(leftChild->left), getHeight(leftChild->right)) + 1;
    unbalancedNode->height = max(getHeight(unbalancedNode->left), getHeight(unbalancedNode->right)) + 1;

    return unbalancedNode;
}

Node *insert(Node *root, int ID, string name, string designation)
{
    if (root == NULL)
        return new Node(ID, name, designation);

    if (ID < root->ID)
        root->left = insert(root->left, ID, name, designation);
    else if (ID > root->ID)
        root->right = insert(root->right, ID, name, designation);
    else
        return root; 

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && ID < root->left->ID)
        return rightRotate(root);

    if (balance < -1 && ID > root->right->ID)
        return leftRotate(root);

    if (balance > 1 && ID > root->left->ID)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && ID < root->right->ID)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *minValueNode(Node *node)
{
    Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node *root, int ID)
{
    if (root == NULL)
        return root;

    if (ID < root->ID)
        root->left = deleteNode(root->left, ID);
    else if (ID > root->ID)
        root->right = deleteNode(root->right, ID);
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
            Node *temp = minValueNode(root->right);

            root->ID = temp->ID;
            root->name = temp->name;
            root->designation = temp->designation;

            root->right = deleteNode(root->right, temp->ID);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void displayOrganizationalChart(Node *root)
{
    if (root != NULL)
    {
        displayOrganizationalChart(root->left);
        cout << "ID: " << root->ID << ", Name: " << root->name << ", Designation: " << root->designation << endl;
        displayOrganizationalChart(root->right);
    }
}

Node *searchEmployee(Node *root, int ID)
{
    if (root == NULL || root->ID == ID)
        return root;

    if (ID < root->ID)
        return searchEmployee(root->left, ID);

    return searchEmployee(root->right, ID);
}

void modifyEmployeeInformation(Node *root, int ID, string newName, string newDesignation)
{
    Node *employee = searchEmployee(root, ID);

    if (employee != NULL)
    {
        employee->name = newName;
        employee->designation = newDesignation;
        cout << "Employee information modified successfully." << endl;
    }
    else
    {
        cout << "Employee with ID " << ID << " not found." << endl;
    }
}

void removeEmployee(Node *&root, int ID)
{
    root = deleteNode(root, ID);
    cout << "Employee with ID " << ID << " removed successfully." << endl;
}

void displayMenu()
{
    cout << "\nOrganizational Hierarchy Management System" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Search for Employee" << endl;
    cout << "3. Generate Organizational Chart" << endl;
    cout << "4. Modify Employee Information" << endl;
    cout << "5. Remove Employee" << endl;
    cout << "6. Exit" << endl;
}

int main()
{
    Node *root = NULL;
    int choice;

    do
    {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int ID;
            string name, designation;

            cout << "Enter Employee ID: ";
            cin >> ID;
            cin.ignore(); 
            cout << "Enter Employee Name: ";
            getline(cin, name);
            cout << "Enter Employee Designation: ";
            getline(cin, designation);

            root = insert(root, ID, name, designation);
            cout << "Employee added successfully." << endl;
            break;
        }
        case 2:
        {
            int searchID;
            cout << "Enter Employee ID to search: ";
            cin >> searchID;

            Node *employee = searchEmployee(root, searchID);
            if (employee != NULL)
            {
                cout << "Employee Found:" << endl;
                cout << "ID: " << employee->ID << endl;
                cout << "Name: " << employee->name << endl;
                cout << "Designation: " << employee->designation << endl;
            }
            else
            {
                cout << "Employee with ID " << searchID << " not found." << endl;
            }
            break;
        }
        case 3:
            cout << "Organizational Chart:" << endl;
            displayOrganizationalChart(root);
            break;
        case 4:
        {
            int modifyID;
            string newName, newDesignation;

            cout << "Enter Employee ID to modify: ";
            cin >> modifyID;
            cin.ignore(); 
            cout << "Enter New Employee Name: ";
            getline(cin, newName);
            cout << "Enter New Employee Designation: ";
            getline(cin, newDesignation);

            modifyEmployeeInformation(root, modifyID, newName, newDesignation);
            break;
        }
        case 5:
        {
            int removeID;
            cout << "Enter Employee ID to remove: ";
            cin >> removeID;

            removeEmployee(root, removeID);
            break;
        }
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    delete root;

    return 0;
}
