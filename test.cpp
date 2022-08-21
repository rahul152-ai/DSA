#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> temp){
    for (int i = 0; i < temp.size(); i++)
    {
        cout<<temp[i];
    }
    cout<<endl;
}
int main(){
    vector<int> temp={1,2,3,4,5,6,7,7,8};
    int mid = temp.size()/2;
    
    vector<int> sub_main{temp.begin(),temp.begin()+mid};
    vector<int> sub_main1{temp.begin()+mid,temp.begin()+temp.size()};
    print(sub_main);
    print(sub_main1);
    return 0;
}