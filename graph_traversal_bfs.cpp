#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int nodesCount;
    vector<int>* adjList;
    public : Graph() {}
    public : Graph(int nodesCount) { 
        this -> nodesCount = nodesCount;
        this -> adjList   = new vector<int>[nodesCount];
    }
    public :  int* shortestReach(int startIndex) {
        int* distances;
        queue<int> q;
        distances = new int[nodesCount];
        for(int i = 0; i < nodesCount; i++) {
            distances[i] = -1;
        }
        distances[startIndex] = 0;
        q.push(startIndex);
        while(!q.empty()) {            
            int currentNode = q.front();
            q.pop();
//cout<<"Procesing "<<currentNode <<endl;                
            
            //Get edges for it from adjacensy list

            
            for(int possibleDestinationFromCurrentNode : adjList[currentNode]) {
  //              cout<<"Processing "<<currentNode<<" -> " << possibleDestinationFromCurrentNode<<endl;
                if(distances[possibleDestinationFromCurrentNode] > 0) continue;
    //            cout<<"Edge from "<<currentNode<<"->" <<possibleDestinationFromCurrentNode<<endl;
                q.push(possibleDestinationFromCurrentNode);
                
                distances[possibleDestinationFromCurrentNode] = distances[currentNode] + 6;     
            }
        }
        return distances;
    }
    public : void addEdge(int u, int v) { 
        adjList[u].push_back(v);
        adjList[v].push_back(u);        
        return;    
    }
    
};
int main() {
    int noOfTestCases;
    int n, m, u, v, i, j, startIndex;    
    cin>>noOfTestCases;
    for(i = 0; i < noOfTestCases; i++) {
        Graph* g;
        
        cin>>n>>m;
        g  = new Graph(n);
        for(j = 0;j < m; j++) {
            cin>>u>>v;
            g -> addEdge(--u, --v);
        }
        cin>>startIndex;
        int* output = g -> shortestReach(--startIndex);
        for(int i = 0; i < n ; i++) {
            if(i != startIndex)
                cout<<output[i]<<" ";
        }
        cout<<endl;
        delete g;
    }
   
}
