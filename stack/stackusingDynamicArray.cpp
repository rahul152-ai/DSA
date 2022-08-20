#include <iostream>
#include <climits>
using namespace std;

//stack using dynamic array;
class stackUsingDynamicArray
{
    int *data;
    int nextElement = 0;
    int capcity;
    // constructor for size of stack;
public:
    stackUsingDynamicArray()
    {
        data = new int[4];
        capcity = 4;
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
           int *newData = new int[2*capcity];
           capcity=2*capcity;
           for (int i = 0; i < capcity; i++)
           {
            newData[i]=data[i];
           }
           delete [] data;
           data=newData;
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
int main(){

    stackUsingDynamicArray rahul;
    rahul.push(10);
    rahul.push(20);
    rahul.push(30);
    cout<<rahul.top()<<endl;
    rahul.push(40);
    rahul.push(50);
    cout<<rahul.top()<<endl;
    cout<<rahul.size()<<endl;
   

  
    return 0;
}