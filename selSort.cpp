#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	long int i, j, temp, number[100], n;
	system("cls");
	cout << "enter number of elements ";
	cin >> n;
	cout << "enter positive numbers \n";
		for(i=0;i<n;i++)
		{
		cin >> number[i];
		if (number[i] < 0)
		{
			return 0;
		}
		}
		for(i=0;i<n;i++)
		{
			 for(j=i+1;j<n;j++)
			 {
				if(number[i]>number[j])
					{
						temp=number[i];
						number[i]=number[j];
						number[j]=temp;
						}
			 }
		}
	cout << "Sorted elements:";
	for(i=0;i<n;i++)
	 {
	 cout << number[i] <<" ";
	 }
}



/*
#include<stdio.h>
#include<conio.h>
void main()
{
 int i, j, temp, number[5]={8,2,56,55,3};
 clrscr();
printf(" elements: ");
	 for(i=0;i<5;i++)
	printf(" %d",number[i]);
	 for(i=0;i<5;i++)
	 {
			for(j=i+1;j<5;j++)
			{
				 if(number[i]>number[j])
				 {
						temp=number[i];
						number[i]=number[j];
						number[j]=temp;
				 }
			}
	 }
printf("Sorted elements: ");
 for(i=0;i<5;i++)
	printf(" %d",number[i]);
getch();
}

*/