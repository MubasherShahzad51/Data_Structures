#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *next;

    Node(char d)
    {
        data = d;
        next = NULL;
    }
};

void insertNode(Node *&tail, char element)
{
    Node *newNode = new Node(element);
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

bool isPalindrome(Node *tail)
{
    if (tail == NULL)
    {
        return true; 
    }

    Node *current = tail->next;
    string str;

    do
    {
        str += current->data;
        current = current->next;
    } while (current != tail->next);

    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return false;
        }
    }

    return true;
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *current = tail->next;

    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);

    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 'A');
    insertNode(tail, 'B');
    insertNode(tail, 'C');
    insertNode(tail, 'C');
    insertNode(tail, 'B');
    insertNode(tail, 'A');

    cout << "Circular Linked List: ";
    print(tail);

    bool result = isPalindrome(tail);

    if (result)
    {
        cout << "The circular linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The circular linked list is not a palindrome." << endl;
    }

    return 0;
}
