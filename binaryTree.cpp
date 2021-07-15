#include <iostream>
#include <stdlib.h>

using namespace std;

void trav();
void createBT();


struct node
{
    int info;
    node *right,*left;
};
node *root=NULL;

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
	cout << "Binary Tree programs "<<endl;
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
        cout << "1. Create a Binary tree"<<endl;
        cout << "2. Traversal of binary tree"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1:createBT();break;
            case 2:trav();break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void trav()
{
	if(root==NULL)
	{
		cout << "Binary tree not present"<<endl;
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
	int a=-1;
	int path[20];
	int pc=0;
	int n=0,t=0;
	while(a!=0)
	{
		if(root==NULL)
		{
			cout << "new binary tree is being created" <<endl;
			node *newnode=new node;
			cout <<"enter the value of first node" << endl;
			cin >> newnode->info;
			newnode->right=NULL;
			newnode->left=NULL;
			root=newnode;
			n=0;
		}
		else
		{
			n++;
			t=n;
			node *temp,*prnt;
			temp=root;
			prnt=root;
			node *newnode = new node;
			cout <<"enter the value of node" << endl;
			cin >> newnode->info;
			newnode->right=NULL;
			newnode->left=NULL;
			while(t!=0)
			{
				if (t%2==0)
					path[pc++]=1;
				else
					path[pc++]=0;
				t=(t-1)/2;
			}
			for (int i=pc-1;i>0;i--)
			{
				if (path[i]==0)
					temp=temp->left;
				if (path[i]==1)
					temp=temp->right;
			}
			pc=0;
			if (path[pc]==0)
				temp->left=newnode;
			if (path[pc]==1)
				temp->right=newnode;
		}
		cout <<"if want to enter the new number to the binary tree press 1, else press 0" << endl;
		cin >> a;
	}
	trav();
}

