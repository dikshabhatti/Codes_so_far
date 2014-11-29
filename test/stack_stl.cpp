#include<iostream>
#include<stack>

using namespace std;
int exp(string s,int n)
  {std::stack<int> out;


 // int ans=0;

  for(int i=0;i<n;i++)
  { if(s[i]>='0' && s[i]<='9')
       {
           out.push(s[i]-'0');
       }
 else if(s[i]=='+')
      { int a,b;
        if(!out.empty())
          { a=out.top();
            out.pop();
          }
        else return -1;
        if(!out.empty())
          { b=out.top();
            out.pop();
          }
        else return -1;

          a+=b;
          out.push(a);
       }
else if(s[i]=='*')
      { int a,b;
        if(!out.empty())
          { a=out.top();
            out.pop();
          }
        else return -1;
        if(!out.empty())
          { b=out.top();
            out.pop();
          }
        else return -1;

          a*=b;
          out.push(a);
      }

      else return -1;


       }
      if(!out.empty()) {n=out.top();
                         out.pop();}

      if(out.empty()) return n;
      else return-1;




}

int main()
{ string s;
  cin>>s;
  int n=s.length();
  int mn=exp(s,n);
  cout<<mn;
}

