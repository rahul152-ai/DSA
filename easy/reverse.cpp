#include<iostream>
#include<math.h>
using namespace std;
int reverse = 0;
void reverseNumber(int n){
    if (n==0)
    {
        return;
    }
    int reminder=n%10;
    reverse=reverse*10+reminder;
    reverseNumber(n/10);

}
//using helper function
int helper(int n,int digit){
    if (n%10==n)
    {
       return n;
    }
    int rem=n%10;
    return rem*(int)(pow(10,digit-1))+helper(n/10,digit-1);
    
}

int rev2(int n){
    int digit = (int)log10(n)+1;
    return helper(n,digit);
}

int main(){
    
    cout<<rev2(123);
    return 0;
}