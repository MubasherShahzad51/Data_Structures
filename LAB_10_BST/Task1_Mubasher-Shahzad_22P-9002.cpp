#include <iostream>
#include <string>
using namespace std;

class TreeNode
{
public:
    string gemName;
    int power;
    TreeNode *left;
    TreeNode *right;

    TreeNode(string name, int p)
    {
        this->gemName = name;
        this->power = p;
        this->left = NULL;
        this->right = NULL;
    }
};

class MagicalForest
{
public:
    TreeNode *root;
    int bagPower;

    MagicalForest()
    {
        this->root = NULL;
        this->bagPower = 0;

        root = insert(root, "Diamond", 50);
        root = insert(root, "Ruby", 30);
        root = insert(root, "Sapphire", 70);
        root = insert(root, "Pearl", 40);
        root = insert(root, "Opal", 10);
        root = insert(root, "Garnet", 60);
        root = insert(root, "Zircon", 20);
        root = insert(root, "Jade", 5);
    }

    TreeNode *insert(TreeNode *root, string name, int power)
    {
        if (root == NULL)
        {
            return new TreeNode(name, power);
        }

        if (power < root->power)
        {
            root->left = insert(root->left, name, power);
        }
        else if (power > root->power)
        {
            root->right = insert(root->right, name, power);
        }

        return root;
    }

    void displayTree(int traversalType)
    {
        switch (traversalType)
        {
        case 1:
            cout << "Magical Tree (Pre-order): ";
            preOrder(root);
            break;
        case 2:
            cout << "Magical Tree (In-order): ";
            inOrder(root);
            break;
        case 3:
            cout << "Magical Tree (Post-order): ";
            postOrder(root);
            break;
        }
        cout << endl;
    }

    TreeNode *searchGem(TreeNode *root, int power)
    {
        if (root == NULL || root->power == power)
        {
            return root;
        }

        if (power < root->power)
        {
            return searchGem(root->left, power);
        }

        return searchGem(root->right, power);
    }

    void searchGem(int power)
    {
        TreeNode *result = searchGem(root, power);
        if (result != NULL)
        {
            cout << "[" << result->gemName << ", " << result->power << "]" << endl;
        }
        else
        {
            cout << "Gem not found." << endl;
        }
    }

    TreeNode *findMaxPowerGem(TreeNode *root)
    {
        if (root->right != NULL)
        {
            return findMaxPowerGem(root->right);
        }
        return root;
    }

    void findMaxPowerGem()
    {
        TreeNode *maxPowerGem = findMaxPowerGem(root);
        cout << "Max power gem: [" << maxPowerGem->gemName << ", " << maxPowerGem->power << "]" << endl;
    }

    TreeNode *pluckGem(TreeNode *root, string name, int power, bool &gemPlucked)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (power < root->power || (power == root->power && name < root->gemName))
        {
            root->left = pluckGem(root->left, name, power, gemPlucked);
        }
        else if (power > root->power || (power == root->power && name > root->gemName))
        {
            root->right = pluckGem(root->right, name, power, gemPlucked);
        }
        else
        {
            gemPlucked = true;
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *temp = findMinPowerGem(root->right);
            root->gemName = temp->gemName;
            root->power = temp->power;
            root->right = pluckGem(root->right, name, temp->power, gemPlucked);
        }
        return root;
    }

    TreeNode *findMinPowerGem(TreeNode *root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }

    void pluckGem(int power, string name)
    {
        bool gemPlucked = false;
        root = pluckGem(root, name, power, gemPlucked);
        if (gemPlucked)
        {
            bagPower += power;
            cout << "You plucked: [" << name << ", " << power << "]" << endl;
            cout << "Power in bag: " << bagPower << endl;
            if (bagPower >= 100)
            {
                cout << "You won! Now take your bag and run from the forest" << endl;
            }
        }
        else
        {
            cout << "Gem not found in the forest." << endl;
        }
    }

    void preOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            cout << "[" << root->gemName << ", " << root->power << "] ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            inOrder(root->left);
            cout << "[" << root->gemName << ", " << root->power << "] ";
            inOrder(root->right);
        }
    }

    void postOrder(TreeNode *root)
    {
        if (root != NULL)
        {
            postOrder(root->left);
            postOrder(root->right);
            cout << "[" << root->gemName << ", " << root->power << "] ";
        }
    }
};

int main()
{
    cout << "Welcome to the Magical Forest." << endl;
    int bagCapacity, option, traversalType, powerToFind;
    MagicalForest forest;

    cout << "How much magical power can your bag hold? ";
    cin >> bagCapacity;

    while (forest.bagPower < bagCapacity)
    {
        cout << "Select an option:" << endl;
        cout << "1. Display the magical tree." << endl;
        cout << "2. Search for a gem by specifying its power." << endl;
        cout << "3. Find the gem with the highest magical power." << endl;
        cout << "4. Pluck a gem from the tree" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Which traversal do you want?" << endl;
            cout << "1. Pre-order traversal" << endl;
            cout << "2. In-order traversal" << endl;
            cout << "3. Post-order traversal" << endl;
            cin >> traversalType;
            forest.displayTree(traversalType);
            break;
        case 2:
            cout << "Enter the power of the gem you want to find: ";
            cin >> powerToFind;
            forest.searchGem(powerToFind);
            break;
        case 3:
            forest.findMaxPowerGem();
            break;
        case 4:
            cout << "Enter the name and power of the gem you want to pluck: ";
            string gemName;
            cin >> gemName;
            int gemPower;
            cin >> gemPower;
            forest.pluckGem(gemPower, gemName);
            break;
        }
    }

    return 0;
}
