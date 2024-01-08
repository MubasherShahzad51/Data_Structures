#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node *reverseKNodes(Node *head, int k)
{
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
    {
        head->next = reverseKNodes(next, k);
    }

    return prev;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *current = head;
    for (int i = 2; i <= 9; i++)
    {
        current->next = new Node(i);
        current = current->next;
    }

    int k = 3;

    cout << "Original List: ";
    printList(head);

    head = reverseKNodes(head, k);

    cout << "Modified List: ";
    printList(head);

    return 0;
}
