#include<iostream>
using namespace std;

int fun(int x, int *py, int **pz)
{
    int y, z;
    **pz = **pz + 1;
    z = **pz;
    *py = *py + 2;
    y = *py;
    x = x + 3;
    return x + y + z;
}
int main()
{
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << fun(c, b, a);
    return 0 ;
}