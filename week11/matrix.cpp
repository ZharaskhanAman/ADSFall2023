#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 7;
int adj[N][N];

int main() {
    /*
        4 5
        1 2 5
        2 3 7
        2 4 6
        3 4 5
        4 1 2
    
    
    */
    int v, e;

    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            adjp[i][j] = -1;
        }
    }

    for (int i = 1; i <= e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        // oriented
        adj[from][to] = weight; 

        // not oriented
        // adj[to][from] = weight; 
    }

    return 0;
}