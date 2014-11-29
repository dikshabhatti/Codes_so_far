//Solution to
//https://www.hackerrank.com/challenges/the-love-letter-mystery

#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void jumble(string str)
    { int n=str.length();
     int count=0;
      for(int i=0,j=n-1;i<j;i++,j--)
       { if(str[i]!=str[j]){ count += abs(str[i]-str[j]);}
         }
        cout<<count;
    }
int main()
    { int n;
      cin>>n;
      for(int i=0;i<n;i++)
     { string str;
        cin>>str;
        jumble(str);
       cout<<endl;
           
     }
     
     return 0;
    }
    
