#include <iostream>
#include <stdlib.h>
using namespace std;

void traverse();

struct node
{
    int info;
    node *forw;
    node *back;
};
node *first=NULL;
node *last=NULL;

void insert(int i) 
{
	node *newnode = new node;
	cin >> newnode->info;
   	newnode->back = NULL;
	newnode->forw = first;
	if (i==0)
	{
		last=newnode;
	}
	else
	{
		first->back=newnode;
	}
	first=newnode;	
}

void del()
{
	while (first!=NULL)
	{
		first=first->forw;
	}
	while (last!=NULL)
	{
		last=last->back;
	}
}

int createLL()
{
	int i,n;
	del();
	cout << "enter the number of element: "<<endl;
	cin>> n;
	cout <<"enter elements: "<<endl;
	for (i=0;i<n;i++)
	{
		insert(i);
	}
	traverse();
	return n;
}

void traverse()
{
	node *ptr;
	ptr=first;
	if (ptr==NULL)
		cout<<"forward list does not exist"<<endl;
	else
	{
		cout<<"forward list: "<<endl;
		while (ptr!=NULL)
		{
			cout << ptr->info << " ";
			ptr=ptr->forw;
		}
	}
	cout<<"\n";
}

void insertion(int &n)
{
	node *ptr;
	int loc,i;
	cout << "enter the position where you want to enter the new element/node: ";
	cin >> loc;
	ptr=first;
	if (loc==1 || ptr==NULL)
	{
		cout << "node is being added at first location"<<endl;
		cout <<"enter the number: ";
		node *newnode = new node;
		cin >> newnode->info;
   		newnode->back = NULL;
		newnode->forw = first;
		if (n==0)
		{
			last=newnode;
		}
		else
		{
			first->back=newnode;
		}
		first=newnode;
		n++;
	}
	else if(loc>n)
	{
		loc=n;
		cout << "the last node is at "<<n<<" so the next node will be added at "<< n+1<<endl;
		node* newnode = new node;
		cout <<"enter the number: ";
		cin >> newnode->info;
   		newnode->forw = NULL;
		newnode->back = last;
		if (n==0)
		{
			first=newnode;
		}
		else
		{
			last->forw=newnode;
		}
		last=newnode;
		n++;
	}
	else
	{
		node *newNode=new node;
		node *temp;
		temp=first;
		for (i=0;i<loc-2;i++)
		{
			temp=temp->forw;
		}
		cout<<"enter the number you want to insert: ";
		cin>>newNode->info;
		newNode->forw=temp->forw;
		newNode->back=temp;
		(temp->forw)->back=newNode;
		temp->forw=newNode;
		n++;
	}
	cout << "number of element: "<<n<<endl;
	traverse();	
}

void deletion(int &n)
{
	int a;
	cout <<"1. delete when Location is given\n2. delete when element is given"<<endl;
	cin>>a;
	switch(a)
	{
		case 1:void delLoc(int &);delLoc(n);break;
		case 2:void delEl(int &);delEl(n);break;
		default:cout<<"Enter valid input"<<endl;
	}
}

void delLoc(int &n)
{
	node *ptr;
	int loc,i;
	ptr=first;
	if (ptr==NULL)
	{
		cout<<"empty list."<<endl;
	}
	else 
	{
		cout << "enter the position where you want to delete ";
		cin >> loc;
		if (n==1)
		{
			cout << "there is only one element in the list"<<endl;
			del();
			n=0;
		}
		else if (loc==1)
		{
			(first->forw)->back=NULL;
			first=first->forw;
			n--;
		}
		else if(loc>n || loc==n)
		{
			if (loc>n)
				loc=n;
			cout << "number of elements are only: "<<n<<endl;
			(last->back)->forw=NULL;
			last=last->back;
			n--;
		}
		else
		{
			node *ptr;
			ptr=first;
			for (i=0;i<loc-1;i++)
			{
				ptr=ptr->forw;
			}
			(ptr->back)->forw=ptr->forw;
			(ptr->forw)->back=ptr->back;
			n--;
		}
		cout << "number of element: "<<n<<endl;
		traverse();	
	}

}

void delEl(int &n)
{
	node *ptr;
	int item,loc=0,flag;
	ptr=first;
	if (ptr==NULL)
		cout<<"empty list."<<endl;
	else
	{
		cout << "enter the number you want to delete"<<endl;
		cin>> item;
		while(ptr!=NULL)
		{
			if(ptr->info==item)
			{
				flag=1;
				cout << "item found at location: "<< ++loc <<endl;
				break;
			}
			loc++;
			ptr=ptr->forw;
		}
		if (flag!=1)
			cout<< "item not found"<<endl;
		else
		{
			node *pt;
			int i;
			pt=first;
			if (pt==NULL)
			{
				cout<<"empty list."<<endl;
			}
			else 
			{
				if (n==1)
				{
					cout << "there is only one element in the list"<<endl;
					del();
					n=0;
				}
				else if (loc==1)
				{
					(first->forw)->back=NULL;
					first=first->forw;
					n--;
				}
				else if(loc>n || loc==n)
				{
					if (loc>n)
						loc=n;
					cout << "number of elements are only: "<<n<<endl;
					(last->back)->forw=NULL;
					last=last->back;
					n--;
				}
				else
				{
					node *temp,*p;
					p=first;
					for (i=0;i<loc-1;i++)
					{
						temp=p;
						p=p->forw;
					}
					(ptr->back)->forw=ptr->forw;
					(ptr->forw)->back=ptr->back;
					n--;
				}
			}
			cout << "number of element: "<<n<<endl;
			traverse();
		}
		
	}
}

void menu(int a)
{
	int n=0;
	while (a!=0)
	{
		cout << "\nEnter a number to perform the following program"<<endl;
		cout << "0. Exit"<<endl;
        cout << "1. creation"<<endl;
		cout << "2. traverse"<<endl;
        cout << "3. insertion of element"<<endl;
        cout << "4. deletion of element"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1:n=createLL();break;
			case 2:traverse();break;
            case 3:insertion(n);break;
            case 4:deletion(n);break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

int main()
{
	system("cls");
	int a=1;
	cout << "Two Way forwed List Programs: "<<endl;
	menu(a);
	return 0;
}


