#include <iostream>
#include <conio.h>
using namespace std;
int main() 
{
    int i,n;
    system("cls");
    cout<<"enter number of elemets:";
    cin >> n;
	int *a=new int(n);
    cout << "elements:"<<endl;
    for (i=0;i<n;i++)
        cin >> a[i];
    for (i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
    getch();
}