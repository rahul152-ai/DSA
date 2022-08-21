//time complexity of selection sort is 'O(n square)'
//in the slection sort in frist pass slect greates element from the array put it at the last position;
//in second pass slect the second largest element from the array and put it at the second last positon
//and this process continue till the array not sorted;
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
void slection(vector<int>& array,int n){
    for (int i = 0; i < n; i++)
    {
       int lastIndex = n-1-i;
       int max = 0;
       for ( int j = 0; j < n-i; j++)
       {
          if (array[max]<array[j])
          {
            max = j;
          }
          
       }
       int temp = array[max];
       array[max] = array[lastIndex];
       array[lastIndex] = temp;

       
    }
    
}
int main(){

    vector<int> array={3,4,1,6,34,0,6};
    int n = array.size();
    print(array,n);
    slection(array,n);
    print(array,n);

    return 0;

}