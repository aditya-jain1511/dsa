#include <iostream>  
using namespace std; 

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
} 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int array[], int l, int h) 
{ 
    // Select the pivot element
    int pivot = l;
    cout << "pivot: "<<pivot<<":"<<array[pivot]<<endl;
    int k=h;
    for (int i=k;i>=pivot;i--)
    {
        if (array[i] <= array[pivot])
        {
            swap(&array[pivot], &array[i]);
            pivot=i;
            for (int j=l;j<=pivot;j++)
            {
                if (array [j] >= array[pivot])
                {
                    swap(&array[pivot], &array[j]);
                    pivot=j;
                }
            }
        }
    }

    printArray(array, 11);
    cout << "........\n";
    cout << "pivot: "<<pivot<<":"<<array[pivot]<<endl;
    return (pivot); 
} 
  
void quickSortIterative(int arr[], int l, int h) 
{ 
    int s1[h - l + 1]; 
    int s2[h - l + 1];
    int t1 = -1;
    int t2 = -1;
  
    s1[++t1] = l; 
    s2[++t2] = h; 
  
    while (t1 >= 0 || t2 >= 0) { 
        h = s2[t2--]; 
        l = s1[t1--]; 
  
        int p = partition(arr, l, h); 
  
        if (p - 1 > l) 
        { 
            s1[++t1] = l; 
            s2[++t2] = p - 1; 
        } 
  
        if (p + 1 < h) 
        { 
            s1[++t1] = p + 1; 
            s2[++t2] = h; 
        } 
    } 
} 
  

  
int main() 
{ 
    int arr[] = { 11,5,16,22,10,19,2,8,9,25,1}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    quickSortIterative(arr, 0, n - 1); 
    printArray(arr, n); 
    return 0; 
} 
  