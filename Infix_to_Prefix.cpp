#include<iostream>
#include<string.h>
#include<ctype.h>
#include<string>
#include<algorithm>
using namespace std;

struct stack1
{
    char data;
    stack1 *next;
}*top=NULL;

struct stack2
{
    int data;
    stack2 *next;
}*top1=NULL;

int precedence(char op)
{
    if(op=='^')
    {
        return 3;
    }
    
    else if(op=='*'||op=='/')
    {
        return 2;
    }
    
    else if(op=='+'||op=='-')
    {
        return 1;
    }
    
    else 
    {
        return 0;
    }
}

void infixtopre(char infix[50])
{
    stack1 *newnode,*temp;
    int i,l;
    string p;
    i=strlen(infix)-1;
    
    newnode=new stack1;
    newnode->data=')';
    newnode->next=top;
    top=newnode;
    
    infix[-1]='(';
    while(top!=NULL)
    {
        if(infix[i]==')')
        {
             newnode=new stack1;
             newnode->data=')';
             newnode->next=top;
             top=newnode;
        }
        
         else if (infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-'||infix[i]=='^'  )
        {
            while(precedence(top->data)>=precedence(infix[i]))
            {
                p+=top->data;
                temp=top;
                top=top->next;
                delete temp;
            }
            newnode=new stack1;
            newnode->data=infix[i];
            newnode->next=top;
            top=newnode;
        }
        
        else if(infix[i]=='(')
        {
            while(top->data!=')')
            {
                 p+=top->data;
                temp=top;
                top=top->next;
                delete temp;
            }
            temp=top;
            top=top->next;
            delete temp;
        }
        
        else
        {
            p+=infix[i];
        }
        i--;
    }
    cout<<"Prefix expression is :";
    reverse(p.begin(),p.end());
    cout<<p;
}

void evalpre( char p[30])
{
    stack2 *newnode,*temp;
    int a,b,c;
    int i=strlen(p)-1;
    p[-1]='(';
    while(p[i]!='(')
    {
        if(isdigit(p[i]))
        {
            newnode =new stack2;
            newnode->data=p[i]-'0';
            newnode->next=top1;
            top1=newnode;
        }
        
        else
        {
            a=top1->data;
            temp=top1;
            top1=top1->next;
            delete temp;

            b=top1->data;
            temp=top1;
            top1=top1->next;
            delete temp;
            switch(p[i])
            {
                case '+':
                    c=a+b;
                    break;
                
                case '-':
                    c=a-b;
                    break;
                
                case '*':
                    c=a*b;
                    break;
                
                case '/':
                    c=a/b;
                    break;    

            }
            newnode = new stack2;
            newnode->data=c;
            newnode->next=top1;
            top1=newnode;
        }
        i--;    
    }
    cout<<"evaluation of prefx expression is :"<<top->data;
}

int main()
{
    char infix [30],p[30];
    int ch ;
    do {
      
        cout<<"\n 1.infix to prefix ";
        cout<<"\n 2.evaluation of prefix";
        cout<<"\n 3.Exit";
        cout<<"\n Enter your choice";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Enter infix expression: ";
                cin>>infix;
                infixtopre(infix);
                break;
            
            case 2 :
                cout<<"Enter prefix expression:";
                cin>>p;
                evalpre(p);
                break;
            
        }
    }
        while(ch!=3);
}