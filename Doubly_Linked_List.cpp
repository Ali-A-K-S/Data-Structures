#include<iostream>
#include<conio.h>
using namespace std;
struct NODE
{
	int info;
	NODE* next;
	NODE* prev;
};

class dbly_LkdList
{
		NODE *head, *tail;
		bool isEmpty()
			{
				if(head==NULL)
				{
					cout<<"\n\t(list is Empty)";
					return true;
				}
				else return false;
			}
	public:
		dbly_LkdList()
		{
			head=tail=NULL;
		}
		void insrtAtStart()
		{
			NODE* n= new NODE;
			cout<<"\n\nENTER an Integer>> ";
			cin>>n->info;
			n->next=NULL;
			n->prev=NULL;
			
			if(head==NULL)
				head=tail=n;
			else
			{
				n->next   =head;
				head->prev=n;
				head      =n;
			}
		}
		void deleteFromStart()
		{
			if(!isEmpty() )
			{
				NODE* crt= head;
				cout<<"\n\t***Node Deleted***"
					<<"\nDeleted Integer: "<<crt->info;
				if(head==tail)
					head=tail=NULL;
				else
				{
					head= head->next;
					head->prev= NULL;
				}
				delete crt;
			}
		}
		void insertAtEnd()
		{
			NODE* n= new NODE;
			cout<<"\n\nENTER an Integer>> ";
			cin>>n->info;
			n->next=NULL;
			n->prev=NULL;
			
			if(head==NULL)
				head=tail=n;
			else
			{
				n->prev   = tail;
				tail->next= n;
				tail= n;
			}
		}
		void deleteFromEnd()
		{
			if(!isEmpty() )
			{
				NODE* crt= tail;
				cout<<"\n\t***Node Deleted***"
					<<"\nDeleted Integer: "<<crt->info;
				if(head==tail)
					head=tail=NULL;
				else
				{
					tail= tail->prev;
					tail->next= NULL;
				}
				delete crt;
			}			
		}
};
main()
{
	char optn;
	dbly_LkdList obj;
	MENU:
	cout<<"\n\n"
		<<"\tPRESS  1 to   insertAtStart()\n"
		<<"\t       2 to deleteFromStart()\n"
		<<"\t       3 to   insertAtEnd()\n"
		<<"\t       4 to deleteFromEnd()\n"
		<<"\t       5 to     Exit \n"
		<<"ENTER Choice>> ";
	optn=_getche();
	switch(optn)
	{
		case'1':
			obj.insrtAtStart();
			goto MENU;
			break;
		case'2':
			obj.deleteFromStart();
			goto MENU;
			break;
		case'3':
			obj.insertAtEnd();
			goto MENU;
			break;
		case'4':
			obj.deleteFromEnd();
			goto MENU;
			break;
		case'5':
			exit;
			break;
	}
}
