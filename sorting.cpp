#include <iostream>
#include <utilities.h>
#include <limits>
using namespace std;
void insertionSort(int* a, int n) {
    //540 45 34 443 35
    //45 540 34 443 443
    for(int i = 1; i < n; i++) {
        int key = a[i]; //34
        int j =  i - 1; 
        for(; j >= 0 && a[j] > key; j--) {
            a[j + 1 ] = a[j];
            //printArray(a, n);
        }
        a[j + 1] = key;
    }
}
void bubbleSort(int* a, int n) {
    for(int i = 0; i < n; i++) {
        
        for(int j = 0; j < n; j++) {
            cout<<"Checking "<<a[i] <<" with "<<a[j]<<endl;
            if(a[i] < a[j]) {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        cout<<"Pass : " <<i<<endl;
        printArray(a, n);
    }
}
void merge(int* a, int start, int mid, int end) {
    
    int l1 = (mid - start) + 1 ;
    int* left = new int[ l1 + 1];
    left[l1] =  std::numeric_limits<int>::max();
    int r1 =  (end - mid);
    int* right = new int[r1 + 1];
    right[r1] = numeric_limits<int>::max();
    int i, j, k;
    for(int i = 0, k = start; i < l1; i++, k++) {
        left[i] = a[k];
    }
    for(int i = 0, k = mid + 1 ; i < r1; i++, k++) {
        right[i] = a[k];
    }
    i = 0;
    j = 0;
    k = start;
    while(k <= end) {
        if(left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    delete left;
    delete right;
}
void divide(int * a, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;
        divide(a, start, mid);
        divide(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}
void mergeSort(int* a, int n) {
    divide(a, 0, n - 1);
}
int main() {
    int arr[] = {454,45, 545, 453, 456, 5};
    int n = 6;
    /*cout<<"How many numbers you want to enter in array"<<endl;
    cin>>n;
    arr = new int[n];
    /*cout<<"Enter numbers   :  ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    */
    cout<<endl<<"You have entered following numbers"<<endl;
    printArray(arr, n);
    cout<<"Merge sort  :  "<<endl;
    mergeSort(arr, n);
    cout<<"After sorting  :  "<<endl;
    printArray(arr, n);    
    char ch;
    cin>>ch;    
    return 0;
}
