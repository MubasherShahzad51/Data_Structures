#include <iostream>
#include <cstdlib> // rand() and srand() functions
#include <ctime>   // time() function
using namespace std;

const int num_of_weeks = 4;
const int num_of_days = 7;

int main()
{
    srand(time(0)); // random number generator with current time

    int temperatures[num_of_weeks][num_of_days];

    // array with random temperatures
    for (int week = 0; week < num_of_weeks; ++week)
    {
        for (int day = 0; day < num_of_days; ++day)
        {
            temperatures[week][day] = rand() % (30 - 10 + 1) + 10;
        }
    }

    // Display the temperatures using a pointer
    int *tempPtr = &temperatures[0][0];
    cout << "Monthly Temperatures:\n";
    for (int week = 0; week < num_of_weeks; ++week)
    {
        cout << "Week " << week + 1 << ": ";
        for (int day = 0; day < num_of_days; ++day)
        {
            cout << *tempPtr << " ";
            ++tempPtr;
        }
        cout << endl;
    }

    // Find and display the hottest day of each week using pointers
    tempPtr = &temperatures[0][0];
    for (int week = 0; week < num_of_weeks; ++week)
    {
        int maxTemp = *tempPtr;
        int hottestDay = 0;
        for (int day = 1; day < num_of_days; ++day)
        {
            if (*(tempPtr + day) > maxTemp)
            {
                maxTemp = *(tempPtr + day);
                hottestDay = day;
            }
        }
        cout << "Hottest day of Week " << week + 1 << ": Day " << hottestDay + 1
             << " with temperature " << maxTemp << " degrees Celsius\n";
        tempPtr += num_of_days; // Move the pointer to the next week
    }

    return 0;
}