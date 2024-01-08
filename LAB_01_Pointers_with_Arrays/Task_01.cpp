#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<stdlib.h>

using namespace std;
void swapping(int *p1, int *p2){
    *p1 = *p1 - *p2;
    *p2 = *p1 + *p2;
    *p1 = *p2 - *p1;
    cout<< "Value of P1: "<< *p1<<endl;
    cout<< "Value of P2: "<< *p2<<endl;
}
int main()
{
    int p1 = 10;
    int p2 = 20;
    int *ptr1 = &p1;
    int *ptr2 = &p2;
    swapping(ptr1, ptr2);
    

    return 0;
}