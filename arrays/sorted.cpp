//this program print ture if array is sorted else false
#include<iostream>
#include <vector>
using namespace std;
bool sorted(vector<int> &array,int index){
    if (index==array.size()-1)
    {
        return true;
    }
    return array[index]<=array[index+1] && sorted(array,index+1);
    
}
int main(){
    vector<int> array={ 1,3,5,5,9,8};
    if ( sorted(array,0))
    {
        cout<<"ture";
    }
    else
        cout<<"false";
    
    return 0;
}