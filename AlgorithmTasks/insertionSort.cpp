/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void insertionSort(int a[], int size)
{  
    int i, j, swap;   //assume that the first item is already sorted//
    
    for (i = 1; i < size; i++) {  //i is the second item then the third and so on//
        
        swap = a[i]; //swap is the key which i will compare with other items  
        
        j = i - 1;  //j is the item before the key which i compare together
  
        while(j>=0 && swap <= a[j])  //in case of the key in the array is smaller than the previous item.//  
        {    
            a[j+1] = a[j];  //swap the element, put the smaller first//   
            j = j-1;    
        }    
        a[j+1] = swap;  //Else, shift greater item in the array towards the right//  
    }  
}  
  
void printArr(int a[], int size)   
{  
    for (int i = 0; i < size; i++)  
        cout << a[i] <<" ";  
}  
  
int main()  
{  
    cout << "Enter size of array: " << endl;
    int size;
    cin >> size;
    int a[size];
    
    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }
    // int a[] = { 89, 45, 35, 8, 12, 2 };  
    // int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting array elements are - "<<endl;  
    printArr(a, size);  
    insertionSort(a, size);  
    cout<<"\nAfter sorting array elements are - "<<endl;  
    printArr(a, size);  
  
    return 0;  
}  