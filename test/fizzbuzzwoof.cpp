#include<iostream>
using namespace std;

int main()
{ int N;
  cin>>N;
  int f=0;

  for (int i=1;i<=N;i++)
  { f=0;
  if(i%3==0) {cout<<"fizz",f=1;}
  if(i%5==0) {cout<<"buzz",f=1;}
  if(i%7==0) {cout<<"woof",f=1;}

  if(f==0) cout<<i;
  cout<<endl;
  }
}
