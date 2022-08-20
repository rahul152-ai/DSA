#include <iostream>
using namespace std;
int main()
{
    int arry[] = {2,4,1,5};
    int arrSize = sizeof(arry) / sizeof(arry[0]);
    int i = 0 ;
    while (i < arrSize)
    {
        int correct = arry[i] - 1;
        if (arry[i] != correct)
        {
            int swap = arry[i];
            arry[i] = arry[correct];
            arry[correct] = swap;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < arrSize; i++)
    {
        cout << arry[i];
    }

    return 0;
}