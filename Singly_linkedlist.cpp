#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*head, *newnode, *pre, *ptr;

void insert_beg(int item)
{
    newnode=new node;
    newnode->data=item;
    newnode->next=head;
    head=newnode;
}

void insert_end(int item)
{
    newnode=new node;
    newnode->data=item;
    if(head==NULL)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}

void insert_loc(int item, int l)
{
    int count=0;
    newnode=new node;
    newnode->data=item;
    if(l==1)
    {
        newnode->next=head;
        head=newnode;
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            count++;
            if(l==count)
            {
                break;
            }
            else
            {
                pre=ptr;
                ptr=ptr->next;
            }
        }
        pre->next=newnode;
        newnode->next=ptr;
    }
}

void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL";
}

void search(int key)
{
    int count=0;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        if(ptr->data==key)
        {
            cout<<key<<"found at the location"<<count;
            break;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    if(ptr==NULL)
    {
        cout<<key<<"not found.";        
    }
}

int main()
{
    int item, l, ch;
    do
    {
        cout<<"\n 1. Insert at beginning.";
        cout<<"\n 2. Insert at end.";
        cout<<"\n 3. Insert at location.";
        cout<<"\n 4. Display";
        cout<<"\n 5. Search an element.";
        cout<<"\n 6. Exit.";
        cout<<"\n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
            cout<<"\n Enter an element to insert at beginning: ";
            cin>>item;
            insert_beg(item);
            break;
            
            case 2: 
            cout<<"\n Enter an element to insert at end: ";
            cin>>item;
            insert_end(item);
            break;
            
            case 3: 
            cout<<"\n Enter an element to insert: ";
            cin>>item;
            cout<<"\n Enter the location at which you want to insert the element: ";
            cin>>l;
            insert_loc(item, l);
            break;
            
            case 4:
            display();
            break;
            
            case 5:
            cout<<"\n Enter an element to search: ";
            cin>>item;
            search(item);
            break;
        }
    }while(ch!=6);
}