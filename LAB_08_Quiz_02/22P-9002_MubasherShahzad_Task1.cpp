#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
struct Node
{
    string name;
    Node *next;
};

void insert(Node *&head, string name)
{
    Node *newNode = new Node;
    newNode->name = name;

    if (!head)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void traversePlayers(Node *head)
{
    if (!head)
    {
        cout << "No players in the list." << endl;
        return;
    }

    Node *current = head;
    do
    {
        cout << current->name << endl;
        cout << "1. Next" << endl;
        cout << "2. Go to the main menu" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            current = current->next;
        }
        else if (choice == 2)
        {
            break;
        }
    } while (current != head);
}

Node *startGame(Node *&head)
{
    Node *current = head;

    while (current->next != current)
    {
        int randomNo = rand() % 5 + 1;
        Node *prev = nullptr;

        for (int i = 1; i < randomNo; i++)
        {
            prev = current;
            current = current->next;
        }

        if (prev)
        {
            prev->next = current->next;
        }
        else
        {
            head = current->next;
        }

        Node *winner = current;
        current = current->next;

        cout << "Random no: " << randomNo << endl;
        cout << winner->name << " removed from the game" << endl;
        delete winner;

        cout << "Current players:" << endl;
        Node *temp = current;
        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != current);
        cout << endl;
    }

    return current;
}

int main()
{
    Node *head = nullptr;
    insert(head, "Hassan");
    insert(head, "Sameer");
    insert(head, "Moon");
    insert(head, "Mubasher");
    insert(head, "Saad");

    int choice;

    do
    {
        cout<<"Enter Your Choice Below: "<<endl;
        cout << "1. Traverse players one by one" << endl;
        cout << "2. Start game" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            traversePlayers(head);
            break;
        case 2:
            if (head)
            {
                Node *winner = startGame(head);
                cout << "Winner is: " << winner->name << endl;
                delete winner;
            }
            else
            {
                cout << "No players to start the game." << endl;
            }
            break;
        case 3:
            while (head)
            {
                Node *temp = head->next;
                if (temp == head)
                {
                    delete head;
                    break;
                }
                head->next = temp->next;
                delete temp;
            }
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
