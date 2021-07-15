#include <iostream>
#include <stdlib.h>
using namespace std;

void selectSort();
void insertSort();
void bubbleSort();
void qSort();
void mSort();

int main()
{
	system("cls");
	int a=1;
	cout << "sorting programs "<<endl;
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
        cout << "1. Using Selection sort"<<endl;
        cout << "2. Using insertion sort"<<endl;
        cout << "3. Using bubble sort"<<endl;
        cout << "4. Using quick sort"<<endl;
        cout << "5. Using merge sort"<<endl;
        cin >> a;
		switch(a)
		{
            case 0:break;
            case 1: selectSort();break;
            case 2: insertSort();break;
            case 3: bubbleSort();break;
            case 4: qSort();break;
            case 5: mSort();break;
            default:cout<<"enter a valid number!"<<endl;break; 
		}
	}
}

void selectSort()
{
	long int i, j, temp, number[100], n;
	cout << "enter number of elements less than 100: ";
	cin >> n;
	cout << "enter numbers \n";
		for(i=0;i<n;i++)
		{
		    cin >> number[i];
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

void insertSort()  
{  
    int i, temp, j;
    int n;
    cout << "enter number of elements: ";
	cin >> n;
    int arr[n];
    cout << "enter numbers \n"; 
    for (i = 0; i < n; i++)  
        cin >> arr[i];
    cout << "array before sorting "<<endl;

    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;    
      
    for (i = 1; i < n; i++) 
    {  
        temp = arr[i];  
        for (j=i-1;j>=0;j--)
        {
            if (arr[j]>temp)
            {
                arr[j + 1] = arr[j];
                arr[j] = temp;  
            }
        }
    } 

    cout << "array after sorting: "<<endl;
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}

void bubbleSort()
{
	int i, temp, j;
    int n;
    cout << "enter number of elements: ";
	cin >> n;
    int x[n]; 
    cout << "enter numbers \n";
    for (i = 0; i < n; i++)  
        cin >> x[i];
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

/////////////////////////////////////////////////////////////////////////

// Function to swap position of elements
void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to print eklements of an array
void printArray(int array[], int size) 
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

//////////////////////////////////////////////////////////////////////////////
// Function to partition the array on the basis of pivot element

int partition(int array[], int low, int high) 
{
    // Select the pivot element
    int pivot = low;
    int k=high;
    for (int i=k;i>=pivot;i--)
    {
        if (array[i] <= array[pivot])
        {
            swap(&array[pivot], &array[i]);
            pivot=i;
            for (int j=low;j<=pivot;j++)
            {
                if (array [j] >= array[pivot])
                {
                    swap(&array[pivot], &array[j]);
                    pivot=j;
                }
            }
        }
    }

    return (pivot);
}

void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void qSort()
{
    int i;
    int n;
    cout << "enter number of elements: ";
	cin >> n;
    int x[n]; 
    cout << "enter numbers \n";
    for (i = 0; i < n; i++)  
        cin >> x[i];
    quickSort(x, 0, n - 1);
    cout << "Sorted array in ascending order: \n";
    printArray(x, n);
}

//////////////////////////////////////////////////////////////////////////

void merge(int arr[], int l, int m, int r) 
{ 
	int n1 = m - l + 1; //element in left sub array
	int n2 = r - m; //element in right sub array

	int L[n1], R[n2]; // two temporary arrays to stre the two sub arrays 

	for(int i = 0; i < n1; i++) //storing left sub array in temp array L
		L[i] = arr[l + i]; 
	for(int j = 0; j < n2; j++) //storing right sub array in temp array R
		R[j] = arr[m + 1 + j]; 

	int i = 0; 
	int j = 0; 
	int k = l; 
	
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		int m = (l + r)/2; 

		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 

		merge(arr, l, m, r); 
	} 
} 

void mSort()
{
    int i;
    int n;
    cout << "enter number of elements: ";
	cin >> n;
    int arr[n]; 
    cout << "enter numbers \n";
    for (i = 0; i < n; i++)  
        cin >> arr[i];

    mergeSort(arr, 0, n - 1); 
  
    cout << "\nSorted array is \n"; 
    printArray(arr, n);
}