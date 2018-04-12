 /********************************************************
Assignment No A-4
  problem statement:- Read for the formulas in propositional calculus.write a function that reads such a formula &
                    creates its binary tree representation.what is the complexity of your function ?

NAME:- 
ROLL NO:-
DIV:-B
BATCH:-B2

**********************************************************/

#include<iostream>
using namespace std;

#define max 6

class node 
{
public:
      char data;
      node *left;
      node *right;

};


class stack
{
public:
      int top;
      node* elem[max];
      
   stack()
   {
   		top=-1;
   }
   void push(node *t);
   node* pop();
   int isempty();
   int isfull();
};

class etree
{
public:
	node *root;
	etree()
	{
		root=NULL;
	}
   void infix(node *p);
   void  prefix(node *p);
   void  postfix(node *p);
   void create();
   
}; 

void stack::push(node *t)  
{
	node *temp;
   	if(!isfull())
   	{
   			top++;
   
   			elem[top]=t;
   			
 
   	}

   	else
   		cout<<"\n stack is full\n";

} 
node* stack:: pop()   
{
     if(!isempty())
     {
     		return elem[top--];
 	}
   
     else 
  	cout<<"\nstack is empty\n";
 
}


int stack::isempty()
{
   if(top==-1)
   {
   		return(1);
   }
   else
   		return(0);

}


int stack::isfull() 
{  
   if(top==max-1)
   {
   		return (1);
   }
   else
   {
   		return (0);
   }

}
void etree:: infix(node *p)
{
	if(p!=NULL)
	{
		infix(p->left);
		cout<<p->data<<" ";
		infix(p->right);
	}
}
void etree:: prefix(node *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		prefix(p->left);
		prefix(p->right);
		
		
	}
}
void etree:: postfix(node *p)
{
	if(p!=NULL)
	{
		
		
		postfix(p->left);
		postfix(p->right);
		cout<<p->data<<" ";
		
	}
}

void etree::create()
{
	char str[20],ch;
	int i=0;
	node *temp;
	node *lnode;
	node *rnode;
	stack s;
	
	cout<<"\nEnter the postfix expr:";
	cin>>str;
	
	node *newnode;
	
	do
	{
		ch=str[i];
		i++;
		if(ch=='\0')
		{
			break;
		}
		
		if(ch=='-'||ch=='+'||ch=='*'||ch=='/')
		{		
			rnode=s.pop();
			lnode=s.pop();
			
			newnode = new node();
			newnode->right=rnode;
			newnode->left=lnode;
			newnode->data=ch;
			s.push(newnode);
			cout<<"\ntest 2 : "<<newnode->data;		
		}
		else
		{
		
			newnode = new node();
			newnode->left=NULL;
			newnode->right=NULL;
			newnode->data=ch;
			s.push(newnode);
			cout<<"\ntest 1 : "<<newnode->data;
		
		
		}
	}while(ch!='\0');
root=s.pop();
			cout<<"\ntest 3 : "<<root->data;
}	

    int main()
{
	etree e;
	//stack s;
	int c;
	
	do
	{
		cout<<"\n............Expression tree..........";
		cout<<"\n1.Create a Expression tree:";
		cout<<"\n2.Display infix";
		cout<<"\n3. prefix";
		cout<<"\n4.psotfix";
		cout<<"\nEnter ur Choice:";
		cin>>c;
		 switch(c)
		 {
		 	case 1:
		 			//cout<<"\nEnter the Value:";
		 			//cin>>no;
		 			e.create();
		 	break;
		 	
		 	case 2:
		 			e.infix(e.root);
		 	break;
		 	
		 	case 3:
		 			e.prefix(e.root);
		 	break;
		 	
		 	case 4:
		 			e.postfix(e.root);
		 	break;
		 	
	
	
		 }	
	}
		 	while(c!=5);
		 	
	return (0);
}

/**************** OUTPUT *********************
gescoe@gescoe-OptiPlex-3010:~$ cd Desktop
gescoe@gescoe-OptiPlex-3010:~/Desktop$ g++ exp.cpp
gescoe@gescoe-OptiPlex-3010:~/Desktop$ ./a.out

............Expression tree..........
1.Create a Expression tree:
2.Display infix
3. prefix
4.psotfix
Enter ur Choice:1

Enter the postfix expr:abc+*d/

test 1 : a
test 1 : b
test 1 : c
test 2 : +
test 2 : *
test 1 : d
test 2 : /
test 3 : /
............Expression tree..........
1.Create a Expression tree:
2.Display infix
3. prefix
4.psotfix
Enter ur Choice:2       
a * b + c / d 
............Expression tree..........
1.Create a Expression tree:
2.Display infix
3. prefix
4.psotfix
Enter ur Choice:3
/ * a + b c d 
............Expression tree..........
1.Create a Expression tree:
2.Display infix
3. prefix
4.psotfix
Enter ur Choice:4
a b c + * d / 

*******************************************/  

