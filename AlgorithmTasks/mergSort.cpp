/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void mergeAlgo(int arr[], int low, int mid, int high, int size)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    // create swap array witch have the new sorted items //
    int swap[size];

    //in case of the first item in the list <= the middle item and if the first item after the middle one in the list <= the least one
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) { //check if first item in the list <= the first item after the middle one
            
            swap[k] = arr[i]; //if the last condition is true---> put the first item in the original array as the first item in the swap array
            
            i++; //skip the first item in the original array and go to the second then skip the second and go to the third and so on
            
            k++; //skip the first item in the swap array and go to the second then skip the second and go to the third and so on
        }
        else { //do the opesite of what we did above
            
            swap[k] = arr[j]; //put the last item in the original array as the first item in the swap array
            j++;
            k++;
        }
    }
    // Copy the remaining items of first half, if there are any //
    while (i <= mid) {
        swap[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining items of second half, if there are any //
    while (j <= high) {
        swap[k] = arr[j];
        j++;
        k++;
    }

    // Copy the swap array to original array //
    for (int p = low; p <= high; p++) {
        arr[p] = swap[p];
    }
}

//sub-array of arr to be sorted //
void mergeSort(int arr[], int low, int high, int size)
{
    if (low < high) {
        //find middle item//
        int mid = (low + high) / 2;

        //recurcive mergesort first and second halves //
        mergeSort(arr, low, mid, size);
        mergeSort(arr, mid + 1, high, size);

        //merge//
        mergeAlgo(arr, low, mid, high, size);
    }
}

int main(){
    cout << "Enter Array Size: " << endl;
    int size;
    cin >> size;
    int myarray[size];

    cout << "Enter " << size << " integers in any order: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> myarray[i];
    }
    cout << "Before Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }
    cout << endl;
    mergeSort(myarray, 0, (size - 1), size); // mergesort(arr,low,high)

    cout << "After Sorting" << endl;
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }

    return 0;
}
