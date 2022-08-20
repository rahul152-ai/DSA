#include<iostream>
#include<stdio.h>
using namespace std;
#line 90

int add(int a,int b=10){
    return (a++ + b);
}
int main() {
   int x=10;
   cout<<add(x);
   return 0;
}