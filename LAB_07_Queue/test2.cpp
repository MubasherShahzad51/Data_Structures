#include <iostream>
using namespace std;

class Visitor
{
public:
    string name;
    Visitor *next;
    Visitor(string name)
    {
        this->name = name;
        next = NULL;
    }
};

class Queue
{
public:
    Visitor *front;
    Visitor *rear;

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(string name)
    {
        Visitor *newVisitor = new Visitor(name);
        if (isEmpty())
        {
            front = rear = newVisitor;
        }
        else
        {
            rear->next = newVisitor;
            rear = newVisitor;
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            Visitor *temp = front;
            front = front->next;
            delete temp;
        }
    }

    string getFront()
    {
        if (!isEmpty())
        {
            return front->name;
        }
        else
        {
            return "Queue is empty.";
        }
    }

    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

int main()
{
    Queue ticket;
    Queue roller;
    Queue motion;
    Queue round_wheel;

    while (true)
    {
        cout << "\nEnter your choice:" << endl;
        cout << "1. Enter a visitor in tickets purchase queue." << endl;
        cout << "2. Sell a ticket." << endl;
        cout << "3. Process all queues." << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string visitorName;
            cout << "Enter the visitor's name: ";
            cin >> visitorName;
            ticket.enqueue(visitorName);
            break;
        }
        case 2:
        {
            if (!ticket.isEmpty())
            {
                string visitorName = ticket.getFront();
                ticket.dequeue();
                cout << "Now selling ticket to: " << visitorName << "..." << endl;

                int attractionChoice;
                cout << "Which attraction's ticket " << visitorName << " wants?" << endl;
                cout << "1. Roller Coaster" << endl;
                cout << "2. Motion Ride" << endl;
                cout << "3. Round Wheel" << endl;
                cin >> attractionChoice;

                switch (attractionChoice)
                {
                case 1:
                    roller.enqueue(visitorName);
                    cout << "Roller coaster ticket sold to " << visitorName << endl;
                    break;
                case 2:
                    motion.enqueue(visitorName);
                    cout << "Motion ride ticket sold to " << visitorName << endl;
                    break;
                case 3:
                    round_wheel.enqueue(visitorName);
                    cout << "Round wheel ticket sold to " << visitorName << endl;
                    break;
                default:
                    cout << "Invalid attraction choice." << endl;
                    break;
                }
            }
            else
            {
                cout << "No more visitors in the queue" << endl;
            }
            break;
        }
        case 3:
            cout << "Processing all queues..." << endl;
            while (!roller.isEmpty() || !motion.isEmpty() || !round_wheel.isEmpty())
            {
                if (!roller.isEmpty())
                {
                    string visitorName = roller.getFront();
                    roller.dequeue();
                    cout << "Visitor " << visitorName << " now enjoying at the attraction roller coaster." << endl;
                }
                if (!motion.isEmpty())
                {
                    string visitorName = motion.getFront();
                    motion.dequeue();
                    cout << "Visitor " << visitorName << " now enjoying at the attraction motion ride." << endl;
                }
                if (!round_wheel.isEmpty())
                {
                    string visitorName = round_wheel.getFront();
                    round_wheel.dequeue();
                    cout << "Visitor " << visitorName << " now enjoying at the attraction round wheel." << endl;
                }
            }
            cout << "All queues processed." << endl;
            break;
        case 4:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
