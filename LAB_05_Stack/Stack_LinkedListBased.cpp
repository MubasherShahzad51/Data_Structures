#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {

        data = d;
        next = NULL;
    }
};

class SingleLinkedList
{

    int length;
    Node *head;

public:
    SingleLinkedList()
    {
        head = NULL;
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

    int getLength()
    {
        return length;
    }
};

class Stack : public SingleLinkedList
{
    int top;

public:
    Stack() : SingleLinkedList()
    {
        top = 0;
    }

    void push(int value)
    {

        insert(getLength() + 1, value);
        top++;
    }

    void pop()
    {

        if (getLength() != 0)
        {
            remove(getLength());
            top--;
        }
        else
            cout << "Stack is Empty" << endl;
    }

    int peek()
    {

        if (getLength() == 0)
        {
            return -1;
        }
        return top;
    }

    void reverse(int number)
    {

        while (getLength() != 0)
            pop();

        // Push each digit in the stack
        while (number != 0)
        {
            int digit = number % 10;
            push(digit);
            number /= 10;
        }

        // Pop out each digit and form the reversed integer
        int reverse = 0, i = 1;
        while (getLength() != 0)
        {
            reverse += i * peek();
            pop();
            i *= 10;
        }

        cout << "Reversed number is " << reverse << endl;
    }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.print();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.print();
    cout <<s1.peek()<<"\n";

    return 0;
}