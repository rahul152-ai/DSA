#include <iostream>
#include <cstring>
using namespace std;
template <typename T>

class stackUsingDynamicArray
{
    T *data;
    int nextElement = 0;
    int capcity;
    // constructor for size of stack;
public:
    stackUsingDynamicArray()
    {
        data = new T[4];
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
    void push(T element)
    {
        if (capcity == nextElement)
        {
            T *newData = new T[2 * capcity];
            capcity = 2 * capcity;
            for (int i = 0; i < capcity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[nextElement] = element;
        nextElement++;
    }

    // function of deleting an element from stack;
    T pop()
    {
        if (isEmpty())
        {
            cout << "Our stack is empty" << endl;
            return 0;
        }
        nextElement--;
        return data[nextElement];
    }

    // return the top element;
    T top()
    {
        if (isEmpty())
        {
            cout << "Our stack is empty" << endl;
            return 0;
        }
        return data[nextElement - 1];
    }
};

int main()
{
    cout<<"Stack using templete"<<endl;
    stackUsingDynamicArray<char> s1;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    s1.push('e');
    s1.push('f');
    cout<<s1.pop();
    cout<<s1.top();




    return 0;
}