// program to print factorial of n;
#include<iostream>
using namespace std;

int factorail(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return n * factorail(n - 1);
}
int main()
{
    cout << factorail(4);
    return 0;
}
