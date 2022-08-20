#include <iostream>
#include <vector>
using namespace std;
int findPivot(vector<int> &array)
{
    //finding the pivot element with duplicate element;
    
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
       if (array[mid]==array[start] && array[mid]==array[end])
       {
           //if the element at start , end, mid are equal 
           //skip the start and element 
           if (array[start]>array[start+1])
           {
               return start;
           }
           start++;
           if (array[end]<array[end-1])
           {
               return end-1;
           }
           end--;
       }
       else if (array[start]<array[mid] ||(array[start]==array[mid] && array[mid]>array[end]))
       {
         start=mid+1;
       }
       else{
           end=mid-1;
       }

       
    }

    return -1;
}
int main()
{
    vector<int> array = {
        4,5,6,7,0,1,2,3
        };
    int target = 0;
    cout<<findPivot(array);
    return 0;
}