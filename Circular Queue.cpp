#include<iostream>
#define maxsize 10
using namespace std;
class queue{
	private:
		int size;
		int arr[maxsize];
		int rare=-1,front=-1;
	public:
		void put_size(int s)
		{
			size=s;
		}
		int isfull()
		{
			if((rare+1)%maxsize==front)
			return 1;
			else
			return 0;
		}
		int isempty()
		{
			if(rare==-1 && front==-1)
			return 1;
			else 
			return 0;
		}
		void enqueue(int x)
		{
			if(isfull())
			{
				cout<<"Queue can't be created";
				return;
			}
			if(rare==-1 && front==-1)
			{
				rare=(rare+1)%maxsize;
				front++;
				arr[rare]=x;
			}
			else
			{
				rare=(rare+1)%maxsize;
				arr[rare]=x;
			}
		}
		void dequeue(int &x)
		{
			if(isempty())
			{
				cout<<"Queue is empty,element can't be deleted";
			}
			if(rare==front)
			{
				x=arr[front];
				front=rare=-1;
			}
			else
			{
				x=arr[front];
				front=(front+1)%maxsize;
			}
		}
		void display()
		{
			if(front<=rare)
			{
				for(int i=front;i<=rare;i++)
				{
					cout<<arr[i]<<" ";
				}
			}
			else
			{
				for(int i=front;i<maxsize;i++)
				{
					cout<<arr[i]<<" ";
				}
				for(int i=0;i<=rare;i++)
				{
					cout<<arr[i]<<" ";
				}
			}
		}
		int first()
		{
		    if(isempty())
		    {
		        cout<<"UnderFlow";
		        exit(1);
		    }
		    else
		    {
		        return arr[front];
		    }
		}
		int last()
		{
		    if(isempty())
		    {
		        cout<<"UnderFlow";
		        exit(1);
		    }
		    else
		    {
		        return arr[rare];
		    }
		}
		void create(int n)
		{
			if(isfull())
			{
				cout<<"Queue can't be created";
				return;
			}
			int x;
			for(int i=1;i<=n;i++)
			{
				cout<<"Enter "<<i<<" element";
				cin>>x;
				enqueue(x);
			}
		}
};
int main()
{
	queue Q;
	int choice,x,n;
    while(1)
    {
    	cout<<endl<<endl<<endl;
    	cout<<"Aryan Jain"<<endl;
    	cout<<"1. Create"<<endl;
    	cout<<"2. Enqueue"<<endl;
    	cout<<"3. Dequeue"<<endl;
    	cout<<"4. Output"<<endl;
    	cout<<"5. Isfull"<<endl;
    	cout<<"6. Isempty"<<endl;
    	cout<<"7. First"<<endl;
    	cout<<"8. Last"<<endl;
    	cout<<"9. Exit"<<endl<<endl<<endl<<endl;
    	cout<<"Enter your choice:";
    	cin>>choice;
    	switch(choice)
    	{
    		case 1:
    			{
    				cout<<"Enter size of queue to form:";
    				cin>>n;
    				Q.create(n);
    				break;
				}
			case 2:
				{
					cout<<"Enter the data to insert: ";
					cin>>x;
					Q.enqueue(x);
					break;
				}
			case 3:
				{
					Q.dequeue(x);
					cout<<"Poped Element:"<<x;
					break;
				}
			case 4:
				{
					Q.display();
					break;
				}
			case 5:
				{
					x=Q.isfull();
					if (x==0)
					cout<<"Space is available to create more elements."<<endl;
					else
					cout<<"Space full."<<endl;
					break;
				}
			case 6:
				{
					x=Q.isempty();
					if(x==0)
					cout<<"Queue is not empty."<<endl;
					else
					cout<<"Queue list is empty."<<endl;
					break;
				}
			case 7:
				{
					x=Q.first();
					cout<<"First element:"<<x;
					break;
				}
			case 8:
				{
					x=Q.last();
					cout<<"Last element:"<<x;
					break;
				}
			case 9:
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
