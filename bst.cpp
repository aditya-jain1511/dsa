#include <iostream>
#include <stdlib.h>

using namespace std;

void trav();
void createBT();
void search();
void insert();
void insertnode(int);
void inordersuc(int);
void del(int);

struct node
{
    int info;
    node *right,*left;
};
node *root=NULL;
node *suc=NULL;

void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout<<p->info<<" ";
        inorder(p->right);
    }
}

void preorder(node *p)
{
    if (p != NULL)
    {
        cout<<p->info<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout<<p->info<<" ";
    }
}

int main()
{
	system("cls");
	int a=1;
	cout << "Binary Search Tree programs "<<endl;
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
        cout << "1. Create a Binary search tree"<<endl;
        cout << "2. Traversal of binary search tree"<<endl;
        cout << "3. Searching in binary search tree"<<endl;
        cout << "4. insertion in binary search tree"<<endl;
        cout << "5. Finding inorder successor in binary search tree"<<endl;
        cout << "6. Deletion in binary search tree"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1:createBT();break;
            case 2:trav();break;
            case 3:search();break;
            case 4:insert();break;
            case 5:
			{
				int num;
				cout << "enter the number you want to find inorder successor of: ";
				cin>>num;
				inordersuc(num);
				break;
			}
            case 6:
			{
				int num;
				cout << "enter the number you want to delete: ";
				cin>>num;
				del(num);
				break;
			}
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void trav()
{
	if(root==NULL)
	{
		cout << "Binary search tree not present"<<endl;
	}
	else
	{	
		cout<<endl<<"printing traversal in inorder\n";
    	inorder(root);
    	cout<<endl<<"printing traversal in preorder\n";
    	preorder(root);
    	cout<<endl<<"printing traversal in postorder\n";
    	postorder(root);
	}
}

void createBT()
{
	root=NULL;
	if (root==NULL)
	{
		cout << "new binary tree is being created" <<endl;
		node *newnode=new node;
		cout <<"enter the value of first node" << endl;
		cin >> newnode->info;
		newnode->right=NULL;
		newnode->left=NULL;
		root=newnode;
	}
	cout << "enter the total number of nodes (>0) to be there in tree: ";
	int n,num;
	cin>> n;
	for (int i=0;i<n-1;i++)
	{
		cout << "enter the value of newnode: ";
		cin>>num;
		insertnode(num);
	}
	trav();
}

void search()
{
	int flag=0;
	if(root==NULL)
	{
		cout << "Binary search tree not present"<<endl;
	}
	else
	{	
		cout << "enter the number you want to search: ";
		int num;
		cin>>num;
		node *temp=root;
		while(temp!=NULL)
		{
			if (temp->info == num)
			{
				cout << "->" << num;
				flag=1;
				break;
			}
			else
			{
				if (num < temp->info)
				{
					cout << "->"<<temp->info;
					temp=temp->left;
				}
				else
				{
					cout << "->"<<temp->info;
					temp=temp->right;
				}
			}
		}
		if (flag != 1)
		{
			insertnode(num);
		}
	}
}

void insert()
{
	cout << "enter the value of newnode: ";
	int num;
	cin>>num;
	insertnode(num);
}

void insertnode(int num)
{
	node *temp=root;
	if (root==NULL)
	{
		cout << "new binary tree is being created" <<endl;
		node *newnode=new node;
		newnode->info=num;
		newnode->right=NULL;
		newnode->left=NULL;
		root=newnode;
	}
	else
	{
		while (temp!=NULL)
		{
			if (temp->info == num)
			{
				cout << "value " << num << " already exists so cannot be added";
				break;
			}
			else
			{
				node *newnode=new node;
				newnode->info=num;
				newnode->right=NULL;
				newnode->left=NULL;
				if (num < temp->info)
				{
					if (temp->left == NULL)
					{
						temp->left=newnode;
						break;
					}
					else 
						temp=temp->left;
				}
				else
				{
					if (temp->right == NULL)
					{
						temp->right=newnode;
						break;
					}
					else 
						temp=temp->right;
				}
			}
		}
	}
}

void inordersuc(int num)
{
	int flag=0;
	suc=NULL;
	if(root==NULL)
	{
		cout << "Binary search tree not present"<<endl;
	}
	else
	{
		int a;
		node *temp=root;
		node *temp1=root;
		while(temp!=NULL)
		{
			if (temp->info == num)
			{
				if (temp==root)
					a=1;
				flag=1;
				break;
			}
			else
			{
				if (num < temp->info)
				{
					suc=temp;
					a=2;
					temp=temp->left;
				}
				else
				{
					temp=temp->right;
					a=1;
				}
			}
		}
		if (flag!=1)
		{
			cout << "element does not exists"<<endl;
		}
		else
		{
			if (a==2)
			{
				if (temp->right!=NULL)
				{
					suc=temp->right;
					temp1=temp->right->left;
					if (temp1!=NULL)
					{
						while(temp1!=NULL)
						{
							suc=temp1;
							temp1=temp1->left;
						}	
					}
				}
			}
			else if (a==1 && temp->right!=NULL)
			{
				suc=temp->right;
				temp1=temp->right->left;
				if (temp1!=NULL)
				{
					while(temp1!=NULL)
					{
						suc=temp1;
						temp1=temp1->left;
					}
				}
			}
			else if(suc==NULL)
			{
				cout << temp->info <<" has no inorder successor"<<endl;
			}
		}
		if(suc!=NULL)
		{
			cout << "inorder successor of "<<temp->info<<" is:"<<suc->info<<endl;
		}
	}
}

void del(int num)
{
	int flag=0;
	if(root==NULL)
	{
		cout << "Binary search tree not present"<<endl;
	}
	else
	{
		int a;
		node *temp=root;
		node *prnt=root;
		while(temp!=NULL)
		{
			if (temp->info == num)
			{
				if (temp==root)
				{
					prnt=root;
					a=1;
				}
				flag=1;
				break;
			}
			else
			{
				if (num < temp->info)
				{
					prnt =temp;
					a=2;
					temp=temp->left;
				}
				else
				{
					prnt=temp;
					temp=temp->right;
					a=1;
				}
			}
		}
		if (flag!=1)
		{
			cout << "element does not exists"<<endl;
		}
		else
		{
			if (temp->left==NULL && temp->right== NULL)
			{
				if(a==1)
					prnt->right=NULL;
				if (a==2)
					prnt->left=NULL;
			}
			else if (temp->left==NULL && temp->right!= NULL)
			{
				if(a==1)
					prnt->right=temp->right;
				if (a==2)
					prnt->left=temp->right;
			}
			else if (temp->left!=NULL && temp->right== NULL)
			{
				if(a==1)
					prnt->right=temp->left;
				if (a==2)
					prnt->left=temp->left;
			}
			else if (temp->left!=NULL && temp->right!= NULL)
			{
				inordersuc(num);
				int a=suc->info;
				del(a);
				cout << "-------------------------------------"<<endl;
				temp->info=a;
			}
		}
	}
	trav();
}
