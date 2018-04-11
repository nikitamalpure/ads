/*
 To create ADT that implements the set concepts
 1.add(new element) place a value into the set
 2. remove(element)
 3.contains(element) return true if  element is in collection
 4.size() return number of values in collection iterator() return an iterator
 used to loop over collection.
 5. intersection
 6.union
 7.diff bet 2 sets
 8. subset
 */
#include<iostream>
#include<stdlib.h>

using namespace std;
class stud
{
  int a[10];
  int i,j,pos;
public:

   void intersection(stud o2)
   {
      int n1=pos,n2=o2.pos,ans;
       cout<<"\n intersection is \n";
      for(i=0;i<n1;i++)
      {
	 ans=o2.contains(a[i]);
	 if(ans==1)
	 {
	  cout<<" \n no = "<<a[i];
	 }
     }

   }
       void unionSet(stud o2)
   {
      stud o3;
      int n1=pos,n2=o2.pos,z,ans;
       cout<<"\n union is \n";
      for(i=0;i<n1;i++)
      {
      o3.add(a[i]);
      }
	for(i=0;i<n2;i++)  //o2
	{
	 ans=o3.contains(o2.a[i]);
	 if(ans==0)
	   o3.add(o2.a[i]);
	 }

	cout<<"\n union is ";
	o3.disp();
   }

    void DiffSet(stud o2)
   {
      stud o3;
      int n1=pos,n2=o2.pos,z,ans;
       cout<<"\n Difference is \n";
	for(i=0;i<n2;i++)  //o2
	{
	 ans=o2.contains(a[i]);
	 if(ans==0)
	   o3.add(a[i]);
	 }

	cout<<"\n difference is ";
	o3.disp();
   }

     void SubSet(stud o2)
   {
      stud o3;
      int n1=pos,n2=o2.pos,z,ans;
       cout<<"\n Subset is \n";
	for(i=0,z=0;i<n1;i++)  //o2
	{
	 ans=o2.contains(a[i]);
	 if(ans==0)
	 {
	    z=1;
	    break;
	  }
	 }
	  if(z==0)
	cout<<"\n A is subset of B ";
	else
	cout<<"\n A is NOT a subset of B ";


   }


    stud()
    {
      pos=0;
    }
     int size()
     {
      return(pos);
     }
      void add(int x)
      {
      a[pos]=x;
      pos++;
      }
      int contains(int x)
      {
       for(i=0;i<pos; i++)
       {
	if(a[i]==x)
	  return(1);
       }
       return(0);
      }

      void remove(int x)  ;
	  void disp();
};
 void stud::disp()
 {
  cout<<" \n Array is ";
 for(i=0;i<pos;i++)
 {
  cout<<"\n "<<a[i];

 }

 }

 void stud :: remove(int x)
 {
 int z=0;
   for(i=0;i<pos && a[i]!=x;i++)
 {

 }
 if(i==pos)   // element not found
 {
  z=1;
 }
 for( ; i<pos ;i++)
 {
  a[i]=a[i+1];
 }
 if(z==0) // element found
 pos--;
  disp();
}

int main()
{

int cho,no,ans;
stud obj,o2,o3;
do
{
  cout<<"\n 1. add A \n 2. Add  B \n 3. intersection \n 4. union \n 5. difference\n 6. remove \n 7. contains \n 8. size\n 9. subset ";
  cout<<"\n 10. Exit ";
  cout<<"\n Enter choice ";
  cin>>cho;
  switch(cho)
  {
  case 1: cout<<"\n Enter no : ";
	  cin>>no;
	  obj.add(no);
	  obj.disp();
	  break;
  case 2: cout<<"\n Enter no : ";
	  cin>>no;
	  o2.add(no);
	  o2.disp();
	  break;

 case 3 : obj.intersection(o2);
	  break;
 case 4 : obj.unionSet(o2);
	  break;

 case 5 : obj.DiffSet(o2);
	  break;

  case 6: cout<<"\n Enter no to be deleted : ";
	  cin>>no;
	  obj.remove(no);
	  cout<<"\n after deletion ";
	  obj.disp();
	  break;


 case 7: cout<<"\n Enter no to be search : ";
	  cin>>no;
	 ans= obj.contains(no);
	  if(ans==1)
	    cout<<" \n element found ";
	  else
	     cout<<" \n element NOT found ";

	  break;
 case 8: cout<<"\n size of array is : "<<obj.size();
      break;
 case 9 : obj.SubSet(o2);
	  break;

 case 10:break;
 default: cout<<endl<<" Invalid choice ";
 }

}while(cho!=5);


return(0);
}


/*************OUTPUT******************
gescoe@gescoe-OptiPlex-3020:~$ cd Desktop
gescoe@gescoe-OptiPlex-3020:~/Desktop$ g++ 9.cpp
gescoe@gescoe-OptiPlex-3020:~/Desktop$ ./a.out

 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 1

 Enter no : 1
 
 Array is 
 1
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 1

 Enter no : 2
 
 Array is 
 1
 2
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 1

 Enter no : 3
 
 Array is 
 1
 2
 3
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 2

 Enter no : 1
 
 Array is 
 1
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 2

 Enter no : 2
 
 Array is 
 1
 2
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 2

 Enter no : 3
 
 Array is 
 1
 2
 3
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 2 

 Enter no : 4
 
 Array is 
 1
 2
 3
 4
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 2

 Enter no : 5
 
 Array is 
 1
 2
 3
 4
 5
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 3

 intersection is 
 
 no = 1 
 no = 2 
 no = 3
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 4

 union is 

 union is  
 Array is 
 1
 2
 3
 4
 5
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 6

 Enter no to be deleted : 4
 
 Array is 
 1
 2
 3
 after deletion  
 Array is 
 1
 2
 3
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 7

 Enter no to be search : 5
 
 element NOT found 
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 9

 Subset is 

 A is subset of B 
 1. add A 
 2. Add  B 
 3. intersection 
 4. union 
 5. difference
 6. remove 
 7. contains 
 8. size
 9. subset 
 10. Exit 
 Enter choice 5

 Difference is 

 difference is  
 Array is 
 0gescoe@gescoe-OptiPlex-3020:~/Desktop$ 
********************************/
