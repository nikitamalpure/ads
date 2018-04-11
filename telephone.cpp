
	

/*Problem Statement:Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number.
Roll no.:-43
Batch:-SB-2
*/
#include<iostream>
#include<string.h>
using namespace std;

class hashtable
{
    public:
    char name[100];
    long int no;
    hashtable()
    {
        strcpy(name,"null");
    }
};
class user
{
   public:
    hashtable hash[100];
    hashtable p;
    int n;
        
    public:
    int returnval(char x)
    {
      return int(x%16);  
    }  
    int insert()
    {
         int w;
         cout<<"\nenter no os user:";
         cin>>n;
      for(int i=0;i<n;i++)
     {
       char a[100];
       long int b;
      
        int k;
             cout<<"\nenter name:";
             cin>>a;
             cout<<"\nenter no:";
             cin>>b;
         
        char s=a[0];
        k=returnval(s);
        strcpy(p.name,a);
        p.no=b;
        if(strcmp(hash[k].name,"null")==0)
            hash[k]=p;
        else
            for(int j=k;strcmp(hash[j].name,"null")!=0;j++) 
            {
                hash[j]=p;
            }   
            w++;   
      }
      return w;
    }  
    void display(int k)
    {
        int m;
        for(m=0;m<=n;m++)
        {
            if(strcmp(hash[m].name,"null")==0)
            cout<<"\n name-------"<<"  "<<"no-----------\n";
            else
            cout<<hash[m].name<<"  "<<hash[m].no<<"\n";
        }
    } 
    void search(int k)
    {
        int q,i;
        int y=0;
        char a[100];
        cout<<"\n enter name of client";
        cin>>a;
        char s=a[0];
        q=returnval(s);
        if(strcmp(hash[q].name,a)==0)
        {
            cout<<"\n client no is"<<hash[q].no;
            y=1;
        }    
        else
        {
            for(i=q;i<k;i++)
            {
                if(strcmp(hash[i].name,a)==0)
                {
                     cout<<"\n client no is"<<hash[i].no;
                         y=1;
                         break;
                }
            }
        }
        
        if(y==0)
        cout<<"\n client no not found";
        else
        cout<<"\n fount............";
    } 
};
int main()
{
    user c;
    int o;
    o=c.insert();
    c.display(o);
    c.search(o);
    return 0;
}
/*
Output:
gescoe@gescoe-OptiPlex-3010:~$ cd Desktop/
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ tele.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

enter no os user3

enter name:aa

enter no:9167599844

enter name:bb 

enter no:78787578

enter name:cc

enter no:87874683

 name-------  no-----------
aa  9167599844
bb  78787578
cc  87874683

 enter name of clientbb

 client no is:78787578
 fount............gescoe@gescoe-OptiPlex-3010:~/Desktop$ 
*/


