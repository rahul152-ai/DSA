#include <iostream>
#include <vector>
using namespace std;
class heap
{
    vector<int> cp;

public:
    bool isEmpty()
    {
        return cp.size() == 0;
    }
    int getMin()
    {
        if (isEmpty())
        {
            return INT_MIN;
        }

        return cp.at(0);
    }
    int getSize()
    {
        return cp.size();
    }

    void insertElement(int element)
    {
        cp.push_back(element);

        int childIndex = cp.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (cp[childIndex] > cp[parentIndex])
            {
                int temp = cp[childIndex];
                cp[childIndex] = cp[parentIndex];
                cp[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = cp[0];
        cp[0] = cp[cp.size() - 1];
        cp.pop_back();
        // down - heapify

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < cp.size())
        {
            int minIndex = parentIndex;
            if (cp[minIndex] > cp[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < cp.size() && cp[rightChildIndex] < cp[minIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
            {
                break;
            }
            int temp = cp[minIndex];
            cp[minIndex] = cp[parentIndex];
            cp[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};
int main()
{

    return 0;
}