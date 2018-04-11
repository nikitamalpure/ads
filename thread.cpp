/**********************************************************
Assignment No:-A7
Problem statement:-Consider a threaded binary tree using using pre-order threads rather than three order sets .
			       Design an algorithm for traversal without using stack and analyse its complexity.

NAME:-
ROLL NO:-
DIV:-
BATCH:-

******************************************************/	

#include<iostream>
#include<stdlib.h>
using namespace std;

class TBTNode
{
	public:
	int data;
	TBTNode *left,*right;
	int lbit,rbit;
	void create();
	void preorder();
	
};
void TBTNode::create()
{
	char ans;
	int flag;
	//TBTNode *Root;
	TBTNode *head;
	TBTNode *node,*temp;
	head=new TBTNode;
	head->left=head;
	head->right=head;
	head->rbit=head->lbit=1;
	TBTNode *Root=new TBTNode;
	//Root=new TBTNode;
	cout<<"\nEnter data for root:";
	cin>>Root->data;
	Root->left=head;
	Root->right=head;
	head->left=Root;
	Root->lbit=Root->rbit=0;
	do
	{
		node=new TBTNode;
		cout<<"\nEnter data:";
		cin>>node->data;
		node->lbit=node->rbit=1;
		temp=Root;
		while(1)
		{
			if(node->data<temp->data)
			{
				if(temp->lbit==1)
				{
					node->left=temp->left;
					node->right=temp;
					temp->lbit=0;
					temp->left=node;
					break;
				}
				else
				temp=temp->left;
			}
			else
			{
				if(temp->rbit==1)
				{
					node->left=temp;
					node->right=temp->right;
					temp->right=node;
					temp->rbit=0;
					break;
				}
				else
				temp=temp->right;
			}
		}
		cout<<"\nDo you want to add more?";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}

void TBTNode::preorder()
{
	TBTNode *temp,*head,*Root;
	int flag=0;
	temp=Root;
	while(temp!=head)
	{
		if(flag==0)
			cout<<temp->data<<" ";
		if(temp->lbit==0 && flag==0)              //go left till lbit is 1
		{
			temp=temp->left;
		}
		else if(temp->rbit==0)                    //go to right by child
		{
			temp=temp->right;
			flag=0;
		}
		else                                       //go to right by thread
		{
			temp=temp->right;
			flag=1;
		}
	}
}
int main()
{
	TBTNode obj;
	obj.create();
	obj.preorder();
	return 0;
}

/********OUTPUT********/
/*gesoe@gesoe-OptiPlex-3010:~$ cd Desktop
gesoe@gesoe-OptiPlex-3010:~/Desktop$ g++ 21.cpp
gesoe@gesoe-OptiPlex-3010:~/Desktop$ ./a.out
Enter data for root:5
Enter data:2
Do you want to add more?y
Enter data:4
Do you want to add more?y
Enter data:3
Do you want to add more?y
Enter data:8
Do you want to add more?y
Enter data:6
Do you want to add more?n
5 0 2 4 3 8 gesoe@gesoe-OptiPlex-3010:~/Desktop$ 
**************************************************/


