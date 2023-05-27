#include<stdio.h>
Main()
{
   int high,low;
   Int target;
}
int binary search(int arr[],int low,int high,int target)
{
  if(high>=low)
{
   int mid=low+(high-low)/2;
   if(arr[mid]==target)
      Return mid;
  if(arr[mid]>target)
      Return binarysearch(arr,low,mid-1,target);
      Return binarysearch(arr,mid+1,high,target);
}
Return -1;
}
