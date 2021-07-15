#include <iostream>
using namespace std; 
  
int main()  
{  
    int i, temp, j;
    int arr[] = { 10, 1, 25, 20, 18, 12, 11, 13, 5, 6 };  
    int n = sizeof(arr) / sizeof(arr[0]);
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
    return 0;  
}