#include <iostream>
#include <stdlib.h>
using namespace std;

void arr();
void LL();

struct node
{
    int info;
    node *link;
};
node *start=NULL;
node *last=NULL;

int main()
{
	system("cls");
	int a=1;
	cout << "Queue programs "<<endl;
    void menu(int);
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
        cout << "1. Using Arrays"<<endl;
        cout << "2. Using Linked List"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1:arr();break;
            case 2:LL();break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void arr()
{
    int *c,n=0,i,max,min=0;
	cout << "enter the maximum number of elements to be included in queue: ";
	cin >>max;
    abc:
	cout <<"enter number of elements <= max:";
    cin >> n;
	if (n>max)
	{
		goto abc;
	}
	c = new int [n];//creating a dynamic array
    cout << "elements:"<<endl;
    for (i=0;i<n;i++)
        cin >> c[i];
    for (i=0;i<n;i++)
        cout << c[i] << " ";
    int a=-1;
    while (a!=0)
	{
		cout << "\nEnter a number to perform the following program"<<endl;
		cout << "0. Exit"<<endl;
        cout << "1. insert"<<endl;
        cout << "2. delete"<<endl;
        cout << "3. traverse"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1:void insert(int [], int &,int,int &);insert(c,n,max,min);break;
            case 2:void del(int [], int &,int,int &);del(c,n,max,min);break;
            case 3:void traverse(int [], int &,int,int &);traverse(c,n,max,min);break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void traverse(int x[],int & n,int m,int & l)   //this is to print all the elements of array
{
    int i;
	if (l==m||l==n)
		cout << "Queue is empty"<<endl;
	else
	{
		cout << "\ntransvered array: \n";
    	for (i=l; i< n;i++) // calling all the element to print the elements
			cout << x[i] << " ";
	}
}

void insert(int x[], int & n,int m,int & l)
{
    int num;
	
	if (n==m || n>m)
	{
		cout << "limit of queue reached (OVERFLOW)"<<endl;
		goto noInsert;
	}
    if (n==0)
        cout<<"new queue created"<<endl;
    traverse(x,n,m,l);
    cout << "\nEnter the number : ";
	cin >> num;
    x[n]=num;
    n++;
	noInsert:
    traverse(x,n,m,l);
}

void del(int x[], int & n,int m,int & l)
{
    l++;
    if (l>n || l==m || l==n )
    {
		cout << "Queue is empty"<<endl;
		l=n;
	}
    traverse(x,n,m,l);
}

void LL()
{
    int n,a=-1;
	while (a!=0)
	{
		cout << "\nEnter a number to perform the following program"<<endl;
		cout << "0. Exit"<<endl;
		cout << "1. traversing the linked list"<<endl;
		cout << "2. insertion of element"<<endl;
		cout << "3. delete an element"<<endl;
		cin >> a;

		switch(a)
		{
			case 0:break;
			case 1:void trav();trav();break;
			case 2:void insertL();insertL();break;
			case 3:void delL();delL();break;
			default:cout<<"enter a valid number!"<<endl;break;
		}
	}
}

void trav()
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

void insertL()
{
    node *ptr,*temp;
    ptr=start;
    temp=last;
    if (ptr==NULL)
	{
		cout<<"empty list."<<endl;
        cout <<"enter number: ";
        node *newnode= new node;
        cin >> newnode->info;
        newnode->link=start;
        start=newnode;
        last=newnode;
	}
    else
    {
        cout << "enter number: ";
        node *newnode= new node;
        cin >> newnode->info;
        last->link=newnode;
        newnode->link=NULL;
        last=newnode;
    }
    trav();
}

void delL()
{
	node *ptr;
	ptr=start;
	if (ptr==NULL)
	{
		cout<<"empty list."<<endl;
	}
	else 
	{
		start=start->link;
	}
    trav();
}