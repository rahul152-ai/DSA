#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

// printing all possible permutation of string;
void permutation(std::string p, std::string up)
{
    if (up.length() == 0)
    {
        cout << p << endl;
        return;
    }
    char ch = up.at(0);
    for (int i = 0; i <= p.length(); i++)
    {
        string f = p.substr(0, i);
        string s = p.substr(i, p.length());
        permutation(f + ch + s, up.substr(1));
    }
}
// returning a list of all possible permutation without passing passing the list in argunment;

vector<string> permutationlist(std::string p, std::string up)
{
    if (up.length() == 0)
    {
        vector<string> list;
        list.push_back(p);
        cout<<p<<endl;
        return list;
    }
    char ch = up.at(0);

    vector<string> ans;
    for (int i = 0; i <= p.length(); i++)
    {
        string f = p.substr(0, i);
        string s = p.substr(i, p.length());
        vector<string> ans2 = ans;
        ans.clear();
        vector<string> ans3 = permutationlist(f + ch + s, up.substr(1));
        merge(ans2.begin(), ans2.end(), ans3.begin(), ans3.end(), ans.begin());
    }
    return ans;
}
int main()
{
    vector<string> ans = permutationlist("", "abcd");
    for (int i = 0; i < ans.size(); i++)
    {
        /* code */
        cout<<ans[i]<<endl;
    }

    return 0;
}