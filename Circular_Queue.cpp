#include<iostream>
using namespace std;

class CircularQueue
{
	int queue[30],front,rear,n;
	public:
	CircularQueue()
	{
		n=5;
		front=-1;
		rear=-1;
	}
	void enqueue(int data)
	{
		if(front==-1 && rear==-1)
		{
			front=rear=0;
			queue[rear]=data;
		}
		else if((rear+1)%n==front)
		{
			cout<<"Queue is Full";
		}
		else
		{
			rear=(rear+1)%n;
			queue[rear]=data;
		}
	}
	void dequeue()
	{
		if (front==-1)
	   {
	   	cout<<"Underflow";
	   }
	   else if(front==rear)
	   {
	   	front=rear=-1;
	   }
	   else
	   {
	   	cout<<"Deleted Element:"<<queue[front];
	   	front=(front+1)%n;
	   }
	  }
	void display()
	{
		int i=front;
		while(i!=rear)
		{
			cout<<queue[i];
			i=(i+1)%n;
		}
		cout<<queue[rear];
	}
};
int main()
{
	CircularQueue c;
	int q,ch;
	
	do
	{
		cout<<"\n1. Enqueue";
		cout<<"\n2. Dequeue";
		cout<<"\n3. Display";
		cout<<"\n4. Exit";
		cout<<"\n. Enter your choice";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n Enter element in queue";
				     cin>>q;
				     c.enqueue(q);
				     break;
			case 2:
					  c.dequeue();
			        break;
			case 3:
					  c.display();
					  break;
			}
		}while(ch!=4);
}