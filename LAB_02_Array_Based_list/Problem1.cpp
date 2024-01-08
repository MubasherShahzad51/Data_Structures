#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
void Array(char *arr)
{
    char *ptr = arr;
    srand(time(0));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int value = rand() % 10;

            if (value % 2 == 0 || value == 0)
            {
                *(ptr + i * 3 + j) = '*';
            }
            else
            {
                *(ptr + i * 3 + j) = '-';
            }
        }
    }
    *(ptr + 4) = 'o';
}

void printArray(const char *arr)
{
    const char *ptr = arr;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << *(ptr + i * 3 + j) << " ";
        }
        cout << endl;
    }
}

void displayGameOptions()
{
    cout << "Choose a move, you are standing in the middle of the grid at O position." << endl;
    cout << "1). Top" << endl
         << "2). Bottom" << endl
         << "3). Left" << endl
         << "4). Right" << endl;
    cout << "------------------------" << endl;
}

int main()
{
    cout << endl;
    cout << "Welcome to the collision detection game!";
    int choice;
    char grid[3][3];
    char *gridPtr = &grid[0][0];
    Array(gridPtr);

    char *curr = &grid[1][1];
    cout << endl;

    displayGameOptions();
    cout << "Choose Position: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        curr = curr - 3;
        break;
    case 2:
        curr = curr + 3;
        break;
    case 3:
        curr = curr - 1;
        break;
    case 4:
        curr = curr + 1;
        break;
    default:
        cout << "Invalid Choice: " << endl;
        return 0;
    }

    cout << *curr << endl;
    cout << "Moved at: " << *curr << endl
         << endl;

    if (*curr != '*')
    {
        cout << "You lost, Collided" << endl;
    }
    else
    {
        cout << "Safe Place, You won" << endl;
    }

    printArray(gridPtr);

    return 0;
}