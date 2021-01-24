//Problem Statement https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/tree-query-3-5d98588f/
#include <iostream>
#include <algorithm>
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
2 2
*/

enum query{ flipVertexState = 1, countReachableNodes = 2};

int main() {
    int verticesCount;
    int edgesCountForTree;
    int queriesCount;    
    int edgeFrom, edgeTo;
    int rows = verticesCount;
    int cols = verticesCount;    
    int queryType; 
    int vertex;    	
    int operation; 
    int* verticesState;
    int* reachableNodesCount;
    int* adjListX;
    int* adjListY;
    int maxlength, actualLength;
    int k;
    cin>>verticesCount;
    edgesCountForTree = verticesCount - 1; 
    cin>>queriesCount;
    verticesState = new int[verticesCount];
    reachableNodesCount = new int[verticesCount];
    maxlength = (verticesCount * ( verticesCount - 1) ) / 2;
    adjListX = new int[maxlength];
    adjListY = new int[maxlength];
    k = 0;
    fill_n(verticesState, verticesCount, 1);
    fill_n(reachableNodesCount, verticesCount, 0);
    for(int i = 0; i < edgesCountForTree; i++){
        
        cin>>edgeFrom>>edgeTo;  	
        edgeFrom--;
        edgeTo--;	        
        reachableNodesCount[edgeFrom] += 1;
        reachableNodesCount[edgeTo] += 1;
        adjListX[k] = edgeFrom;
        adjListY[k] = edgeTo;
        k++;
    }
    actualLength = k;
    for(int i = 0; i < queriesCount; i++) {
        cin>>operation>>vertex;
        vertex--;    
        if(operation == flipVertexState) {
                    
            //Update adjMatrix
            for(int i = 0; i < actualLength; i++) {
                if( verticesState [vertex] == 1 ) {
                    if(adjListX[i] == vertex  ) {
                        adjListX[i] *= -1;
                        adjListY[i] *= -1;
                        reachableNodesCount[adjListY[i] * -1 ] -= 1;
                        reachableNodesCount[adjListX[i] * -1 ] -= 1;

                    }
                    else if(adjListY[i] == vertex  ) {
                        adjListX[i] *= -1;
                        adjListY[i] *= -1;
                        reachableNodesCount[adjListY[i] * -1 ] -= 1;
                        reachableNodesCount[adjListX[i] * -1 ] -= 1;
                    }                                    
                }
                else {
                    if(adjListX[i] * - 1 == vertex  ) {
                        adjListX[i] *= -1;
                        adjListY[i] *= -1;
                        reachableNodesCount[adjListY[i] ] += 1;
                        reachableNodesCount[adjListX[i] ] += 1;
                    }
                    else if(adjListY[i] * - 1 == vertex  ) {
                        adjListX[i] *= -1;
                        adjListY[i] *= -1;
                        reachableNodesCount[adjListY[i] ] += 1;
                        reachableNodesCount[adjListX[i] ] += 1;
                    }                    
                }

                
                
            }   
            verticesState[vertex] *= -1;         
            
        }
        else if(operation == countReachableNodes) {
            cout<<reachableNodesCount[vertex]<<endl;
        }

    }
	
    return 0;
}

