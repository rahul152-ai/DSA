#include <iostream>
using namespace std;
int numberZero(int n, int count)
{
    if (n == 0)
    {
        return count;
    }
    if (n % 10 == 0)
    {
       return numberZero(n / 10, count + 1);
    }
    else
    {
      return numberZero(n / 10, count);
    }
}
int main()
{
   temp->next=newData;
    return 0;
}