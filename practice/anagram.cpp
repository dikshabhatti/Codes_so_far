//solution to
// https://www.hackerrank.com/challenges/make-it-anagram/


#include<iostream>
#include<stdio.h>
#include<cstring>
 
using namespace std;
 
int main()
{
//    char s1[256],s2[256];
    string s1,s2;
    cin>>s1;
    cin>>s2;
 
    int len1=s1.length();
    int len2=s2.length();
 
    int arr1[256]={0}, arr2[256]={0};
 
    for (int i=0; i<len1; i++)
    arr1[s1[i]]++;
 
    for (int i=0; i<len2; i++)
    arr2[s2[i]]++;
 
    for (int i=0; i<256; i++)
    {
        if (arr1[i] && arr2[i])
        {
            if (arr1[i]>arr2[i])
            {
                arr1[i]-=arr2[i];
                arr2[i]=0;
            }
            else
            {
                arr2[i]-=arr1[i];
                arr1[i]=0;
            }
        }
    }
    int count=0;
    for (int i=0; i<256; i++)
    {
        if (arr1[i] || arr2[i])
        count=count+arr1[i]+arr2[i];
 
    }
 
    printf("%d", count);
 
}
