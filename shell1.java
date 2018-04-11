/*PROBLEM STATEMENT:-Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data
structure with modularity of programming language.
ROLL NO:-
*/


import java.util.*;
class shell1
{
    void reheapdown(int a[],int n,int i)
    {
        int temp,j;
        while(2*i+1<n)
        {
            j=2*i+1;
             
            if(j+1 < n && a[j+1]> a[j])
             
                j=j+1; 
                if(a[i]>a[j])
                 
                    break;
                 
                else
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    i=j;
                }
        }     
    }
     
    void heap_sort(int a[],int n)
    {
        int i,temp;
        for(i=(n-1)/2;i>=0;i--)
            reheapdown(a,n,i);
         
        while(n>0)
        {
            temp=a[0];
            a[0]=a[n-1];
            a[n-1]=temp;
            n--;
            reheapdown(a,n,0);
        }     
    }     
             
 
    public static void main (String args[])
    {
        int a[]=new int[10];
        int n,i;
        System.out.println("shell Sorting:");
        System.out.println("How many element you want:");
        n = Integer.parseInt(System.console().readLine());
        System.out.println("Enter no of element.");
        for(i=0;i<n;i++)
        {
            a[i]= Integer.parseInt(System.console().readLine());
        }                 
        shell1 obj=new shell1 ();
        obj.heap_sort(a,n);
        System.out.println("The sorted elements are:");
        for(i=0;i<n;i++)
        {
            System.out.println(""+a[i]);
        }
         
         
    }
}

/************OUTPUT**************************
gescoe@gescoe-OptiPlex-3020:~$ cd Desktop
gescoe@gescoe-OptiPlex-3020:~/Desktop$ javac shell1.java
gescoe@gescoe-OptiPlex-3020:~/Desktop$ java shell1
shell Sorting:
How many element you want:
7
Enter no of element.
2
5
4
1
8
7
3
The sorted elements are:
1
2
3
4
5
7
8
gescoe@gescoe-OptiPlex-3020:~/Desktop$ 
************************/
