// no need
#include <iostream>
#include <stdlib.h>

using namespace std;

void trav();
void createAVL();

struct node
{
    int info;
    node *right,*left;
};
node *root=NULL;

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
            case 1:createAVL();break;
            case 2:trav();break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void createAVL()
{
	
}

void trav()
{
    
}