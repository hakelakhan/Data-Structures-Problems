#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
void printArray(T* a, int ){
    for(int i = 0; i < n; i++) {
        cout<<a[i] << " ";
    }
    cout<<endl;
}
template <typename T>
void swap(T* a, T* b) {
    T tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
int min(int a, int b) {
    return a < b ? a : b;
}
bool isEven(int num) {
    return (num & 1) != 1;
}
bool isOdd(int num) {
    return (num & 1) == 1;
}
int* generateIntRandomArray(int size, int min, int max) {
    int* arr = new int[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
    return arr;
}
template <typename T>
T** allocateMatrix(int rows , int cols) {
    T** matrix = new T*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new T[cols];
    }
    return matrix;
}
template <typename T>
void deleteMatrix( T** matrix, int rows , int cols) {    
    for(int i = 0; i < rows; i++) {
        delete matrix[i] ;
    }
    delete matrix;
}
template <typename T>
void printMatrix(T** matrix, int rows, int cols) {    
    cout<<endl;    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout<<setw(10)<<matrix[i][j] << "  ";
        }
        cout<<endl;
    }    
}
template <typename T>
void fillMatrixWithValue(T** matrix, int rows, int cols, T value) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = value;
        }
    }
}
void waitForKey() {
    char key;
    cin>>key;
}
bool validateIndex(int index, int size) {
    return index >= 0 && index < size; 
}