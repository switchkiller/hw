#include<iostream>
#include<stdlib.h>
using namespace std;
void towerofHanoi(int n, char from, char to, char aux)
{
  if (n == 1)
  {
    cout<<"1 from "<<from<<"-->"<<to;
    return;
  }
  towerofHanoi(n-1,from,aux,to);
  cout<<n<<" from "<<from<<"-->"<<to;
  towerofHanoi(n-1,aux,to,from);
}
int main()
{
    int n=4;
    towerofHanoi(n,'S','D','A');
    return 0;
}
