#include <iostream>
#include <stdlib.h>
using namespace std;

void menu(int);
int createLL();
void sort();
void traverse(); 
void search();
void insert(int &);
void insUnsort(int &);
void insSort(int &);
void delElement(int &);
void delEl(int &);
void delLoc(int &);
void del();
void searchUnsort();
void searchSort();

struct node
{
    int info;
    node *link;
};
node *start=NULL;

int main()
{
	system("cls");
	int a=1;
	cout << "Linked List Programs: "<<endl;
	menu(a);
	return 0;
}

void menu(int a)
{
	int n;
	while (a!=0)
	{
		cout << "\nEnter a number to perform the following program"<<endl;
		cout << "0. Exit"<<endl;
		cout << "1. create a new linked list with n elements"<<endl;
		cout << "2. traversing the linked list"<<endl;
		cout << "3. sorting"<<endl;
		cout << "4. search location of element in given linked list"<<endl;
		cout << "5. insertion of element"<<endl;
		cout << "6. delete an element"<<endl;
		cout << "7. delete the whole linked list"<<endl;
		cin >> a;

		switch(a)
		{
			case 0:break;
			case 1:n=createLL();break;
			case 2:traverse();break;
			case 3:sort();break;
			case 4:search();break;
			case 5:insert(n);break;
			case 6:delElement(n);break;
			case 7:del();break;
			default:cout<<"enter a valid number!"<<endl;break;
		}
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
		node *newNode= new node;
		cin >> newNode->info;
		newNode->link=start;
		start=newNode;
	}
	return n;
}

void del()
{
	while (start!=NULL)
	{
		start=start->link;
	}
}

void traverse()
{
	node *ptr;
	ptr=start;
	if (ptr==NULL)
		cout<<"linked list does not exist"<<endl;
	else
	{
		cout<<"linked list: "<<endl;
		while (ptr!=NULL)
		{
			cout << ptr->info << " ";
			ptr=ptr->link;
		}
	}
	cout<<"\n";
}

void search()
{ 
	int a;
	cout <<"1. search an unsorted list\n2. search a sorted list"<<endl;
	cin>>a;
	switch(a)
	{
		case 1:searchUnsort();break;
		case 2:searchSort();break;
		default:cout<<"Enter valid input"<<endl;
	}
}

void searchUnsort()
{
	node *ptr;
	int item,loc=0,flag;
	ptr=start;
	if (ptr==NULL)
		cout<<"empty list."<<endl;
	else
	{
		cout << "enter the number you want to find"<<endl;
		cin>> item;
		while(ptr!=NULL)
		{
			if(ptr->info==item)
			{
				flag=1;
				cout << "item found at location: "<< loc+1 <<endl;
				break;
			}
			loc++;
			ptr=ptr->link;
		}
		if (flag!=1)
			cout<< "item not found"<<endl;
	}
}

void searchSort()
{
	sort();
	node *ptr;
	int item,loc=0,flag;
	ptr=start;
	if (ptr==NULL)
		cout<<"empty list."<<endl;
	else
	{
		cout << "enter the number you want to find"<<endl;
		cin>> item;
		while(ptr!=NULL)
		{
			if(ptr->info==item)
			{
				flag=1;
				cout << "item found at location: "<< loc+1 <<endl;
				break;
			}
			else if (ptr->info>item)
			{
				flag=0;
				break;
			}
			loc++;
			ptr=ptr->link;
		}
		if (flag!=1)
			cout<< "item not found"<<endl;
	}
}

void insert(int &n)
{
	int a;
	cout <<"1. insert in an unsorted list\n2. insert in a sorted list"<<endl;
	cin>>a;
	switch(a)
	{
		case 1:insUnsort(n);break;
		case 2:insSort(n);break;
		default:cout<<"Enter valid input"<<endl;
	}
}

