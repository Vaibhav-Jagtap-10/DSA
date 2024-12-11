#include <iostream>
#include<ctype.h>
using namespace std;

struct node
{
    char data;
    node *left;
    node *right;
};

class ExpressionTree
{
    int top;
    public:
        node *root, *stack[20];
        ExpressionTree()
        {
            top=-1;
            root=NULL;
        }
        void construct(char exp[30]);
        void inorder(node *);
        void preorder(node *);
        void postorder(node *);
};

void ExpressionTree::construct(char exp[30])
{
    int i;
    node *newnode,*l,*r;
    for(i=0;exp[i]!='\0';i++)
    {
        newnode=new node;
        newnode->left=NULL;
        newnode->right=NULL;
        newnode->data=exp[i];
        if(isalnum(exp[i]))
        {   
            top++;
            stack[top]=newnode;
        }
        else
        {
            r=stack[top];
            top--;
            l=stack[top];
            top--;
            newnode->left=l;
            newnode->right=r;
            top++;
            stack[top]=newnode;
        }
    }
    root=stack[top];
    top--;
}

void ExpressionTree::inorder(node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);
    }
}

void ExpressionTree::preorder(node *ptr)
{
    if(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void ExpressionTree::postorder(node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<" ";
    }
}

int main() 
{
    ExpressionTree e;
    char exp[30];
    int ch;
    do
    {
        cout<<"\n 1. Construct an expression tree";
        cout<<"\n 2. Recursive Traversals";
        cout<<"\n 3. Exit.";
        cout<<"\n enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    cout<<"\n enter postfix expression";
                    cin>>exp;
                    e.construct(exp);
                    break;
            case 2:
                    cout<<"\nRecursive Traversals:\n";
                    cout<<"\n inorder: ";
                    e.inorder(e.root);
                    cout<<"\n preorder ";
                    e.preorder(e.root);
                    cout<<"\n postorder ";
                    e.postorder(e.root);
                    break;
        }
    }while(ch!=3);
     return 0;
}