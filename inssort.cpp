// CODE FOR INSERTION SORT
#include <iostream>
using namespace std;
int main()
{
    int n;
    int arry[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arry[i];
    }

    // RUN THE LOOP TILL LENGTH-2;
    for (int i = 0; i < n - 1; i++)
    {
        // run the loop till j greater than i;
        for (int j = i + 1; j > 0; j--)
        {
            if (arry[j] < arry[j - 1])
            {
                int swap = arry[j];
                arry[j] = arry[j - 1];
                arry[j - 1] = swap;
            }
            else
            {
                break;
            }
        }
    }
  



cout<<arry[0];
cout<<arry[1];
cout<<arry[2];
cout<<arry[3];


   

    return 0;
}