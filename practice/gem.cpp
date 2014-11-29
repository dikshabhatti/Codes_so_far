//solution to 
//https://www.hackerrank.com/challenges/gem-stones

#include<iostream>
#include<string.h>
using namespace std;

int matchchar(char s[],char ch)
{ int len,i;
  len=strlen(s);
  for(i=0;i<len;i++)
    {
         if(ch==s[i]) return 1;
    }
   return 0;
 }

int main()
{int n,len,flag,count,check;
 count=0;
 char in[100][100];
 cin>>n;
 for(int i=0;i<n;i++)
   { cin>>in[i];}
      
  len=strlen(in[0]);

/*for(int i=0;i<n;i++)
{ cout<<in[i];}*/

  len=strlen(in[0]);
  for(int i=0;i<len;i++)
   {     for(int j=1;j<n;j++)
                {
			flag=matchchar(in[j],in[0][i]);
			if(flag==0) break;
		}
	if(flag==1)
	{ check=0; flag=-1;
	  for(int k=0; k!=i&&k<len ; k++)
		{	if(in[0][i]==in[0][k]){check=1;break;}
		}
	  if(check==0){count++;}

         }
else flag=-1;
}
cout<<count;

return 0;}

