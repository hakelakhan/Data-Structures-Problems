#include <iostream>
#include <utilities.h>
using namespace std;
int maxSubArray(int* a, int n) {
    int mah = 0;
    int msf = 0;
    
    for(int i = 0; i < n; i++) {
        mah = mah + a[i];
        if(mah < a[i]) mah = a[i];
        if(msf < mah) msf = mah;
    }
    return msf;
}
int main() {
    int arr[] = {4,-3, 5, -34 , -31, -6};
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
    cout<<"Maximum subarray sum is " << maxSubArray(arr, n);
    char ch;
    cin>>ch;    
    return 0;
    return 0;
}