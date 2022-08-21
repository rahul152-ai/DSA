//insertion sort in this sorting algorithm we sort array from left side 
//time complexity of insertion sort is big O n^2;

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

void insertionSort(vector<int>& array,int n){
    for ( int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j>0; j--)
        {
            if (array[j]<array[j-1])
            {
               int temp = array[j];
               array[j] = array[j-1];
               array[j-1] = temp;
            }
            else{
                break;
            }
            
        }
        
    }
    
}

int main(){

    vector<int> array={3,4,1,6,34,0,6};
    int n = array.size();
    print(array,n);
    insertionSort(array,n);
    print(array,n);

    return 0;

}