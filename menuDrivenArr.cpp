#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;
void menu(int [], int &);
void start(int [], int &);

int main() // start of the function by creating a dynamic array for memory management and calling the menu function to create a menu driven program
{
    int i;
	int n;
    int *c;
	system("cls");
    cout << "********************************************************************" << endl;
	cout << "we will create an array and will be performing x of operations on it" << endl;
    cout <<"enter number of elements:";
    cin >> n;
	c = new int [n];//creating a dynamic array
    cout << "elements:"<<endl;
    for (i=0;i<n;i++)
        cin >> c[i];
    for (i=0;i<n;i++)
        cout << c[i] << " ";
    menu(c,n);
	return 0;
	getch();
}
	
void menu(int c[],int & n) // the menu of the whole programs where list of all function can be seen.
{	
	int a,b;
	again:
		cout << "\nselect the x corresponding to the function you want to perform \n";
		cout << "0. Exit \n";
		cout << "1. traversing \n";
		cout << "2. sorting \n";
		cout << "3. linear searching \n";
		cout << "4. binary searching \n";
		cout << "5. insert element in unsorted array \n";
		cout << "6. insert element in sorted array \n";
		cout << "7. delete element whose location is given \n";
        cout << "8. delete a given element from the array \n";
        cout << "9. create an array for unique elements\n";
        cout << "10. create an array for unique sorted elements \n";

		cin >> a;
		switch(a)
		{
			case 0: goto ending;
			case 1: void traverse(int [], int &);traverse(c,n); break;
			case 2: void sort(int [], int &);sort(c,n); break;
			case 3: void linSearch(int [], int &);linSearch(c,n); break;
			case 4: void binSearch(int [], int &);binSearch(c,n); break;
			case 5: void insUnsorted(int [], int &);insUnsorted(c,n); break;
			case 6: void insSorted(int [], int &);insSorted(c,n); break;
			case 7: void delLoc(int [], int &);delLoc(c,n); break;
            case 8: void delElement(int [], int &);delElement(c,n); break;
            case 9: void uniqueArr(int [], int &);uniqueArr(c,n); break;
            case 10: void uniSortArr(int [], int &);uniSortArr(c,n); break;
			default: cout << "\nenter a valid x ";
		}
		end:
		cout << "\ndo you want to continue? press 0 for no, 1 for yes or 2 to create a new array: ";
		cin >> b;
		if(b==1)
				{goto again;}
		else if(b==0)
		{
				ending:
				exit(10);
		}
        else if(b==2)
        {
            start(c,n);
        }
		else
		{
				cout << "\nenter valid x ";
				goto end;
		}
}   

//all arrays are passed as reference in an argument so a change in one 
//function will lead to change in the whole array for the whole function
//that is why there is an option to change the array

void start(int c[], int & n) // crete a new array by overwriting the last one
{
	int i;
	cout <<"enter x of elemets:";
	cin >> n;
	cout << "elements:"<<endl;
	for (i=0;i<n;i++)
        cin >> c[i];
    for (i=0;i<n;i++)
        cout << c[i] << " ";
	menu(c,n);
	//because we know that we can overwrite the elements 
	//in an array and change the number of elements we want to have and print
}

void traverse(int x[],int & n)   //this is to print all the elements of array
{
    int i;
    cout << "\ntransvered array: \n";
    for (i=0; i< n;i++) // calling all the element to print the elements
		cout << x[i] << " ";
}

void sort(int x[],int & n)   // we are using bubble sort program to sort out the array
{
    int i,j,temp;
	traverse(x,n);
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n-1;j++)
		{
        	if(x[j]>x[j+1])
			{
        		temp=x[j];
           		x[j]=x[j+1];
           		x[j+1]=temp;
			}
		}
	}
	cout << "\nSorted elements:\n";
	for(i=0;i<n;i++)
	 {
	 cout << x[i] <<" ";
	 }
}

void linSearch(int x[],int & n) //linear searh
{
	int el,i;
	traverse(x,n);
	cout << "\nenter the element you want to search in the array: ";
	cin >> el;
	for (i=0;i<n;i++)
	{
		if(el==x[i])
		{
			cout << "\nelement exist at location: "<< i+1;
			break;
		}
	}
	if (i==n)
		cout<<"\nelement doesnt exists.";
}

void binSearch(int x[],int & n)	//binary search
{
	int l=0,r,num,m;
	r=n-1;
	sort(x,n);
	cout << "\nEnter the number you want to search: ";
	cin >> num;
	while (l<=r)
	{
		m=(l+r)/2;
		if(x[m]==num)//*checking if the element exists the the middle location because in end after the whole algorithm, this is where we will find it*/
		{
			cout << "element exists at location:" << m+1;
			break;
		}
		else if(x[m]<num)
			l=m+1;
		else if(x[m]>num)
			r=m-1;
		if (l>r)
		{
			cout << "Element doesn't exists.";
			break;
		}
	}

}

void insUnsorted(int x[],int & n)	//insert an element at a given location in an unsorted array
{
	int num,loc,i;
	traverse(x,n);
	cout << "\nThis array contains " << n << " elements.";
	cout << "\nEnter the number (integer) and its location (between 1 to n+1): ";
	cin >> num >> loc;
	for (i=n;i>=loc;i--)
		x[i]=x[i-1];
	x[loc-1]=num;
	n++;
	traverse(x,n);
}
 
