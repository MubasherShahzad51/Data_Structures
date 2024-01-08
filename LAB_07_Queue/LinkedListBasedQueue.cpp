#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;
    int capacity;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        front = rear = NULL;
        size = 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        Node *newNode = new Node(value);
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        
        size++;
        cout << value << " enqueued to the queue." << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;

        size--;
    }

    int count()
    {
        return size;
    }
};

int main()
{
    Queue q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Queue is full: " << (q.isFull() ? "Yes" : "No") << endl;

    q.dequeue();
    q.dequeue();

    cout << "Queue is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Current size of the queue: " << q.count() << endl;

    return 0;
}
