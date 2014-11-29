#include<iostream>
#define range 20000
using namespace std;

int main()
{ int a[]={100, 7, 3, 3, 2, 3,1};
  int n=7;
  int occ[range];

  for(int i=0;i<n;i++)
  { occ[i]=-1;}

  for(int i=0;i<n;i++)
  { occ[a[i]]=i;

  }
  int m=0;
  for(int i=0;i<n;i++)
  { if(occ[a[i]]!=-1) m=max((occ[a[i]]-i),m);
  }

  cout<<m;
}
