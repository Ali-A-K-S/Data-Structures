#include<iostream>
#include<conio.h>
using namespace std;

template <class T>

class QUEUE
{
	int front, rear, size, counter;
	int arry[];
	
	public:
		QUEUE()
		{
			size= 10;
			arry[size];
			front= -1;
			rear = -1;
			counter= 0;
		}
		bool isEmpty()
		{
			if(front== -1 && rear==-1)
			{
				cout<<"\n\t(Queue is Empty)";
				return true;
			}
			else return false;
		}
		bool isFull()
		{
			if((rear +1)%size== front)
			{
				cout<<"\n\t(Queue is Full)";
				return true;
			}
			else return false;
		}
		void enqueue()
		{
			if(!isFull() )
			{
				if(front== -1)
					front= 0;
				rear= (rear +1) % size;
				cout<<"\nENTER an Integer in QUEUE>> ";
				cin>>arry[rear];
				++counter;
			}
			else return;
		}
		
		void dequeue()
		{
			if(!isEmpty() )
			{
				int numOfElmt, sum= 0;
				float avg= 0;
				cout<<"\nENTER the Number of Elements you want to Remove>> ";
				cin>>numOfElmt;
				if(numOfElmt <= counter)
				{
					cout<<"\nNumbers Removed from Queue:";
					for(int i=1 ; i<=numOfElmt ;i++)
					{
						cout<<" "<<arry[front];
						sum= sum + arry[front];
						if(front== rear)
						{
							rear = -1;
							front= -1;
						}
						else
							front= (front+1)%size;
						--counter;
					}
					cout<<"\nAverage of Numbers Removed: "<<sum/numOfElmt;	
				}			
				else
				{
					cout<<"\t(Not Enough Elements in Queue)";
					return;
				}
			}
			else return;
		}
};

main()
{
	char optn;
	QUEUE<int> obj;
	MENU:
	cout<<"\n\n"
		<<"\tPRESS  1 for Enqueue()\n"
		<<"\t       2 for Dequeue()\n"
		<<"\t       3  to  Exit \n"
		<<"ENTER Choice>> ";
	optn=_getche();
	switch(optn)
	{
		case'1':
			obj.enqueue();
			goto MENU;
			break;
		case'2':
			obj.dequeue();
			goto MENU;
			break;
		case'3':
			exit;
			break;
	}
}
