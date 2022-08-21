// mergeSort using recursion;
// in merge sort we split the array recursively
// and then merge the sorted array; 
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &array, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
vector<int> mergeArray(vector<int> left, vector<int> right)
{
    int i = 0, j = 0, k = 0;
    vector<int> merged;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            merged.push_back(left[i]);
            i++;
        }
        else
        {
            merged.push_back(right[j]);
            j++;
        }
        k++;
    }

    while (i < left.size())
    {
        merged.push_back(left[i]);
        i++;
        k++;
    }

    while (j < right.size())
    {
        merged.push_back(right[j]);
        j++;
        k++;
    }

    return merged;
}
vector<int> mergeSort(vector<int> array)
{
    if (array.size() == 1)
    {
        return array;
    }
    int mid=array.size()/2;
    vector<int> leftSplit={array.begin(),array.begin()+mid};
    vector<int> rightSplit={array.begin()+mid,array.begin()+array.size()};
    vector<int> left = mergeSort(leftSplit);
    vector<int> right = mergeSort(rightSplit);
    return mergeArray(left, right);
}

int main()
{
    vector<int> array = {4,3,5,6,7,1,2};
    print(array, array.size());
    vector<int> temp = mergeSort(array);
    print(temp,temp.size());

    return 0;
}