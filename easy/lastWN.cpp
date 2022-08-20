#include <iostream>
#include <string.h>
using namespace std;
int numberofstring(string s)
{
    int ans = 0;
    for (int i = s.length(); i >= 0;i--)
    {
        if (s[i]!=' ')
        {
            ans++;
        }
        if (s[i] == ' ' && ans != 0)
            break;
    }
    return ans;
}
int main()
{
    string s = "   fly me   to   the moon  ";
     cout << numberofstring(s);
    return 0;
}
