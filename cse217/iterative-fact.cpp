#include<iostream>
using namespace std;
long fact(int n) {
    long x = 1;
    for(int i = 1; i <= n; i++) {
        x *= i;
    }
    return x;
}
int main()
{
  int num;
  cout<<"Enter the number : ";
  cin>>num;
  cout<<" The factorial is : "<<fact(num);
  return 0;  
}
