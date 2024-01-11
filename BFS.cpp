#include <iostream>
#include <vector>
#include <queue>

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

void add_edge(Graph& G, int u, int v, int weight) {
    G.adj[u][v] = weight;
     //G.adj[v][u] = weight;    // vô hướng 
}

void BFS(const Graph& G, int s) {
    vector<bool> visited(G.V, false);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        s = q.front();
        cout << s << " ";
        q.pop();

        for (int adjacent = 0; adjacent < G.V; ++adjacent) {
            if (G.adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = true;
                q.push(adjacent);
            }
        }
    }
}

int main() {
    Graph g;
    create(g);

    add_edge(g, 0, 1, 12);
    add_edge(g, 0, 2, 7);
    add_edge(g, 0, 3, 5);
    add_edge(g, 0, 5, 10);
    add_edge(g, 1, 2, 15);
    add_edge(g, 1, 3, 16);
    add_edge(g, 1, 4, 6);
    add_edge(g, 2, 2, 8);
    add_edge(g, 2, 4, 10);
    add_edge(g, 2, 5, 9);
    add_edge(g, 3, 4, 5);

    int startVertex;
    cout << "Nhap dinh bat dau BFS: ";
    cin >> startVertex;

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex " << startVertex << ") \n";
    BFS(g, startVertex);

    return 0;
}
