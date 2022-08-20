//program to print all possible subset of a string using recurrsion
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
void sequence(string p,string up){
   if (up.empty())
   {
      cout<<p<<endl;
      return;
   }
   char ch = up.at(0);
   sequence(p,up.substr(1));
   sequence(p+ch,up.substr(1));
   
}
int main(){
    string str="abc";

   sequence("",str);


    return 0;
}