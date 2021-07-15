#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	long int ammount,total_coin,after_ten,ten_coin,after_five,five_coin,one_coin;
	system("cls");
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
	return 0;
}