void insSorted(int x[],int & n)	// insert in an sorted array
{
	int num,l=0,r,m,loc,i; 
	sort(x,n);
	cout << "\nenter the number you want to enter: ";
	cin >> num;
	r=n-1;
	while (l<=r)
		{
			m=(l+r)/2;
			if (x[m]>=num && x[m-1]<num)/*to check if number already exists or the number we want to insert is smaller than the middle number but larger than the previous number to insert it there*/
			{
				loc=m;
				for (i=n;i>=loc;i--)
				x[i]=x[i-1];
				x[loc]=num;
				n++;
				break;
			}
			else if (x[l]>num)//to insert number at first location
			{
				loc=l;
				for (i=n;i>=loc;i--)
				x[i]=x[i-1];
				x[loc]=num;
				n++;
				break;	
			}
			else if (x[r]<num)// to insert number at last location
			{
				loc=r+1;
				x[loc]=num;
				n++;
				break;
			}
			else if(x[m]<num)
				l=m+1;
			else if(x[m]>num)
				r=m-1;
		}
	traverse(x,n);
}

void delElement(int x[],int & n)		//delete element when element is given
{
	int el,i,m,loc,index,j;
	traverse(x,n);
	cout << "\nenter the element you want to delete in the array: ";
	cin >> el;
	for (i=0;i<n;i++)//linear search for element
	{
		index=0;
		if(el==x[i])
		{
			cout << "\nelement exist at location: "<< i+1;
			index = 1;
			break;
		}
	}
	if (i==n)
		cout<<"\nelement doesnt exists.";

	loc=i;
	if (index==1)
	{
		for (j=loc;j<n-1;j++)//overwriting the succeding numbers over the original number 
		{
			x[j]=x[j+1];
		}
		n--;//reducing the size of array by one
	}
	traverse(x,n);
}

void delLoc(int x[],int & n)	// delete the element when location is given
{
	int loc,j,index=1;
	traverse(x,n);
	while (index==1)
	{cout << "\nEnter the location you want to delete element from: ";	
	cin >> loc;
	loc--;
	if (loc > n-1)
	{
		cout << "enter valid location \n";
	}
	else
	{
		for (j=loc;j<n-1;j++)
		{
			x[j]=x[j+1];
		}
		n--;
		index=0;
	}
	}
	traverse(x,n);
}

void uniqueArr(int x[],int & n)	//create an array with all unique characters. 
{
	int a,i,j,loc,k;
	traverse (x,n);
	cout << "\n select the operation you want to perform: \n";
	cout << "1. delete all the duplicate characters of an existing array\n";
	cout << "2. create a unique array by overwritingt he existing one.\n";
	cin >> a;
	switch(a)
	{
		case 1:
		for (i=0;i<n;i++)//take a reference element to find duplicates
		{
			for (j=i+1;j<n;j++)// run a linear search and delete the duplicates if any there
			{
				if(x[i]==x[j])//deletion process
				{
					for (j;j<n;j++)
					{
						x[j]=x[j+1];
					}
					j=i;
					n--;
				}	
			}
		}
		traverse(x,n);
		break;
		
		case 2:
		cout << "enter number of elements: ";
		cin >> n;
		cin >> x[0];//entering the first element in array to start with
		for (k=1;k<n;k++)
		{
			cin >> x[k];//entering the elements for insertion at last of the series
			for (i=0;i<k;i++)// selecting the fist element and taking it as refernce to find its duplicates
			{
				for (j=i+1;j<=k;j++)// linear search to find duplicates and delete them
				{
					if(x[i]==x[j])//deleting the duplicates
					{
						cout << "element already exists. \n";
						for (j;j<n;j++)
						{
							x[j]=x[j+1];
						}
						j=i;
						k--;//here we are decrementing the entry element rather than n-- (number of elemnts) so the element we want to enter remains same and total number of elements do not decrease
					}	
				}
			}
		}	
		traverse(x,n);
		break;
		
		default: cout << "\nshould have entered a valid number ." << endl;
	}
}

void uniSortArr(int x[],int & n)   //create an array with all unique characters
{
	int a,i,j,loc,k;
	traverse (x,n);
	cout << "\n select the operation you want to perform: \n";
	cout << "1. delete all the duplicate characters of an existing array\n";
	cout << "2. create a unique array by overwritingt he existing one.\n";
	cin >> a;
	switch(a)
	{
		case 1:
		{
		sort(x,n);
		for (i=0;i<n;i++)// take the reference element to check for duplicates
		{
			for (j=i+1;j<n;j++)// run a linear search for duplicate items
			{
				if(x[i]==x[j])// delete the duplicate items
				{
					for (j;j<n;j++)
					{
						x[j]=x[j+1];
					}
					j=i;
					n--;
				}	
			}
		}
		traverse(x,n);
		break;
		}
		case 2:
		{
		cout << "enter number of elements: ";
		cin >> n;
		int ind=1;
		cin >> x[0]; //entering the first element in array to start with
		for (k=1;k<n;k++)
		{
			int num,l=0,r,m,loc,i;
			r=ind-1;
			cin >> num;
			while (l<=r)
			{
				m=(l+r)/2;
				if(x[m]==num)
				{
					cout << "element already exists"<<endl;
					k--;
					break;
				}
				else if (x[m]>num && x[m-1]<num)/*to check if number already exists or the number we want to insert is smaller than the middle number but larger than the previous number to insert it there*/
				{
					loc=m;
					for (i=n;i>=loc;i--)
					x[i]=x[i-1];
					x[loc]=num;
					ind++;
					break;
				}
				else if (x[l]>num)//to insert number at first location
				{
					loc=l;
					for (i=n;i>=loc;i--)
					x[i]=x[i-1];
					x[loc]=num;
					ind++;
					break;	
				}
				else if (x[r]<num)// to insert number at last location
				{
					loc=r+1;
					x[loc]=num;
					ind++;
					break;
				}
				else if(x[m]<num)
					l=m+1;
				else if(x[m]>num)
					r=m-1;
			}
		}
		traverse(x,n);
		break;
		}
		default: cout << "\nshould have entered a valid number ." << endl;
	}
}