#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 7;

// DFS -> Depth-first search

vector <int> adj[N];
const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;
int color[N];



void dfs(int v, int new_color) {
    cout << "Coloring vertex: " << v << " with color " <<  new_color << endl;
    color[v] = new_color;
    for (int i = 0; i < adj[v].size(); i++) {
        int to = adj[v][i];

        if (color[to] == WHITE) {
            if (new_color == RED) {
                dfs(to, BLUE);
            } else {
                dfs(to, RED);    
            }
        } else if (color[to] == new_color) {
            cout << "Not bipartite";
            exit(0);
        }
    }
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

    for (int i = 1; i <= n; i++) {
        if (color[i] == WHITE) {
            dfs(i, RED);
        }
    }

    cout << "Bipartite";
    
    return 0;
}