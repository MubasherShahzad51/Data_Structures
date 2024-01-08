#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class singleLinkedList
{

private:
    int length;
    Node *head;

public:
    singleLinkedList()
    {
        head = nullptr;
        length = 0;
    }

    void insert(int pos, int value)
    {

        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        Node *newNode = new Node(value);

        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {

            Node *curr = head;

            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }

            newNode->next = curr->next;
            curr->next = newNode;
        }
        length++;
    }

    void print()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << endl;
    }

    void remove(int pos)
    {
        Node *curr = head;

        if (length == 0)
        {
            cout << "List is Empty." << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (pos == 1)
        {
            head = head->next;
            delete curr;
        }
        else
        {
            Node *slow = NULL;
            for (int i = 1; i < pos; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = curr->next;
            delete curr;
        }
        length--;
    }

    void clear()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
    }

    void get(int pos)
    {
        if (pos < 1 || pos > length)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        Node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        cout << curr->data << endl;
    }

    void find(int value)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            if (curr->data == value)
            {
                cout << "Element found" << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Element Not found" << endl;
    }

    void copy(singleLinkedList &list)
    {

        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;

        // Copying from the given list
        Node *curr = list.head;
        while (curr != NULL)
        {
            insert(length + 1, curr->data);
            curr = curr->next;
        }
    }

    void reverse()
    {
        Node *current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    
};

int main()
{

    singleLinkedList l1, l2;

    l1.insert(1, 150);
    l1.insert(2, 250);
    l1.insert(3, 350);
    l1.insert(4, 450);
    l1.insert(5, 550);
    l1.insert(6, 650);
    l1.print();
    cout << "Copylist" << endl;
    l2.copy(l1);
    l2.print();
    cout << "Again same list" << endl;
    l1.insert(7, 150);
    l1.insert(8, 250);
    l1.insert(9, 350);
    l1.insert(10, 450);
    l1.print();

    cout << "Copylist" << endl;
    l2.copy(l1);
    l2.print();

    l2.get(10);
    l2.find(150);

    return 0;
}