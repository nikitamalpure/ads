
﻿/*
PROBLEM STATEMENT: Write a program on template and exception handling in Java: in this assignment multiple
templates are to be designed as a pattern and these patterns to be used to take decisions.

CLASS: SE-A
BATCH: SA-3 
ROLL NO-68
*/

import java.io.*;
import java.util.Scanner;
class exsp
{
	public static void main(String arg[])
	{
		int a,b,result;
		Scanner input=new Scanner (System.in);
		System.out.println("Input two integers");
		
		a=input.nextInt();
		b=input.nextInt();
		try
		{
			result=a/b;
			System.out.println("Result = "+result);
		}
		catch (ArithmeticException e)
		{
			System.out.println("Exception Caught : Divide by zero");
		}
	}
}
/*
*******************OUTPUT**********************
gescoe@gescoe-OptiPlex-3020:~$ cd Desktop
gescoe@gescoe-OptiPlex-3020:~/Desktop$ javac exsp.java
exsp.java:18: cannot find symbol
symbol  : class ArithmaticException
location: class exsp
		catch (ArithmaticException e)
		       ^
1 error
gescoe@gescoe-OptiPlex-3020:~/Desktop$ javac exsp.java
gescoe@gescoe-OptiPlex-3020:~/Desktop$ java exsp
Input two integers
4
2
Result = 2
gescoe@gescoe-OptiPlex-3020:~/Desktop$ java exsp
Input two integers
3
4
Result = 0
gescoe@gescoe-OptiPlex-3020:~/Desktop$ 


*/
