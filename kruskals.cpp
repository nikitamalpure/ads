/*
Group B . 11
You have a business with several offices; you want to lease phone lines to connect them up
with each other; and the phone company charges different amounts of money to connect
different pairs of cities. You want a set of lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate data structures.*/


#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class edgedata
{
   public : 
            char v1;  //v1 is source vertex and 
            char v2; //v2 is destination vertex
            int weight; 
};

class kruskals
{
   public:  
             kruskals() //DEFAULT CONSTRUCTOR
             {
             rcnt=0;
              MSTcost=0;
             }
 
            edgedata a[10];
            edgedata b[10];
            int ecnt;
             int rcnt;  
             int MSTcost;
            void readgraph();
             void displaygraph();
             void calcMST();
             void displayMST();
 
              
};

void kruskals::readgraph()
{

 cout<<"Enter  how many number of edges are there in a graph of vertices\n";
   cin>>ecnt;
   cout<<"Enter the  weight of edges in ascending order\n";
   
   for(int i=1;i<=ecnt;i++)
   {
      cout<<"STARTING VERTEX : ";
      cin>>a[i].v1;
      cout<<"ENDING VERTEX : ";
      cin>>a[i].v2;
      cout<<"Enter weight : ";
      cin>>a[i].weight;
      
   }  

}

void kruskals::displaygraph()
{
 
   cout<<"\nSTARTING VERTEX\t  END VERTEX\t WEIGHT\n";
   
   for(int i=1;i<=ecnt;i++)
   {
      cout<<"   "<<a[i].v1<<"\t"<<"\t  "<<a[i].v2<<"\t\t  "<<a[i].weight;
      cout<<endl;
   }  
      
}

void kruskals::calcMST()
{
   int i=1,j=1;
   int cnt=0;
   b[j].v1=a[i].v1;
   b[j].v2=a[i].v2;
   b[j].weight=a[i].weight;
   rcnt++;
   MSTcost=MSTcost+b[rcnt].weight;
   for(i=2;i<ecnt;i++)
   {
        cnt=0;
        for(j=1;j<=rcnt;j++)
        {
        
             if((b[j].v1==a[i].v1) || (b[j].v2==a[i].v1)|| (b[j].v1==a[i].v2) || (b[j].v2==a[i].v2))
             {
              cnt++;
             }
             
        }
         
           if(cnt!=2)
           {
                rcnt++;
                b[rcnt].v1=a[i].v1;
                 b[rcnt].v2=a[i].v2;
                 b[rcnt].weight=a[i].weight;
                 MSTcost=MSTcost+b[rcnt].weight;
           }
       
    }
 

}  //calcMST close


void kruskals::displayMST()
{  
     cout<<"\n\t THE CALCULATES MST IS : \n";
     for(int i=1;i<=rcnt;i++)
     {
     
       cout<<b[i].v1;
       cout<<" \t"<<b[i].v2;
        cout<<" \t"<<b[i].weight;
        cout<<"\n";
   
     }

}  //close of calcMST


int main()
{
   kruskals obj;
   obj.readgraph();
   cout<<"graph is\n";
   obj.displaygraph();
   obj.calcMST();
   obj.displayMST();
   cout<<"\nTHE TOTAL COST OF MINIMUM SPANNING TREE IS  "<<obj.MSTcost<<"\n";
   return 0;
}



/*
***************  OUTPUT
gescoe@gescoe-OptiPlex-3010:~/SA2-27$ g++ kruskals.cpp
gescoe@gescoe-OptiPlex-3010:~/SA2-27$ ./a.out
Enter  how many number of edges are there in a graph of vertices
5
Enter the  weight of edges in ascending order
STARTING VERTEX : A
ENDING VERTEX : B
Enter weight : 1
STARTING VERTEX : B
ENDING VERTEX : C
Enter weight : 2
STARTING VERTEX : C
ENDING VERTEX : D
Enter weight : 3
STARTING VERTEX : A
ENDING VERTEX : D
Enter weight : 4
STARTING VERTEX : A
ENDING VERTEX : C
Enter weight : 5
graph is

STARTING VERTEX	  END VERTEX	 WEIGHT
   A		  B		  1
   B		  C		  2
   C		  D		  3
   A		  D		  4
   A		  C		  5

	 THE CALCULATES MST IS : 
A 	B 	1
B 	C 	2
C 	D 	3

THE TOTAL COST OF MINIMUM SPANNING TREE IS  6
gescoe@gescoe-OptiPlex-3010:~/SA2-27$ 




*/
