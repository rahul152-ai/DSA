#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &array)
{
    //finding the pivot element
    
    int start = 0;
    int end = array.size() - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (mid < end && array[mid] > array[mid + 1])
        {
            return mid;
        }
        if (mid > start && array[mid] < array[mid - 1])
        {
            return mid - 1;
        }
        if (array[mid] <= array[start])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return -1;
}
// binary search if array is not rotated
int binarySearch(vector<int> &array, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (array[mid] < target)
        {
            start = mid + 1;
        }
        else if (array[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            // and found
            return mid;
        }
    }

    return -1;
}
int main()
{
    vector<int> array = {
        5, 6, 7, 8, 9, 0, 1, 2, 3, 4};
    int target = 12;
    int pivot = findPivot(array);
    if (pivot == -1)
    {
        cout << binarySearch(array, target, 0, array.size() - 1);
    }
    else
    {
        if (array[pivot] == target)
        {
            cout << pivot;
        }
        else if (target >= array[0])
        {
            cout << binarySearch(array, target, 0, pivot - 1);
        }
        else
        {
            cout << binarySearch(array, target, pivot + 1, array.size() - 1);
        }
    }

    return 0;
}