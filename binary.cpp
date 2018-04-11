/***********************************************************
Assignment NO:-A2
Problem Statement:-Beggning with an empty binary search tree by inserting the values in the given order.After constructing a binary tree -
				1. insert a new node
				2. Find number of nodes in longest path 
				3. Minimum data vaue found in a tree
				4. Swapped the pointers 
				5.search a value
NAME:- 
ROLL NO:-
DIV:-B
BATCH:-B2
************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};
treeNode* FindMin(treeNode *node)
{
    if(node==NULL)
    {
        /* There is no element in the tree */
        return NULL;
    }
    if(node->left) 
        return FindMin(node->left);
    else
        return node;
}
treeNode* FindMax(treeNode *node)
{
    if(node==NULL)
    {
        
        return NULL;
    }
    if(node->right) 
        return(FindMax(node->right));
    else
        return node;
}
treeNode *Insert(treeNode *node,int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;

        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
    
    return node;
}
treeNode * Delet(treeNode *node, int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(data < node->data)
    {
        node->left = Delet(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delet(node->right, data);
    }
    else
    {
        
        if(node->right && node->left)
        {
            
            temp = FindMin(node->right);
            node -> data = temp->data;
           
            node -> right = Delet(node->right,temp->data);
        }
        else
        {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); 
        }
    }
    return node;
}
treeNode * Find(treeNode *node, int data)
{
    if(node==NULL)
    {
        /* Element is not found */
        return NULL;
    }
    if(data > node->data)
    {
       
        return Find(node->right,data);
    }
    else if(data < node->data)
    {
       
        return Find(node->left,data);
    }
    else
    {
        /* Element Found */
        return node;
    }
}
void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}
void Preorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    Preorder(node->left);
    Preorder(node->right);
}
void Postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
}
int main()
{
    treeNode *root = NULL,*temp;
    int ch;
    //clrscr();
    while(1)
    {
        cout<<"\n1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.FindMin\n7.FindMax\n8.Search\n9.Exit\n";
        cout<<"Enter ur choice:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\nEnter element to be insert:";
            cin>>ch;
            root = Insert(root, ch);
            cout<<"\nElements in BST are:";
            Inorder(root);
            break;
        case 2:
            cout<<"\nEnter element to be deleted:";
            cin>>ch;
            root = Delet(root,ch);
            cout<<"\nAfter deletion elements in BST are:";
            Inorder(root);
            break;
        case 3:
            cout<<"\nInorder Travesals is:";
            Inorder(root);
            break;
        case 4:
            cout<<"\nPreorder Traversals is:";
            Preorder(root);
            break;
        case 5:
            cout<<"\nPostorder Traversals is:";
            Postorder(root);
            break;
        case 6:
            temp = FindMin(root);
            cout<<"\nMinimum element is :"<<temp->data;
            break;
        case 7:
            temp = FindMax(root);
            cout<<"\nMaximum element is :"<<temp->data;
            break;
        case 8:
            cout<<"\nEnter element to be searched:";
            cin>>ch;
            temp = Find(root,ch);
            if(temp==NULL)
            {
                cout<<"Element is not foundn";
            }
            else
            {
                cout<<"Element "<<temp->data<<" is Found\n";
            }
            break;
        case 9:
            exit(0);
            break;
        default:
            cout<<"\nEnter correct choice:";
            break;
        }
    }
    return 0;
}




/***********OUTPUT**************************
/*gesoe@gesoe-OptiPlex-3010:~$ cd Desktop
gesoe@gesoe-OptiPlex-3010:~/Desktop$ g++ 1.cpp
gesoe@gesoe-OptiPlex-3010:~/Desktop$ ./a.out

1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:1

Enter element to be insert:2

Elements in BST are:2 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:1

Enter element to be insert:5

Elements in BST are:2 5 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:1

Enter element to be insert:3

Elements in BST are:2 3 5 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:1

Enter element to be insert:4

Elements in BST are:2 3 4 5 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:2

Enter element to be deleted:4

After deletion elements in BST are:2 3 5 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:3

Inorder Travesals is:2 3 5 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:4

Preorder Traversals is:2 5 3 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:5

Postorder Traversals is:3 5 2 
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:6

Minimum element is :2
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:7

Maximum element is :5
1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:8

Enter element to be searched:3
Element 3 is Found

1.Insert
2.Delete
3.Inorder
4.Preorder
5.Postorder
6.FindMin
7.FindMax
8.Search
9.Exit
Enter ur choice:9
gesoe@gesoe-OptiPlex-3010:~/Desktop$ 
****************************************/
