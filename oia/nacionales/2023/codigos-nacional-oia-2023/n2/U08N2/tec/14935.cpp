#include <string>
#include <iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

class Graph{
    public:
        vector<vector<int>> adjList;
        int V;

    // Graph(int v) : V(v){
    //     adjList.reserve(V+1);
    // }

    void res(int V){
        adjList.reserve(V+1);
    }

    void addEdge(int src, int dst){
        adjList[src].push_back(dst);
        adjList[dst].push_back(src);
    }

    // void printGraph(){
    //     for(int i = 0; i < adjList.capacity();i++){
    //         cout << i << " -> ";
    //         for (int a : adjList[i]) {
    //             cout << a << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    
    int friends(set<int> mine){
        for (int a : mine){
            for(int f : adjList[a]){
                if (mine.find(f) == mine.end()) return f;
            }
        }
        return -1;
    }

};

Graph grafo;

void tablero(int N, vector<int> &A, vector<int> &B) {
    grafo.res(N);
    for (int i = 0; i < A.size();i++){
        grafo.addEdge(A[i], B[i]);
    }

}

int con_quien_comercio(vector<int> &controlados) {
    set<int> controlados2(controlados.begin(),controlados.end());
    return grafo.friends(controlados2);
}


// int main(){
//     vector<int> A = {1};
//     vector<int> B = {2};
//     tablero(2,A,B);
//     cout << con_quien_comercio({1,2}) << endl;

//     return 0;
// }