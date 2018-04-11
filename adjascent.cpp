/**************************************************
Assignment NO:-B9
Problem Statement:-Write a function to get the number of vertices in an undirected graph and its edges. You may
assume that
no edge is input twice.
i.
Use adjacency
list representation of the graph and find runtime of the function
ii.
Use adjacency matrix representation of the graph and find runtime of the function

NAME:-
ROLL NO:-
DIV:-B
BATC:-B2

******************************************************/




#include<iostream>

using namespace std;

class node
{
public : 
         char data;
         node *next;
         
};

class Graph
{
public :
         node *a[5];   
         int mat[10][10];
         char ver[10];     
         int cnt; 

         Graph()
         {
         cnt=0;
         }
         
         void Alist();
         void Amatrix();
         void displayAlist();
         void displayAmatrix();
      
};

void Graph::displayAlist()
{
     node *temp;
     for(int i=0;i<cnt;i++)
     {
          temp=a[i];
          while(temp!=NULL)
          {
               cout<<temp->data<<"->";
               temp=temp->next;
          }
          cout<<" NULL ";
          cout<<"\n";
     }
}
void Graph::displayAmatrix()
{
     for(int i=0;i<cnt;i++)
     {
          cout<<"\t"<<ver[i];
     }
     for(int i=0;i<cnt;i++)
     {
          cout<<"\n"<<ver[i];
          for(int j=0;j<cnt;j++)
          {
               cout<<"\t"<<mat[i][j];
          }
          cout<<"\n";
     }
     
}
void Graph::Alist()
{
   int ncnt;
   node *t,*x;
   
   cout<<"Enter the number of nodes:";
   cin>>cnt;
   
   for(int i=0;i<cnt;i++)
   {
       a[i]=new node();
       a[i]->next=NULL;
       cout<<"\nEnter the head node: ";
       cin>>a[i]->data;
       
       cout<<"\nHow many nodes are attached to "<<a[i]->data<<":";
       cin>>ncnt;
     
       t=a[i];   
          for(int j=0;j<ncnt;j++)
          {
                x=new node();
                x->next=NULL;
                cout<<"\nEnter the nodes attatched to "<<a[i]->data<<":";
                cin>>x->data;
                t->next=x;
                x->next=NULL;
                t=t->next;            
          }       
   }      
} 

void Graph::Amatrix()
{
     cout<<"\n Enter no of vertices:";
     cin>>cnt;
     
     cout<<"Enter the vertices:";
     for(int i=0;i<cnt;i++)
     {
          cin>>ver[i];
     }
     
     cout<<"\nEnter the Adjecency matrix:"<<endl;
     for(int i=0;i<cnt;i++)
     {    
          for(int j=0;j<cnt;j++)
          {
               cout<<"Enter the edge data from "<<ver[i]<<" to "<<ver[j]<<":";
               cin>>mat[i][j];  
               cout<<"\n";
          }
     }
}

int main()
{
     Graph obj;
     
     int ch;
     
     do
     {
     
          cout<<"*************Menu***************";
          cout<<"\n1.Adjecency List \n2.Adjecency Matrix \n3.Exit";
          cout<<"\nEnter your choice:";
          cin>>ch;
          switch(ch)
          {
               case 1:
                    obj.Alist();
                    obj.displayAlist();  
                    break;
               case 2:
                     obj.Amatrix();
                     obj.displayAmatrix();
                     break;
               case 3:
                       cout<<"Exit:";
                       break;
          }         
              
     }while(ch!=3);
     
     return 0;
}

/***********Output**********************
/*gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out
*************Menu***************
1.Adjecency List 
2.Adjecency Matrix 
3.Exit
Enter your choice:1
Enter the number of nodes:3

Enter the head node: 5

How many nodes are attached to 5:2

Enter the nodes attatched to 5:1

Enter the nodes attatched to 5:3

Enter the head node: 4

How many nodes are attached to 4:1

Enter the nodes attatched to 4:0

Enter the head node: 6

How many nodes are attached to 6:3

Enter the nodes attatched to 6:1

Enter the nodes attatched to 6:4

Enter the nodes attatched to 6:7
5->1->3-> NULL 
4->0-> NULL 
6->1->4->7-> NULL 
*************Menu***************
1.Adjecency List 
2.Adjecency Matrix 
3.Exit
Enter your choice:2

 Enter no of vertices:2
Enter the vertices:3
4

Enter the Adjecency matrix:
Enter the edge data from 3 to 3:1

Enter the edge data from 3 to 4:1

Enter the edge data from 4 to 3:0

Enter the edge data from 4 to 4:1

	3	4
3	1	1

4	0	1
*************Menu***************
1.Adjecency List 
2.Adjecency Matrix 
3.Exit
Enter your choice:3
Exit:gescoe@gescoe-OptiPlex-3010:~/Desktop$ 
*************************************/

