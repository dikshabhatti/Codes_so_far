//continous maximum product in an array
#include<stdio.h>
int min(int x, int y)
{
    return x < y? x : y;
}

int max(int x, int y)
{
    return x > y? x : y;
}

int max_product_subarray(int localarr[], int n)
{
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_value_so_far = 0;

        for (int i = 0; i < n; i++)
    {
       
        if (localarr[i] > 0)
        {
            max_ending_here = max_ending_here*localarr[i];
            min_ending_here = min (min_ending_here * localarr[i], 1);
        }

        else if (localarr[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        else
        {
            int temp = max_ending_here;
            max_ending_here = max (min_ending_here * localarr[i], 1);
            min_ending_here = temp * localarr[i];
        }

        
        if (max_value_so_far <  max_ending_here)
          max_value_so_far  =  max_ending_here;
    }

    return max_value_so_far;
}
int main()
{
int a[] =  {1,2,-3,4};//0 , -5, 0, 2 , 6, -12, 2};//{-1, -3, 4, 0, -2, 1, 0, -3};

   int n = sizeof(a)/sizeof(a[0]);
   int p=max_product_subarray(a, n);
   printf("Maximum contiguous pro is :%d\n",p);
   return 0;
   }
