#include <iostream>
#include <iterator>
#include <algorithm>
#include <utilities.h>
using namespace std;
bool isCurrentRowProcessed(int* processedRows, int rows, int currentRow) {
    //return !(find(std::begin<int>(processedRows), end(processedRows), currentRow) == end(processedRows));
    for(int i = 0; i < rows; i++) {
        if(processedRows[i] == currentRow) return true;
    }     
    return false;
}
bool isCurrentColProcessed(int* processedCols, int cols, int currentCol) {
    for(int i = 0; i < cols; i++) {
        if(processedCols[i] == currentCol) return true;
    }     
    return false;
}
void spiralTraversal(int** matrix, int rows, int cols) {
    int circlesMadeCount = 0;
    int i, j;
    int* processedRows;
    int* processedCols;

    processedRows = new int[rows];    
    int processedRowsTop = -1;
    processedCols = new int[cols];
    int processedColsTop = -1;

    fill(processedRows, processedRows + rows, -1);
    fill(processedCols, processedCols + cols, -1);

    for(i = 0 + circlesMadeCount; i < rows - circlesMadeCount ; i++) {
        if(isCurrentRowProcessed(processedRows, rows, i)) return ;
        for( j = 0 + circlesMadeCount; j < cols - circlesMadeCount; j++) {
            cout<<matrix[i][j]<<"  ";
        }//Processed row
        processedRowsTop++;
        processedRows[processedRowsTop] = i;
        //if(j == cols)
        j--;
        i++;
        if(isCurrentColProcessed(processedCols, cols, j))   return;
        while(i < rows - circlesMadeCount) {
            cout<<matrix[i][j]<<"  ";
            i++;
        }//Processed Col
        processedColsTop++;
        processedCols[processedColsTop] = j;
        i--;
        j--;        
        if(isCurrentRowProcessed(processedRows, rows, i)) return ;
        while(j >= 0 + circlesMadeCount) {
            cout<<matrix[i][j]<<"  ";
            j--;
        }//Prcessed row
        processedRowsTop++;
        processedRows[processedRowsTop] = i;
        j++;
        i--;
        if(isCurrentColProcessed(processedCols, cols, j))   return;
        while(i > 0 + circlesMadeCount) {
            cout<<matrix[i][j]<<"  ";
            i--;
        }//Processsed Col
        processedColsTop++;
        processedCols[processedColsTop] = j;

        circlesMadeCount++;
    }
    delete processedRows;
    delete processedCols;
}
int main() {

    int m = 10, n = 3;
    int** matrix = allocateMatrix<int>(m, n);
    fillMatrixWithRandomValue<int>(matrix, m, n, 0, 100);
    printMatrix<int>(matrix, m, n);
    spiralTraversal(matrix, m , n);
    deleteMatrix(matrix, m , n);

    waitForKey();

    return 0;
}