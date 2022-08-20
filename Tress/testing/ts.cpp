#include<iostream>

#include <unordered_map>
using namespace std;
int main() {
    int A[] = {1,2,3,4,8,6,7,8};
unordered_map<int,int> map;
for (int i = 0; i < 8; i++)
{
    map[A[i]]++;
}
 unordered_map<int, int>:: iterator p;
    for (p = map.begin(); p != map.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")\n";
cout<<map[9];

}


