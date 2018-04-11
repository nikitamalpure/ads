/****************
ASSIGNMENT NO:-
PROBLEM STATEMENT:-Write a program on template and exception handling in Java: in this assignment multiple
                   templates are to be designed as a pattern and these patterns to be used to take decisions.
ROLL NO:-
BATCH:-
DIV:-

****************/
import java.io.*;
import java.util.Scanner;
class exp
{
    public static void main(String[]args)
 {
    int a,b,result;
    
    
     Scanner input=new Scanner(System.in);
     System.out.println("Input two integers");
     
     
     a=input.nextInt();
     b=input.nextInt();
    //try block
      try
      {
         result=a/b;
         System.out.println("Result=" + result);
      }
    //catch block
      catch(ArithmeticException e)
      {
         System.out.println("Exception caught:Division byzero,");
      }
      }              
    }  
    
    
    
/******************************
OUTPUT:-
gescoe@xyz:~$ cd Desktop
gescoe@xyz:~/Desktop$ javac Excep13.java
gescoe@xyz:~/Desktop$ java Excep13
Input two integers
20
10
Result=2
gescoe@xyz:~/Desktop$ 

********************************/

    
