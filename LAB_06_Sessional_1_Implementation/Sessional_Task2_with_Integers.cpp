#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " Memory is free for node with data " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{

    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {


        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

bool isPalindrome(Node *tail)
{
    if (tail == NULL)
    {
        return true; 
    }

    Node *slow = tail;
    Node *fast = tail;

    while (fast->next != tail && fast->next->next != tail)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = slow->next;
    slow->next = NULL; 

    Node *prev = NULL;
    Node *current = secondHalf;
    Node *nextNode;

    while (current != tail)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    secondHalf = prev;

    Node *firstHalf = tail;
    while (firstHalf != NULL && secondHalf != NULL)
    {
        if (firstHalf->data != secondHalf->data)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

void print(Node *tail)
{

    Node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
int main()
{
    Node *tail = NULL;

    insertNode(tail, 1, 1);
    insertNode(tail, 1, 2);

    insertNode(tail, 2, 1);
    insertNode(tail, 1, 2);

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
