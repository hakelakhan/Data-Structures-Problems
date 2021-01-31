#include <iostream>
#include <utilities.h>
using namespace std;
int findMinInRange(int* seg, int n, int start ,int end) {
    int segTreeSize = n << 1;
    int min;
    start = start + n;
    end = end + n;
    min = seg[start];
    if(!validateIndex(start, segTreeSize) || !validateIndex(end, segTreeSize)) return 0;
    while(start <= end) {
        if(start == end) {
            return min < seg[start] ? min  : seg[start];
        }
        if((start  & 1) == 1) {
            if(min > seg[start]) min = seg[start];
            start++;
        }
        if((end  & 1) != 1) {
            if(min > seg[end]) min = seg[end];
            end --;
        }
        start = start >> 1;
        end = (end - 1 ) >> 1;
    }
    return min;
}
int findMinLinear(int* arr, int size, int start, int end) {
    if(!validateIndex(start, size) || !validateIndex(end, size)) return 0;
    int min = arr[start++]; 
    while(start <= end) {
        if(arr[start] < min) min = arr[start];
        start++;
    }
    return min;
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
        int child1Index = i << 1;
        int child2Index = child1Index + 1;        
        seg[i] = seg[child1Index] > seg[child2Index] ? seg[child2Index] : seg[child1Index];
    }
    seg[0] = 0;
    return seg;
}
void updateSegTree(int* seg, int size, int index, int newValue) {
    if(!validateIndex(index, size)) return;
    int segTreeSize = size << 1;
    int segTreeIndex = index + size;
    int currentNodeIndex = index + size;
    seg[currentNodeIndex] = newValue;
    int num1 = newValue;
    int num2 = newValue;
    //Propagate update all over tree till root node;
    while(currentNodeIndex > 0) {
        seg[currentNodeIndex] = min(num1, num2);
        if(isEven(currentNodeIndex)) {
            num1 = seg[currentNodeIndex];
            num2 = seg[currentNodeIndex + 1];            
            currentNodeIndex >>= 1;
        }
        else {
            num1 = seg[currentNodeIndex - 1];
            num2 = seg[currentNodeIndex];
            currentNodeIndex = (currentNodeIndex - 1 ) >> 1;
        }
    }
}
int printMenu() {
    int choice;
    cout<<"Enter your choice code  "<<endl;
    cout<<"1 Find Min"<<endl;
    cout<<"2 Update  "<<endl;
    cout<<"3 Print Data Array"<<endl;
    cout<<"4 Print Segment Array"<<endl;
    cout<<"5 Exit"<<endl;
    cin>>choice;
    return choice;
}
int main() {
    //Find the minimum between range
    int size = 32;
    int* seg;
    int* arr =  generateIntRandomArray(size, -100, 100);    
    seg = constructSegTree(arr, size);
    
    int choice = 1;
    do {        
        choice = printMenu();
        switch(choice) {
            case 1 :
                    int start, end;
                    cout <<"Enter start index and end index :  ";
                    cin>>start>>end;
                    cout<<"findMinInRange "<<findMinInRange(seg, size, start, end )<<endl;
                    cout<<"findMinLinear  "<<findMinLinear(arr, size, start, end )<<endl;
                    break;
            case 2 : 
                     int index, value;
                     cout<<"Enter index and value  :  ";
                     cin>>index>>value;
                     if (!validateIndex(index, size)) break;
                     arr[index] = value;
                     updateSegTree(seg, size, index, value);
                     break;
            case 3 : printArray(arr, size);  break;
            case 4 : printArray(seg, size << 1);  break;
            default : break;
        }


    }while(choice != 5); 

    


    delete arr;
    delete seg;
}