void insUnsort(int &n)
{
	node *ptr;
	int loc,i;
	cout << "enter the position where you want to enter the new element/node: ";
	cin >> loc;
	ptr=start;
	if (loc==1 || ptr==NULL)
	{
		if (ptr==NULL)
			n=1;
		else
			n++;
		cout << "node is being added at first location"<<endl;
		cout <<"enter the number: ";
		node *newNode= new node;
		cin >> newNode->info;
		newNode->link=start;
		start=newNode;
	}
	else if(loc>n)
	{
		int number;
		loc=n;
		cout << "the last node is at "<<n<<" so the next node will be added at "<< n+1<<endl;
		node *newNode=new node;
		node *temp;
		temp=start;
		for (i=0;i<loc-1;i++)
		{
			temp=temp->link;
		}
		cout<<"enter the number you want to insert: ";
		cin>>newNode->info;
		newNode->link=temp->link;
		temp->link=newNode;
		n++;
	}
	else
	{
		node *newNode=new node;
		node *temp;
		temp=start;
		for (i=0;i<loc-2;i++)
		{
			temp=temp->link;
		}
		cout<<"enter the number you want to insert: ";
		cin>>newNode->info;
		newNode->link=temp->link;
		temp->link=newNode;
		n++;
	}
	cout << "number of element: "<<n<<endl;
	traverse();	
}
 
void insSort(int &n)
{
	sort();
	node *ptr,*temp;
	int item,flag,loc=0;
	ptr=start;
	if (ptr==NULL)
	{
		cout << "node is being added at first location"<<endl;
		cout <<"enter the number: ";
		node *newNode= new node;
		cin >> newNode->info;
		newNode->link=start;
		start=newNode;
		n=1;
		loc++;
	}
	else
	{
		cout << "enter the number you want to insert"<<endl;
		cin>> item;
		while(ptr!=NULL)
		{
			if(ptr->info==item || ptr->info > item)
			{
				node *newNode= new node;
				newNode->info=item;
				newNode->link=ptr;
				if (loc==0)
				{
					start=newNode;
					n++;
					break;
				}
				else
				{
					temp->link=newNode;
					n++;
					break;
				}
			}
			loc++;
			temp=ptr;
			if (ptr->info < item && ptr->link==NULL)
			{
				node *ne=new node;
				ne->info=item;
				ne->link=NULL;
				ptr->link=ne;
				n++;
				break;
			}
			ptr=ptr->link;
		}
		
	}
	cout << "number of element: "<<n<<endl;
	traverse();
}

void delElement(int &n)
{
	int a;
	cout <<"1. delete when Location is given\n2. delete when element is given"<<endl;
	cin>>a;
	switch(a)
	{
		case 1:delLoc(n);break;
		case 2:delEl(n);break;
		default:cout<<"Enter valid input"<<endl;
	}
}

void delLoc(int &n)
{
	node *ptr;
	int loc,i;
	ptr=start;
	if (ptr==NULL)
	{
		cout<<"empty list."<<endl;
	}
	else 
	{
		cout << "enter the position where you want to delete ";
		cin >> loc;
		if (loc==1)
		{
			start=start->link;
			n--;
		}
		else
		{
			if (loc>n)
				loc=n;
			cout << "number of elements are only: "<<n<<endl;
			node *temp,*ptr;
			ptr=start;
			for (i=0;i<loc-1;i++)
			{
				temp=ptr;
				ptr=ptr->link;
			}
			temp->link=ptr->link;
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
	ptr=start;
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
			ptr=ptr->link;
		}
		if (flag!=1)
			cout<< "item not found"<<endl;
		else
		{
			node *pt;
			int i;
			pt=start;
			if (pt==NULL)
			{
				cout<<"empty list."<<endl;
			}
			else 
			{
				if (loc==1)
				{
					start=start->link;
					n--;
				}
				else
				{
					if (loc>n)
						loc=n;
					cout << "number of elements are only: "<<n<<endl;
					node *temp,*p;
					p=start;
					for (i=0;i<loc-1;i++)
					{
						temp=p;
						p=p->link;
					}
					temp->link=p->link;
					n--;
				}
			}
			cout << "number of element: "<<n<<endl;
			traverse();
		}
		
	}
}

void sort()
{
	node *ptr,*temp;
	int a;
	ptr=start;
	temp=ptr;
	if (ptr==NULL)
		cout<<"empty list."<<endl;
	else
	{
		while(ptr!=NULL)
		{
			temp=ptr->link;
			while (temp!=NULL)
			{
				if (ptr->info > temp->info)
				{
					a=temp->info;
					temp->info=ptr->info;
					ptr->info=a;
				}
				temp=temp->link;
			}
			ptr=ptr->link;
		}
	}
	traverse();
}