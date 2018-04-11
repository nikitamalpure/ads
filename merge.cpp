/*Assignment no:-10
Title:-Assume two input and twp output and perform sorting the internal memory and sort record into external sorting i.e(merge sort)
Class:-SE-B
Batch:-SB-2
Roll no.:-34*/

#include <iostream>

using namespace std;    
int a[50];
void merge(int,int,int);
void merge_sort(int low,int high)
{
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  merge_sort(low,mid);
  merge_sort(mid+1,high);
  merge(low,mid,high);
 }
}
void merge(int low,int mid,int high)
{
 int h,i,j,b[50],k;
 h=low;
 i=low;
 j=mid+1;

 while((h<=mid)&&(j<=high))
 {
  if(a[h]<=a[j])
  {
   b[i]=a[h];
   h++;
  }
  else
  {
   b[i]=a[j];
   j++;
  }
  i++;
 }
 if(h>mid)
 {
  for(k=j;k<=high;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 else
 {
  for(k=h;k<=mid;k++)
  {
   b[i]=a[k];
   i++;
  }
 }
 for(k=low;k<=high;k++) a[k]=b[k];
}
int main()
{
 int num,i;

cout<<"********************************************************";
 cout<<" \n MERGE SORT ";
 cout<<" \n Enter the no of element to be inserted : " ;
 cin>>num;
 cout<<endl;
 cout<<"  Enter the ( "<< num <<" ) numbers ";
 for(i=1;i<=num;i++)
 {
  cin>>a[i] ;
 }
 merge_sort(1,num);
 cout<<endl;
 cout<<"\n sorted list :\n ";
 for(i=1;i<=num;i++)
 cout<<a[i]<<"	\n";
return 0;
}
/*
------------------------------OUTPUT----------------------------------------
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ sort.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out
******************************************************** 
 MERGE SORT  
 Enter the no of element to be inserted : 8

  Enter the ( 8 ) numbers 3
4
2
5
1
6
3
7


 sorted list :
 1	
2	
3	
3	
4	
5	
6	
7	
gescoe@gescoe-OptiPlex-3010:~/Desktop$ 

 */



