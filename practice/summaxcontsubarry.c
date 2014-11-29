//contigous max sum array
#include<stdio.h>

int max(int x, int y)
{ return (y >= x)? y : x; }

void maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0], i;
   int curr_max = a[0];
   int st=0;
   int count=0;

   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        if(a[i]> curr_max+a[i] ) {st=i;count=0;}
        else count++;
        max_so_far = max(max_so_far, curr_max);

   }
   printf("%d",st);
   printf("%d",count);
   /*
   int j;
   for(j=st;j<=count;j++)
   {printf("%d",a[i]);}
*/
   printf("**%d**",max_so_far);
  // return ;

}

/* Driver program to test maxSubArraySum */
int main()
{
   int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   maxSubArraySum(a, n);
   printf("Maximum contiguous sum is :\n");
   return 0;
}
