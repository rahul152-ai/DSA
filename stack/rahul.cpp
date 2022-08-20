#include <iostream>
#include <climits>
using namespace std;
#include "stackUsingArray.cpp"
int main()
{
    stackUsingArray rahul(3);
    rahul.push(10);
    rahul.push(20);
    rahul.push(30);
    rahul.push(40);
    cout << rahul.size() << endl;
    cout << rahul.top() << endl;
    cout << rahul.isEmpty() << endl;
    cout << rahul.pop() << endl;
    cout << rahul.pop() << endl;
    cout << rahul.pop() << endl;
    cout << rahul.pop() << endl;
    return 0;
}