#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicate(int *a,int size){
    vector<int> outPut;
    unordered_map<int,bool> map;
    for (int i = 0; i < size; i++)
    {
        if (map.count(a[i])>0)
        {
            continue;
        }
        map[a[i]]=true;
        outPut.push_back(a[i]);
        
    }
    return outPut;
}

int main(){
    int a[]={1,2,3,3,4,4,5,6,2,8};
    vector<int> Output = removeDuplicate(a,10);
    for(int i:Output){
        cout<<i;
    }
    return 0;
}