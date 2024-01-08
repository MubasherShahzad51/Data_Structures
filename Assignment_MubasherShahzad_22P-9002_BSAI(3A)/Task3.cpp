#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Student
{
public:
    string name;
    int merit;
};

class Node
{
public:
    Student data;
    Node *next;
};

class Queues
{
private:
    Node *front;
    Node *rear;
    int size;

public:
    Queues()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    ~Queues()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    bool isFull()
    {
        return size >= 10;
    }

    void enqueue(Student student)
    {
        if (isFull())
        {
            cout << "Queue is full." << endl;
            return;
        }

        Node *newNode = new Node;
        newNode->data = student;
        newNode->next = NULL;

        if (isEmpty())
        {
            front = newNode;
        }
        else
        {
            rear->next = newNode;
        }

        rear = newNode;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    int getSize()
    {
        return size;
    }

    Student getFront()
    {
        return front->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = front;
        while (temp != NULL)
        {
            cout << "Name: " << temp->data.name << endl;
            cout << "Merit: " << temp->data.merit << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    Queues queue_1, queue_2, queue_3;

    Student student;
    int size1, size2, size3;
    int num_of_queue;

    int choice;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Add Students to the Queues" << endl;
        cout << "2. Process Admissions" << endl;
        cout << "3. Check Queues Status" << endl;
        cout << "4. See who is next" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the Student Name: ";
            cin >> student.name;
            cout << "Enter the Student Merit: ";
            cin >> student.merit;
            size1 = queue_1.getSize();
            size2 = queue_2.getSize();
            size3 = queue_3.getSize();

            if (size1 <= size2 && size1 <= size3)
            {
                queue_1.enqueue(student);
            }
            else if (size2 <= size1 && size2 <= size3)
            {
                queue_2.enqueue(student);
            }
            else
            {
                queue_3.enqueue(student);
            }

            cout << "Student added to the queue" << endl;
            break;

        case 2:
            while (!queue_1.isEmpty() || !queue_2.isEmpty() || !queue_3.isEmpty())
            {
                if (!queue_1.isEmpty())
                {
                    cout << "Processing student from Queue 1: " << queue_1.getFront().name << endl;
                    queue_1.dequeue();
                }
                if (!queue_2.isEmpty())
                {
                    cout << "Processing student from Queue 2: " << queue_2.getFront().name << endl;
                    queue_2.dequeue();
                }
                if (!queue_3.isEmpty())
                {
                    cout << "Processing student from Queue 3: " << queue_3.getFront().name << endl;
                    queue_3.dequeue();
                }
            }

            cout << "All Admissions are Processed" << endl;
            break;

        case 3:
            cout << "Queue 1: No of Student = " << queue_1.getSize() << endl;
            queue_1.display();
            cout << endl;

            cout << "Queue 2: No of Student = " << queue_2.getSize() << endl;
            queue_2.display();
            cout << endl;

            cout << "Queue 3: No of Student = " << queue_3.getSize() << endl;
            queue_3.display();
            cout << endl;
            break;

        case 4:
            cout << "Enter queue number from 1 to 3: ";
            cin >> num_of_queue;

            if (num_of_queue == 1 && !queue_1.isEmpty())
            {
                cout << "Next student in Queue 1: " << queue_1.getFront().name << endl;
            }
            else if (num_of_queue == 2 && !queue_2.isEmpty())
            {
                cout << "Next student in Queue 2: " << queue_2.getFront().name << endl;
            }
            else if (num_of_queue == 3 && !queue_3.isEmpty())
            {
                cout << "Next student in Queue 3: " << queue_3.getFront().name << endl;
            }
            else
            {
                cout << "Queue is empty" << endl;
            }
            break;

        case 5:
            cout << "Exiting program" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}
