#include <iostream>
#include <stdlib.h>
using namespace std; 

void arr2();
void arrP();
void LL();

struct node
{
    int info,p;
    node *link;
};
node *start=NULL;

int main()
{
	system("cls");
	int a=1;
	cout << "Priority Queue programs "<<endl;
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
        cout << "1. Using Arrays 2D"<<endl;
        cout << "2. Using Arrays parallel"<<endl;
        cout << "3. Using Linked List"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1:arr2();break;
            case 2:arrP();break;
            case 3:LL();break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}
//***************************************************************************************

void arr2()
{
    int n=0,i,max,min=0;
	cout << "enter the maximum number of rows and column to be included in queue: ";
	cin >>max;
	n=max;
    int m=max;
	int **c= new int *[m];
	for (i=0;i<n;i++)
		c[i]= new int[n];
	
	int **index =new int *[m];
	for (i=0;i<m;i++)
		index[i]= new int[2];
	
	for (i=0;i<m;i++)
		for (int j=0;j<2;j++)
		{
			index[i][j]=-1;
		}

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
            case 1:void insert(int **, int &,int ,int,int &,int **);insert(c,n,m,max,min,index);break;
            case 2:void del(int **, int &,int ,int,int &,int **);del(c,n,m,max,min,index);break;
            case 3:void traverse(int **, int &,int ,int,int &,int **);traverse(c,n,m,max,min,index);break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void traverse(int **x,int & n,int m,int max,int & l,int **index)   //this is to print all the elements of array
{
    for (int i=0; i<m; i++)
	{
		int a=index[i][0];
		if (index[i][0]==-1)
		{
			cout << "Priority Queue " << i+1 << " is empty"<<endl;
		}
		else
		{
			int b=index[i][1];
			cout << "element is priority queue "<<i+1<<":"<<endl;
			for (int j=a;j<=b;j++)
			{
				cout << x[i][j] << " ";
			}
			cout <<endl;
		}
		cout << endl;
	}
	
}

void insert(int **x, int & n,int m,int max,int & l,int **index)
{
    traverse(x,n,m,max,l,index);
    int p;
	do
	{
		cout << "Enter the priority. There are total 1 to " << m << " priorities: ";
		cin >> p;//priority
	}while (p>m);

	p--;
	int a,b;
	a=index[p][0];
	b=index[p][1];
	if (b+1==max)
	{
		cout << "limit of queue reached (OVERFLOW)"<<endl;
		goto noInsert;
	}
	if (a==-1)
	{
		cout <<"new queue entry for this priority "<<endl;
		index[p][0]++;
	}
	int num;
	cout <<endl<<"Enter  the number: ";
	cin>>num;
	cout <<endl;
	x[p][b+1]=num;
	index[p][1]++;
	noInsert:
	traverse(x,n,m,max,l,index);
}

void del(int **x, int & n,int m,int max,int & l,int **index)
{
    for (int i=0; i<m; i++)
	{
		int a=index[i][0];
		if (index[i][0]==-1 || index[i][0] > index[i][1])
		{
			continue;
		}
		else
		{
			int b=index[i][1];
			a=++index[i][0];
			break;
		}
		cout << endl;
	}
	traverse(x,n,m,max,l,index);
}
//***************************************************************************************
void arrP()
{
	int n=0,m,i,max,min=0;
	cout << "enter the maximum number of elements to be included in queue: ";
	cin >>max;
	cout << "enter the maximum number of priorities to be included in queue: ";
	cin >>m;
	int *c= new int [n];
	int *p= new	int [n];

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
            case 1:void insP(int *,int *,int &, int, int,int &);insP(c,p,n,m,max,min);break;
            case 2:void delP(int *,int *,int &, int, int,int &);delP(c,p,n,m,max,min);break;
            case 3:void travP(int *,int *,int &, int, int,int &);travP(c,p,n,m,max,min);break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void travP(int *c,int *p,int &n, int m, int max, int &min)
{
	int i;
	if (min==max||min==n)
		cout << "Queue is empty"<<endl;
	else
	{
		cout << "\ntransvered array: \n";
    	for (i=min; i< n;i++) // calling all the element to print the elements
			cout << "num: "<<c[i] << " priority: "<<p[i]<<endl;
	}
}

void insP(int *c,int *p,int &n, int m, int max, int &min)
{
	travP(c,p,n,m,max,min);
	int a,num;
	if (n>=max)
	{
		cout << "limit of queue reached (OVERFLOW)"<<endl;
		goto noInsert;
	}
	if (n==0)
        cout<<"new queue created"<<endl;
	do
	{
		cout << "Enter the priority for which you want to enter the number: ";
		cin>>a;
	}while(a>m);
	cout << "enter the number: ";
	cin>>num;
	if (n==0)
	{
		p[0]=a;
		c[0]=num;
		n++;
	}
	else 
	{
		for (int i=min;i<n;i++)
		{
			if (a>=p[n-1])
			{
				cout <<"0"<<endl;
				p[n]=a;
				c[n]=num;
				n++;
				break;
			}
			else if(a<p[i])
			{
				cout <<"1"<<endl;
				for(int j=n;j>=i;j--)
				{
					c[j]=c[j-1];
					p[j]=p[j-1];
					
					cout <<"2"<<endl;
				}
				p[i]=a;
				c[i]=num;
				n++;
				break;
			}	
		}
	}
	
	noInsert:
	cout << "number of element: "<<n<<endl;
	travP(c,p,n,m,max,min);
}

void delP(int *c,int *p,int &n, int m, int max, int &min)
{
	min++;
    if (min>n || min==max || min==n )
    {
		cout << "Queue is empty"<<endl;
		min=n;
	}
    cout << "beg index: "<<min<<endl;
	cout << "number of element: "<<n<<endl;
	travP(c,p,n,m,max,min);	
}

//***************************************************************************************
void LL()
{
    int n=0,a=-1;
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
			case 1:void travL();travL();break;
			case 2:void insertL(int &);insertL(n);break;
			case 3:void delL(int &);delL(n);break;
			default:cout<<"enter a valid number!"<<endl;break;
		}
	}
}

void travL()
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
			cout <<"Num: " << ptr->info << " priority: "<<ptr->p<<endl;
			ptr=ptr->link;
		}
	}
	cout<<"\n";
}

void insertL(int &n)
{
    node *ptr,*temp;
	int item,flag,loc=0,m;
	ptr=start;
	if (ptr==NULL)
	{
		cout << "node is being added at first location"<<endl;
		node *newNode= new node;
		cout <<"enter the priority: ";
		cin >> newNode->p;
		cout <<"enter the number: ";
		cin >> newNode->info;
		newNode->link=start;
		start=newNode;
		n=1;
		loc++;
	}
	else
	{
		cout <<"enter the priority: ";
		cin >> m;
		cout << "enter the number you want to insert"<<endl;
		cin>> item;
		while(ptr!=NULL)
		{
			if(ptr->p > m)
			{
				node *newNode= new node;
				newNode->info=item;
				newNode->p=m;
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
			if (ptr->p <= m && ptr->link==NULL)
			{
				node *ne=new node;
				ne->info=item;
				ne->p=m;
				ne->link=NULL;
				ptr->link=ne;
				n++;
				break;
			}
			ptr=ptr->link;
		}
		
	}
	cout << "number of element: "<<n<<endl;
    travL();
}

void delL(int &n)
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
    travL();
}