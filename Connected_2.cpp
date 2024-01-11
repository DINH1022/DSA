#include <iostream>
#include <vector>

using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
};

int V = 0;

void create(Graph& G) {
    cout << "Nhap so dinh: ";
    cin >> V;
    G.V = V;
    G.adj.resize(V, vector<int>(V, 0));
}

void add_edge(Graph& G, int v1, int v2) {
    G.adj[v1][v2] = 1;
    G.adj[v2][v1] = 1;
}

void DFS_until(Graph& G, int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int i = 0; i < G.V; i++) {
        if (G.adj[v][i] && !visited[i]) {
            DFS_until(G, i, visited);
        }
    }
}

void Connected(Graph& G) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS_until(G, i, visited);
            cout << endl;
        }
    }
}

int main() {
    Graph G;
    create(G);

    add_edge(G, 1, 0);
    add_edge(G, 2, 1);
    add_edge(G, 3, 4);

    Connected(G);

    return 0;
}
