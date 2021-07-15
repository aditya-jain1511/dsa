// Quick sort in C++

#include <iostream>
#include <stdlib.h>
using namespace std;

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

// Function to partition the array on the basis of pivot element

int partition(int array[], int low, int high) 
{
    // Select the pivot element
    int pivot = low;
    cout << "pivot: "<<pivot<<":"<<array[pivot]<<endl;
    int k=high;
    for (int i=k;i>=pivot;i--)
    {
        if (array[i] <= array[pivot])
        {
            cout << "1"<<endl;
            swap(&array[pivot], &array[i]);
            printArray(array, 8);
            pivot=i;
            for (int j=low;j<=pivot;j++)
            {
                if (array [j] >= array[pivot])
                {
                    cout << "2"<<endl;
                    swap(&array[pivot], &array[j]);
                    printArray(array, 8);
                    pivot=j;
                }
            }
        }
    }

    printArray(array, 8);
    cout << "........\n";
    cout << "pivot: "<<pivot<<":"<<array[pivot]<<endl;
    return (pivot);
}

void quickSort(int array[], int low, int high) 
{
    if (low < high) 
    {
        // Select pivot position and put all the elements smaller 
        // than pivot on left and greater than pivot on right
        int pi = partition(array, low, high);
        cout << "3"<<endl;
        // Sort the elements on the left of pivot
        quickSort(array, low, pi - 1);
        cout << "4"<<endl;
        // Sort the elements on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

// Driver code
int main() 
{
    system("cls");
    cout << "***********************************************"<<endl;
    int data[] = {5, 16, 22, 1, 0, 19, 2, 8};
    int n = sizeof(data) / sizeof(data[0]);
    printArray(data, n);
    quickSort(data, 0, n - 1);
    cout << "Sorted array in ascending order: \n";
    printArray(data, n);
}