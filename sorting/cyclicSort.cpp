//cyclicSort code ,this is unstable sorting algorithm
//when you see number from (1-n) range using cyclic sort
//time complexity of cyclicSort algorithm is O(n)
//space complexity is O(1)

#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& array,int n){
    for ( int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void cyclicSort(vector<int>& array,int n){
    int i=0;
    while (i<n-1)
    {
        int correctIndex = array[i]-1;
        if (correctIndex!=i)
        {
           int temp = array[correctIndex];
           array[correctIndex] = array[i];
           array[i]=temp;
        }
        else
        {
            i++;
        }
        
        
    }
    
}
int main(){
    vector<int> array ={2,3,5,1,10}; 
    int n=array.size();
    print(array,n);
    cyclicSort(array,n);
    print(array,n);
    return 0;
}