#include<iostream>
#include<string>
#include<vector>
using namespace std;
void subseqence(string p,string up){
    if (up.length()==0)
    {
       
    }
    subseqence(p+up[0],up.substr(1));
    subseqence(p,up.substr(1));
}
//returning a list of substring without creating it in argunment
vector<string> subseqence2(string p, string up){
   
   
    if (up.length()==0)
    {
       vector<string> list;
       list.push_back(p);
       return list;
    }

    vector<string> left = subseqence2(p+up[0],up.substr(1));
    vector<string>right = subseqence2(p,up.substr(1));
    vector<string> ans(left);
     std::copy(right.begin(), right.end(), std::back_inserter(ans));
    
    return ans;
}
int main(){
    std ::string up="abc";
    std ::string p="";
   vector<string> ans2=   subseqence2(p,up);
   for (int i = 0; i < ans2.size(); i++)
   {
       cout<<ans2[i]<<endl;
   }
   

    return 0;
}