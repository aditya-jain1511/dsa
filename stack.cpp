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

int main()
{
	system("cls");
	int a=1;
	cout << "Stack programs "<<endl;
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
    int *c,n=0,i,max;
	cout << "enter the maximum number of elements to be included in stack: ";
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
            case 1:void insert(int [], int &,int );insert(c,n,max);break;
            case 2:void del(int [], int &,int );del(c,n,max);break;
            case 3:void traverse(int [], int &,int );traverse(c,n,max);break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void traverse(int x[],int & n,int m)   //this is to print all the elements of array
{
    int i;
    cout << "\ntransvered array: \n";
    for (i=0; i< n;i++) // calling all the element to print the elements
		cout << x[i] << " ";
}

void insert(int x[], int & n,int m)
{
    int num;
	if (n==m || n>m)
	{
		cout << "limit of stack reached (OVERFLOW)"<<endl;
		goto noInsert;
	}
    if (n==0)
        cout<<"new stack created"<<endl;
    traverse(x,n,m);
    cout << "\nEnter the number : ";
	cin >> num;
    x[n]=num;
    n++;
	noInsert:
    traverse(x,n,m);
}

void del(int x[], int & n,int m)
{
    n--;
    if (n<0)
        n=0;
    traverse(x,n,m);
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
    node *ptr;
	ptr=start;
    if (ptr==NULL)
	{
        cout<<"linked list does not exist"<<endl;
	    cout << "first node is being added"<<endl;
    }
    cout <<"enter the number: ";
	node *newNode= new node;
	cin >> newNode->info;
	newNode->link=start;
	start=newNode;
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