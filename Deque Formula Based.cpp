#include<iostream>
#define maxsize 100
int front=-1;
int rare=-1;
int dq[maxsize];
using namespace std;
int isempty()
{
	if(front==-1 && rare==-1)
	return 1;
	else 
	return 0;
}
int isfull()
{
	if((rare+1)%maxsize==front)
	return 1;
	else 
	return 0;
}
void push_rare(int x)
{
	if(isfull())
	{
		cout<<"Dequeue Full";
		return;
	}
	if(isempty())
	{
		front++;
		rare++;
		dq[rare]=x;
	}
	else
	{
		rare=(rare+1)%maxsize;
		dq[rare]=x;
	}
}
void push_front(int x)
{
	if(isfull())
	{
		cout<<"Dequeue Full";
		return;
	}
	if(isempty())
	{
		front++;
		rare++;
		dq[front]=x;
	}
	else
	{
		if(front==0)
		{
			front=maxsize-1;
			dq[front]=x;
		}
		else
		{
			front=front-1;;
			dq[front]=x;
		}
	}
}
void pop_front(int &x)
{
	if(isempty())
	{
		cout<<"No elements to pop";
		return;
	}
	if(front==rare)
	{
		x=dq[front];
		front=rare=-1;
	}
	else
	{
		x=dq[front];
		front=(front+1)%maxsize;
	}
}
void pop_rare(int &x)
{
	if(isempty())
	{
		cout<<"No elements to pop";
		return;
	}
	if(front==rare)
	{
		x=dq[rare];
		front=rare=-1;
	}
	else
	{
		if(rare==0)
		{
			x=dq[rare];
			rare=maxsize-1;
		}
		else
		{
			x=dq[rare];
			rare=rare-1;
		}
	}
}
void first(int &x)
{
	if(isempty())
	{
		cout<<"No elements";
		return;
	}
	x=dq[front];
	return;
}
void last(int &x)
{
	if(isempty())
	{
		cout<<"No elements";
		return;
	}
	x=dq[rare];
	return;
}
void display()
{
	if(isempty())
	{
		cout<<"No elements";
		return;
	}
	int f=front;
	int r=rare;
	while(f!=r)
	{
		cout<<dq[f]<<" ";
		f=(f+1)%maxsize;
	}
	cout<<dq[r];
}
int main()
{
	int choice,x,n;
    while(1)
    {
    	cout<<endl<<endl<<endl;
    	cout<<"1. push_front"<<endl;
    	cout<<"2. push_rare"<<endl;
    	cout<<"3. pop_front"<<endl;
    	cout<<"3. pop_rare"<<endl;
    	cout<<"5. Output"<<endl;
    	cout<<"6. Isfull"<<endl;
    	cout<<"7. Isempty"<<endl;
    	cout<<"8. First"<<endl;
    	cout<<"9. Last"<<endl;
    	cout<<"10. Exit"<<endl<<endl<<endl<<endl;
    	cout<<"Enter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
    				cout<<"Enter the data to insert: ";
					cin>>x;
					push_front(x);
					break;
				}
			case 2:
				{
					cout<<"Enter the data to insert: ";
					cin>>x;
					push_rare(x);
					break;
				}
			case 3:
				{
					pop_front(x);
					cout<<"Poped Element:"<<x;
					break;
				}
			case 4:
				{
					pop_rare(x);
					cout<<"Poped Element:"<<x;
					break;
				}
			case 5:
				{
					display();
					break;
				}
			case 6:
				{
					x=isfull();
					if (x==0)
					cout<<"Space is available to create more elements."<<endl;
					else
					cout<<"Space full."<<endl;
					break;
				}
			case 7:
				{
					x=isempty();
					if(x==0)
					cout<<"Deque is not empty."<<endl;
					else
					cout<<"Deque list is empty."<<endl;
					break;
				}
			case 8:
				{
					first(x);
					cout<<"First element:"<<x;
					break;
				}
			case 9:
				{
					last(x);
					cout<<"Last element:"<<x;
					break;
				}
			case 10:
				{
					exit(1);
				}
			default:
				{
					cout<<"Invalid choice."<<endl;
				}
		}
	}
	return 0;
}
