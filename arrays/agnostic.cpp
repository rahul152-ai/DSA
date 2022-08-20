#include<iostream>
#include<vector>
using namespace std;
int orderagnostic(vector<int> &array,int target){
    int start=0;
    int end=array.size()-1;
    bool isAsc=array[start]<array[end];
    
    while (start<=end)
    {
      int mid=start+(end-start)/2;
      if (array[mid]==target)
      {
          return mid;
      }
      if (isAsc)
      {
          if (target<array[mid])
          {
              end=mid-1;
          }
          else{
              start=mid+1;
          }
          
      }
      else{
          if (target<array[mid])
          {
             start=mid+1;
          }
          else{
              end=mid-1;
          }
          
      }
      
        
    }
    
  return -1;
}
int main()
{
    vector<int> array={
        12,9,8,7,5,3,2,1
    };
    int target=1;
    cout<<orderagnostic(array,target);
    return 0;
}
