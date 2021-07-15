#include <iostream>
#include <stdlib.h>
using namespace std;

void del();

struct node
{
    int info,exp;
    node *link,*frnd;
};
node *start=NULL;
node *cstart=NULL;

int main()
{
	system("cls");
	int a=1;
	cout << "Applications of linked list "<<endl;
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
        cout << "1. Frequency of occurence of element is linked list"<<endl;
        cout << "2. Copy linked list with a friend node"<<endl;
        cout << "3. Represent polynomial in form of linked list"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1:void freq();freq();break;
            case 2:void copyLL();copyLL();break;
            case 3:void poly();poly();break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void del()
{
	node *ptr;
	ptr=start;
	if (ptr==NULL)
	{
		cout<<"empty list."<<endl;
	}
	else 
	{
		while (start!=NULL)
	    {
		    start=start->link;
	    }
	}
	if (cstart==NULL)
	{
		cout<<"empty list."<<endl;
	}
	else 
	{
		while (cstart!=NULL)
	    {
			cstart=cstart->link;
	    }
	}
}

void freq()
{
    int i,n,m=0,flag=-1;
	del();
	cout << "enter the number of element: "<<endl;
	cin>> n;
    int arr[n][2];
	cout <<"enter elements: "<<endl;
	for (i=0;i<n;i++)
	{
		node *newNode= new node;
		cin >> newNode->info;
		newNode->link=start;
		start=newNode;
	}
    cout << "Frequency of elements in a given linked list:"<<endl;
    
    for (i=0;i<n;i++)
    {
        arr[i][1]=0;
    }

    node *ptr;
	ptr=start;
	if (ptr==NULL)
		cout<<"linked list does not exist"<<endl;
	else
	{
		while (ptr!=NULL)
		{
            for (i=0;i<m;i++)
            {
                if (ptr->info==arr[i][0])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==0)
            {
                arr[i][1]++;
				flag=-1;
            }
            else
            {
                arr[i][0]=ptr->info;
				arr[i][1]++;
                m++;
            }
            ptr=ptr->link;    
		}
        for (i=0;i<m;i++)
        {
            cout << "number :"<<arr[i][0]<<" freq:"<<arr[i][1]<<endl;
        }
	}
	cout<<"\n";
}

void copyLL()
{
	int i,n,a;
	del();
	cout << "enter the number of element: "<<endl;
	cin>> n;
	node *p[n];

	cout <<"enter elements: "<<endl;
	for (i=0;i<n;i++)
	{
		node *newNode= new node;
		cin >> newNode->info;
		newNode->link=start;
		start=newNode;
		p[n-i-1]=start;
	}

	node *ptr,*temp;
	ptr=start;
	temp=start;

	i=0;
	while (ptr!=NULL)
	{
		cout << "select a friend node "<<i+1<<" between 1 to "<< n<<":";
		cin >> a;
		ptr->frnd=p[a-1];
		ptr=ptr->link;
		i++;
	}
	
	cout << endl;
	temp=start;
	while (temp!=NULL)
	{
		cout << "node: " <<temp->info << " ";
		cout << "friend node: " <<temp->frnd->info<<endl;
		temp=temp->link;
	}

	cout<<endl;
	temp=start;
	for (i=0;i<n;i++)
	{
		cout<<temp->info<<"->"<<temp->frnd->info<<" ; ";
		temp=temp->frnd;
	}
	cout<<endl;
	cout<<endl;
	cout << "cloning the linked list->->-> "<<endl;
	
	ptr=start;
	while(ptr!=NULL)
	{
		node *nn=new node;
		nn->info=ptr->info;
		nn->link=ptr->link;
		ptr->link=nn;
		ptr=ptr->link->link;
	}

	ptr=start;
	while (ptr!=NULL)
	{
		ptr->link->frnd=ptr->frnd->link;
		ptr=ptr->link->link;
	}

	ptr=start;
	cstart=start->link;
	temp=cstart;
	for (i=0;i<n-1;i++)
	{
		ptr->link=ptr->link->link;
		ptr=ptr->link;
		temp->link=temp->link->link;
		temp=temp->link;
	}
	ptr->link=NULL;

	cout<<endl;
	temp=cstart;
	for (i=0;i<n;i++)
	{
		cout<<temp->info<<"->"<<temp->frnd->info<<" ; ";
		temp=temp->frnd;
	}
	cout<<endl;
}

void poly()
{
	del();
	cout <<endl;
	cout << "In this prog we will create a single variable"<<endl;
	cout << "polynomial equation with n degrees using linked"<<endl;
	cout << "list and enter coeff for successive degrees"<<endl;
	cout << "starting from zero."<<endl;

	int i=0;
	cout <<endl<<"enter the highest degree: ";
	int n;
	cin>>n;
	for (i=0;i<=n;i++)
	{
		node *newNode= new node;
		cout << "enter the coeff for X^"<<i<<": ";
		cin >> newNode->info;
		newNode->exp=i;
		newNode->link=start;
		start=newNode;
	}
	i--;

	node *ptr;
	ptr=start;
	cout << "polynomial equation: "<<endl;
	cout << ptr->info <<" X^"<<i<<" ";
	i--;
	ptr=ptr->link;
	while(ptr!=NULL)
	{
		cout << "+ "<< ptr->info <<" X^"<<i<<" ";
		ptr=ptr->link;
		i--;
	}
}

