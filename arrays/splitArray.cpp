#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int rotatedBinarySearch(vector<int> &nums,int m){
    int start=0;
    int end=0;
    for (int i = 0;i < nums.size();i++)
    {
        start=std::max(start,nums[i]);
        end+=nums[i];
    }
    //binary search
    while (start<end)
    {
        //try for the middle as the potential ans;
        int mid= start+(end-start)/2;
        int sum=0;
        int pieces=1;
        for(auto num : nums){
            if (sum+num>mid)
            {
               sum=num;
               pieces++;
            }
            else{
                sum+=num;
            }
            
        }
        if (pieces>m)
        {
            start=mid+1;
        }
        else{
            end=mid;
        }
        
        
    }
    
    return end;
}
int main()
{
    vector<int> nums = {
        7, 2, 5, 10, 8};
     int m=2;
        cout<<rotatedBinarySearch(nums,m);
    return 0;
}