#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

bool linearSearch(vector<int> &array,int target,int index){
    //return ture of or false
    if (index==array.size())
    {
       return false;
    }
    return array[index]==target ||linearSearch(array,target,index+1);
    
}

//linear search return index value;
int linearSearchIndex(vector<int> &array,int target,int index){
    //return ture of or false
    if (index==array.size())
    {
       return -1;
    }
    if (array[index]==target)
    {
        return index;
    }
    else{
        return linearSearchIndex(array,target,index+1);
    }
    
    
    
}

//find all occurences of target
vector<int> ans;
void linearSearchAllIndex(vector<int> &array,int target,int index){
    //return ture of or false
    if (index==array.size())
    {
       return;
    }
    if (array[index]==target)
    {
        ans.push_back(index);
    }
    
    linearSearchAllIndex(array,target,index+1);
    
}

//returinin an array list using recursion
vector<int> linearSearchAllIndexList(vector<int> &array,int target,int index,vector<int> &list1){
    if (index==array.size())
    {
       return list1;
    }
    if (target==array[index])
    {
        list1.push_back(index);
    }
    
    return linearSearchAllIndexList(array,target,index+1,list1);

}

//returning a list from function without passing in the argunment
vector<int> linearSearchAllIndexList2(vector<int> &array,int target,int index){
    vector<int> list;
    if (index==array.size())
    {
       return list;
    }
    if (target==array[index])
    {
        list.push_back(index);
    }
    
   std::vector<int> v(list);
   vector<int> list2=linearSearchAllIndexList2(array,target,index+1);
   std::copy(list2.begin(), list2.end(), std::back_inserter(v));
   return v;

}


int main()
{
    vector<int> array={
        3,5,6,1,4,6
    };
    int target=6;
  vector<int> ans2;
   
  ans2=linearSearchAllIndexList2(array,6,0);

    for ( int i = 0; i < ans2.size(); i++)
    {
       cout<<ans2[i]<<" ";
    }
     
    
    return 0;
}