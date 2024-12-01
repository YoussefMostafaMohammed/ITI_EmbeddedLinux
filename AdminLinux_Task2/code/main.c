#include <stdio.h>

int binary_search(int low,int high ,int num,int arr[]){
  if(low>high)return -1;
  int mid=(low+high)/2;
  if(arr[mid]==num)return mid; 
  if(arr[mid]>num)return binary_search(low,mid-1,num,arr);
  else return binary_search(mid+1,high,num,arr);
}

int main(void){
  int arr[12]={2,5,7,11,31,55,62,71,83,99,125,170};
  int num=55,ans=-1;
  ans=binary_search(0,12,num,arr);
  if(ans==-1)printf("Element dosen't Exist :(\n");
  else printf("Element Exist at index %d\n",ans);
  return 0;
}
