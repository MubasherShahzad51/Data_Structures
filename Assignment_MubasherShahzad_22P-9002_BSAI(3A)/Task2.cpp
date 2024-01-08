#include <iostream>
#include <math.h>
using namespace std;

#define MAX 5  

class Tower {
public:
    char name;
    int top;
    int disks[MAX];

    Tower(char n) {
        top = -1;
        name = n;
    }

    void push(int disk) {
        disks[++top] = disk;
    }

    int pop() {
        return disks[top--];
    }

    int topElement() {
        if (top == -1) {
            return -1;
        } else {
            return disks[top];
        }
    }
};

void moveDisk(Tower &origin, Tower &destination) {
    int diskToMove = origin.pop();
    destination.push(diskToMove);
    cout << "Move disk " << diskToMove << " from rod " << origin.name << " to rod " << destination.name << "\n";
}

void towerOfHanoiIterative(Tower &A, Tower &B, Tower &C, int n) {
    int m = pow(2, n) - 1;

    if (n % 2 == 0) {
        swap(B.name, C.name);  
    }

    for (int i = n; i >= 1; i--) {
        A.push(i);
    }

    for (int i = 1; i <= m; i++) {
        if (i % 3 == 1) {
            if (C.topElement() == -1 || (A.topElement() != -1 && A.topElement() < C.topElement())) {
                moveDisk(A, C);
            } else {
                moveDisk(C, A);
            }
        } else if (i % 3 == 2) {
            if (B.topElement() == -1 || (A.topElement() != -1 && A.topElement() < B.topElement())) {
                moveDisk(A, B);
            } else {
                moveDisk(B, A);
            }
        } else {
            if (B.topElement() == -1 || (C.topElement() != -1 && C.topElement() < B.topElement())) {
                moveDisk(C, B);
            } else {
                moveDisk(B, C);
            }
        }
    }
}

int totalMoves(int disks)
{
    return (int)pow(2, disks) - 1;
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    Tower A('A'), B('B'), C('C');
    towerOfHanoiIterative(A, B, C, n);
 cout << "Total number of moves: " << totalMoves(n) << endl;
    return 0;
}
