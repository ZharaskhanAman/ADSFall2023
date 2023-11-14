#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 7;

// DFS -> Depth-first search

vector <int> adj[N];
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;
int visited[N];



void dfs(int v) {
    cout << "Visiting vertex: " << v << endl;
    visited[v] = RED;
    for (int i = 0; i < adj[v].size(); i++) {
        int to = adj[v][i];

        if (visited[to] == WHITE) {
            dfs(to);
        } else if (visited[to] == RED) {
            // cycle found!
        }
    }
    cout << "Finished visiting vertex: " << v << endl;
    visited[v] = BLUE;
}

int main() {
    /*
        5 5
        1 2
        1 5
        2 3
        2 4
        3 4
    */
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    dfs(1);
    
    return 0;
}