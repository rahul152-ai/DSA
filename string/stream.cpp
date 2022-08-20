//remove all occurence of a character from a string
#include<iostream>
#include<string>
#include<string.h>
#include <algorithm>
using namespace std;
string removeAllocurence(string str,char c){
    if (str.length()==0)
    {
       return "";
    }

    if (str[0]==c)
    {
        return removeAllocurence(str.substr(1),c);
    }

    else
        return str[0]+removeAllocurence(str.substr(1),c);
    
    

}

//skip a characheter
string skipApple(string up){
    if (up.length()==0)
    {
        return "";
    }
   if (up.find("apple")==0)
   {
      return skipApple(up.substr(5));
   }
   else
     return up[0] + skipApple(up.substr(1));
   
    
    
}
int main()
{
   string str;
   str="Rahulapplekumar";
   

  
  cout<<skipApple("Rahulapplekumar");

    return 0;
}