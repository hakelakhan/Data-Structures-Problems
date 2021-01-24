//Problem Statement https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/tree-query-3-5d98588f/
#include <iostream>
#include <utilities.h>
using namespace std;
/*
5 4
1 2
2 3
1 4
4 5
1 3
2 2
1 3
2 
*/

enum query{ flipVertexState = 1, countReachableNodes = 2};
void addBidirectionalEdge(int** matrix, int edgeFrom, int edgeTo, int value) {
    edgeFrom--;     //Since matrix index is 0 based
    edgeTo--;
    matrix[edgeFrom][edgeTo] = value;
    matrix[edgeTo][edgeFrom] = value;
}
void flipVertexStateInAdjMatrix(int** matrix, int rows, int cols, int vertex) {
    vertex--;        //Since matrix index is 0 based
    for(int j = 0; j < cols; j++) {
        matrix[vertex][j] *= -1; 
    }
    for(int j = 0; j < rows; j++) {
        matrix[j][vertex] *= -1;
    }    
}
int countReachableNodesFromVertex(int** matrix, int rows, int cols, int vertex) {
    vertex--;        //Since matrix index is 0 based
    int count = 0;
    for(int j = 0; j < cols; j++) {
        if( matrix[vertex][j] == 1 ) count++;
    }
    return count;
}

int main() {
    int verticesCount;
    int edgesCountForTree;
    int queriesCount;
    int reachableNodesCount;
    int edgeFrom, edgeTo;
    int rows = verticesCount;
    int cols = verticesCount;    
    int** adjMatrix;
    int queryType; 
    int vertex;
    
    cin>>verticesCount;
    edgesCountForTree = verticesCount - 1; 
    cin>>queriesCount;
    adjMatrix = allocateMatrix<int>(rows, cols);
    fillMatrixWithValue<int>(adjMatrix, rows, cols, 0);
    for(int i = 0; i < edgesCountForTree; i++){
        
        cin>>edgeFrom;
        cin>>edgeTo;
        addBidirectionalEdge(adjMatrix, edgeFrom, edgeTo, 1);        
    }
    printMatrix<int>(adjMatrix, rows, cols);

    for(int i = 0; i < queriesCount; i++) {        
        cin>>queryType;
        cin>>vertex;
        if(queryType == flipVertexState) {
            //For all rows matrix[--vertex]
            flipVertexStateInAdjMatrix(adjMatrix, rows, cols, vertex);
        }
        else if(queryType == countReachableNodes) {            
            reachableNodesCount = countReachableNodesFromVertex(adjMatrix, rows, cols, vertex);
            cout<<reachableNodesCount <<" ";
        }
    }

    deleteMatrix<int>(adjMatrix, rows, cols);
    
    char ch ;
    cin >> ch;
    return 0;
}
