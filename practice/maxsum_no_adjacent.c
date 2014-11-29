//max sum in an array with no adjacent elements
#include<stdio.h>

int FindMaxSum(int arr[], int n)
{
  int incl = arr[0];
  int excl = 0;
  int excl_new;
  int i;

  for (i = 1; i < n; i++)
  {
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl;

     /* current max including i */
     incl = excl + arr[i];
     excl = excl_new;
  }
   return ((incl > excl)? incl : excl);
}


int main()
{
  int arr[] = {-5, -5, -10, -100, 10, 5};
  printf("%d \n", FindMaxSum(arr, 6));
  getchar();
  return 0;
}
