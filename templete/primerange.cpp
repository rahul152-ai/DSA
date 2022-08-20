#include <iostream>
using namespace std;
void primeRange(int start, int end)
{
    
    if (end < start)
    {
        cout << "Enter right range of number" << endl;
    }
    if (start<=1)
    {
        start=2;
    }
    
    for (int i = start; i <= end; i++)
    {
        int flag = 0;
        for (int j = 2; j <= i/2; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << i << endl;
        }
    }
}

int main()
{
    int start;
    int end;
    cout << "Enter range sepreated by space," << endl;
    cin >> start >> end;
    primeRange(start,end);

    return 0;
}