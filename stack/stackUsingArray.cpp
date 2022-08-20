#include <iostream>
#include <climits>
using namespace std;
class stackUsingArray
{
    int *data;
    int nextElement = 0;
    int capcity;
    // constructor for size of stack;
public:
    stackUsingArray(int sizeofStack)
    {
        data = new int[sizeofStack];
        capcity = sizeofStack;
    }

    // function for checking our stack in empty or not;
    bool isEmpty()
    {
        return nextElement == 0;
    }

    // function for checking number of element in stack;
    int size()
    {
        return nextElement;
    }
    // function for pushing data in stack;
    void push(int element)
    {
        if (capcity == nextElement)
        {
            cout << "Stack is full"<<endl;
            return;
        }
        data[nextElement] = element;
        nextElement++;
    }

    // function of deleting an element from stack;
    int pop()
    {
        if (isEmpty())
        {
            cout << "Our stack is empty"<<endl;
            return INT_MIN;
        }
        nextElement--;
        return data[nextElement];
    }

    // return the top element;
    int top()
    {
        if (isEmpty())
        {
            cout << "Our stack is empty"<<endl;
            return INT_MIN;
        }
        return data[nextElement-1];

    }
};

// int main()
// {
  
  
//     return 0;
// }