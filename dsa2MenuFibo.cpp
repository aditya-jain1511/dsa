#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
void fibo();
void endfibo();
void digfibo();
void digsumfibo();
void digsumsqfibo();
void factorial();
void jumble_name();
void dynArr();
void productMaxArr();
void moneyEx();

int main()
{
		long int a,b;
		system("cls");
		again:
		cout << "\nselect the number corresponding to the function you want to perform \n";
		cout << "0. Exit \n";
		cout << "1. Fibonnaci series \n";
		cout << "2. last element of Fibonacci series \n";
		cout << "3. last digit of largest Fibonacci number \n";
		cout << "4. last digit of sum of Fibonacci series \n";
		cout << "5. last digit of sum of square of Fibonacci series \n";
		cout << "6. factorial of a given number \n";
		cout << "7. Number of ways a word can be jumbled \n";
		cout << "8. To create and print a dynamic array \n";
		cout << "9. Find the maximum product of two distinct numbers in a sequence of non-negative integers. \n";
		cout << "10. money exchange problem \n";

		cin >> a;
		switch(a)
		{
			case 0: goto ending;
			case 1: fibo(); break;
			case 2: endfibo(); break;
			case 3: digfibo(); break;
			case 4: digsumfibo(); break;
			case 5: digsumsqfibo(); break;
			case 6: factorial(); break;
			case 7: jumble_name(); break;
			case 8: dynArr(); break;
			case 9: productMaxArr(); break;
			case 10: moneyEx(); break;
			default: cout << "\nenter a valid number ";
		}
		end:
		cout << "\ndo you want to continue? press 1 for yes and 0 for no ";
		cin >> b;
		if(b==1)
				goto again;
		else if(b==0)
		{
				ending:
				exit(10);
		}
		else
		{
				cout << "\nenter valid number ";
				goto end;
		}
return 0;
getch();
}


void fibo()
{
	long int i,n,f[45];
	cout << "enter number of elements in series between 0 to 45: ";
	cin >> n;
	if (n > 45)
	{
	cout << "error \n";
	}
	else {
		f[0] = 0;
		f[1] = 1;
		for (i = 2; i < n; i++)
		{
				f[i] = f[i-1] + f[i-2];
		}
		for(i=0;i<n;i++)
		cout<<f[i]<<" ";
}
}

void endfibo()
{
	long int a,b,i,n,k;
		cout << "enter number of elements in series ";
		cin >> n;
		a = -1;
		b = 1;
		for (k = 0; k < n; k++)
		{
				i=b;						
				b=a+b;
				a=i;
		}
		cout << b;
}

void digfibo()
{
	long int a,b,i,n,k;
		cout << "enter number of elements in series ";
		cin >> n;
		a = -1;
		b = 1;
		for (k = 0; k < n; k++)
		{
				i=b;
				b=(a+b)%10;
				a=i;
		}
		cout << b;

}

void digsumfibo()
{
	long int a,b,i,n,k,sum=0;
		cout << "enter number of elements in series ";
		cin >> n;
		a = -1;
		b = 1;
		for (k = 0; k < n; k++)
		{
				i=b;
				b=(a+b)%10;
				a=i;
				sum=(sum+b)%10;
		}
		cout << sum;
}

void digsumsqfibo()
{
	long int a,b,i,n,k,sum=0;
		cout << "enter number of elements in series ";
		cin >> n;
		a = -1;
		b = 1;
		for (k = 0; k < n; k++)
		{
				i=b;
				b=(a+b)%10;
				a=i;
				sum=(sum+(b*b))%10;
		}
		cout << sum;
}

void factorial()
{
	double n,i,fact=1;
	cout << "enter the number you want to find factorial of: ";
	cin >> n;
	for (i=n; i>0; i--)
	{
		fact=fact*i;
	}
	cout << "\nFactorial of number is: " << fact;
}

void jumble_name()
{
	char str[30];
	int len,i,fact=1;
	cout << "enter any word: ";
	cin >> str;
	len=strlen(str);
	cout << "number of letters: " << len << endl;
	for(i=len; i>0 ;i--)
		fact=fact*i;
	cout << "\nNumber of ways in which a word can be jumbled: "<< fact;
}

void dynArr()
{
	int i,n;
    cout<<"enter number of elemets:";
    cin >> n;
	int *a=new int(n);
    cout << "elements:"<<endl;
    for (i=0;i<n;i++)
        cin >> a[i];
    cout << "elements entered: "<<endl;
	for (i=0;i<n;i++)
        cout << a[i] << " ";
}

void productMaxArr()
{
	long int i, j, temp, number[100], n;
	cout << "enter number of elements ";
	cin >> n;
	cout << "enter positive numbers only or the program will end.\n";
		for(i=0;i<n;i++)
		{
		cin >> number[i];
		if (number[i] < 0)
		{
			exit(1);
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
	temp=number[n-1]*number[n-2];
	cout <<"max product for numbers is: \n"<< temp;
}

void moneyEx()
{
	long int ammount,total_coin,after_ten,ten_coin,after_five,five_coin,one_coin;
	cout << "Enter the ammount to be exchanged: ";
	cin >> ammount;
	after_ten= ammount % 10;
	ten_coin = (ammount - after_ten)/10;
	after_five= after_ten % 5;
	five_coin = (after_ten - after_five)/5;
	one_coin = after_five;
	total_coin = ten_coin + five_coin + one_coin;
	cout << "\nMinimum number of Rs.10 coins in denomination: " << ten_coin;
	cout << "\nMinimum number of Rs.5 coins in denomination: " << five_coin;
	cout << "\nMinimum number of Rs.1 coins in denomination: " << one_coin;
	cout << "\nMinimum number of coins in denomination: " << total_coin;
}


