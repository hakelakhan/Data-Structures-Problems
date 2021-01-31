#include <iostream>
#include <utilities.h>
using namespace std;
int findSum(int* seg, int n, int start ,int end) {
    int segTreeSize = n << 1;
    int sum = 0;
    start = start + n;
    end = end + n;
    if(!validateIndex(start, segTreeSize) || !validateIndex(end, segTreeSize)) return 0;
    while(start <= end) {
        if(start == end) {
            sum += seg[start]; break;
        }
        if((start  & 1) == 1) {
            sum += seg[start];
            start++;
        }
        if((end  & 1) != 1) {
            sum += seg[end];
            end --;
        }
        start = start >> 1;
        end = (end - 1 ) >> 1;
    }
    return sum;
}
int findSumLinear(int* arr, int size, int start, int end) {
    int sum = 0;
    if(!validateIndex(start, size) || !validateIndex(end, size)) return 0;
    
    while(start <= end) {
        sum += arr[start++];
    }
    return sum;
}
int* constructSegTree(int* arr, int n) {
    int* seg;
    int segTreeSize = n << 1;
    seg = new int[ segTreeSize];
    int j = 0;
    for(int i = n; i < segTreeSize; i++, j++) {
        seg[i] = arr[j]; 
    }
    for(int i = n - 1; i > 0; i--) {
        int node1Index = i << 1;
        int node2Index = node1Index + 1;        
        seg[i] = seg[node1Index] + seg[node2Index];
    }
    seg[0] = 0;
    return seg;
}
void updateSegTree(int* seg, int size, int index, int newValue) {
    if(!validateIndex(index, size)) return;
    int segTreeSize = size << 1;
    int segTreeIndex = index + size;
    int currentNodeIndex = index + size;
    int originalValue = seg[currentNodeIndex];
    int diff = newValue - originalValue;    
    
    //Propagate update all over tree till root node;
    while(currentNodeIndex > 0) {
        seg[currentNodeIndex] += diff;
        if((currentNodeIndex & 1) != 1 ) currentNodeIndex >>= 1;
        else currentNodeIndex = (currentNodeIndex - 1 ) >> 1;
    }
}
int printMenu() {
    int choice;
    cout<<"Enter your choice code  "<<endl;
    cout<<"1 Find Sum"<<endl;
    cout<<"2 Update  "<<endl;
    cout<<"3 Print Array"<<endl;
    cout<<"4 Exit"<<endl;
    cin>>choice;
    return choice;
}
int main() {
    //Find the minimum between range
    int size = 32;
    int* seg;
    int* arr =  generateIntRandomArray(size, 0, 100);    
    seg = constructSegTree(arr, size);
    
    int choice = 1;
    do {        
        printArray<int>(arr, size);
        choice = printMenu();
        switch(choice) {
            case 1 :
                    int start, end;
                    cout <<"Enter start index and end index :  ";
                    cin>>start>>end;
                    cout<<"findSum "<<findSum(seg, size, start, end )<<endl;
                    cout<<"findSumLinear "<<findSumLinear(arr, size, start, end )<<endl;
                    break;
            case 2 : 
                     int index, value;
                     cout<<"Enter index and value  :  ";
                     cin>>index>>value;
                     if (!validateIndex(index, size)) break;
                     arr[index] = value;
                     updateSegTree(seg, size, index, value);
                     break;
            case 3 : printArray(arr, size); break;
            default : break;
        }


    }while(choice !=4); 

    


    delete arr;
    delete seg;
}