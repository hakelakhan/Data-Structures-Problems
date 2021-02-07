#include <iostream>
#include <utilities.h>
using namespace std;
int partition(int*arr, int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++) {
        if(arr[j] < pivot) {
            i++;
            swap<int>(&arr[j], &arr[i]);
        }
    }
    i++;
    swap<int>(&arr[i], &arr[end]);
    return i;
}
int quickSort(int* arr, int start, int end , int n) {
    if( n > end || start > end) return -999;

    int p = partition(arr, start, end);
    if(p < n) {
        return quickSort(arr, p + 1, end, n);
    }
    else if(p > n) {
        return quickSort(arr, start, p - 1, n);
    }
    else
        return arr[p];
    return 0;    
}
void quickSortOriginal(int* arr, int start, int end) {
    if(start < end) {
        int p = partition(arr, start, end);
        quickSortOriginal(arr, start, p - 1);
        quickSortOriginal(arr, p + 1, end);
    }
}
int getNthSmallestNumber(int* arr, int size, int n) {
    if(n > size) return 0;
    n--;
    return quickSort(arr, 0, size - 1, n);
}
int main() {
    int size = 10;
    int* arr = generateIntRandomArray(size, 1, 100);
    int n;
    printArray<int>(arr, size);
    cout<<"Rank of smallest number you need "<<endl;

    cin>>n;
    
    cout<<n<<"th smallest number in array is "<<getNthSmallestNumber(arr, size, n)<<endl;
    printArray<int>(arr, size);

    waitForKey();
    return 0;
}

