#include <iostream>
#include <vector>
using namespace std;
const int N = 1e3 + 7;
vector <pair<int, int> > adj[N];

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

    for (int i = 1; i <= e; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back(make_pair(to, weight));
    }

    // a[5].first -> to
    // a[5].second -> weight

    return 0;
}