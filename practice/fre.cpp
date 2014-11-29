//highest frequency element in a string
#include<iostream>
using namespace std;



int main()
{// char s[]= "patatooopatutoo";
    int s[]="1122333321";
//"geeksforgeeks ";
   int* count= new int [256];


   for(int i=0;*(s+i); i++)
   { count[*(s+i)]++;
   }
   for(int i=0;*(s+i); i++)
   { cout<<*(s+i)<<"="<<count[*(s+i)]<<endl;
   }
   int max=0, n=0;
  for(int i=0;*(s+i); i++)
   { cout<<count[*(s+i)];
     if(max<count[*(s+i)]) { max= count[*(s+i)];
	                          n=i;   }

}
cout<<endl<<"max freq"<<max<<"i.e ---"<<s[n];
return 0;

}

/*char str[] = "geeksforgeeks;;;;;";
  // int *count = getCharCountArray(str);
   int *count = new int [256];
   int i;
   for (i = 0; *(str+i);  i++)
      count[*(str+i)]++;
   for (int i = 0; *(str+i);  i++)
  {
  cout<<count[*(str+i)] ;

  }*/













