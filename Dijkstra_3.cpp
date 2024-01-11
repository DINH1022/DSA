#include "iostream"
#include "vector"
#include "cstring"
using namespace std;

int const M = 1e6 + 7;

struct Graph {
    int v;
    vector<vector<int>> edge;
};

void add_edge(Graph &G, int a, int b, int weight) {
    if (a >= 0 && a < G.v && b >= 0 && b < G.v) {
        G.edge[a][b] = weight;
        G.edge[b][a] = weight;
    }
}

void create(Graph &G) {
    int v = 0;
    cout << "Nhap so dinh: ";
    cin >> v;
    G.v = v;
    G.edge = vector<vector<int>>(v, vector<int>(v, M));

    // ... (your existing add_edge calls)

    // Uncomment the previous section and comment out the following section for the first example.
    add_edge(G, 0, 1, 7);
    add_edge(G, 1, 2, 8);
    add_edge(G, 3, 2, 9);
    add_edge(G, 4, 3, 10);
}

int distance(Graph &G, int dist[], bool set[]) {
    int min = M;
    int min_index = 0;
    for (int i = 0; i < G.v; i++) {
        if (set[i] == false && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void print(Graph G, int src, int dist[], int parent[]) {
    for (int i = 0; i < G.v; i++) {
        if (dist[i] == M) {
            cout << "Dont find way from " << src << " to " << i << endl;
        } else if (i != src) {
            cout << "Distance from " << src << " to " << i << "\t: " << dist[i] << "\t Path: ";
            // Backtrack and print the path from source to destination
            int current = i;
            while (current != src) {
                cout << current << " <- ";
                current = parent[current];
            }
            cout << src << endl;
        }
    }
}

void dijkstra(Graph &G, int src) {
    int dist[G.v];
    bool set[G.v];
    int parent[G.v]; // Keep track of the parent vertices

    memset(dist, M, sizeof(dist));
    memset(set, false, sizeof(set));
    memset(parent, -1, sizeof(parent));

    dist[src] = 0;

    for (int count = 0; count < G.v - 1; count++) {
        int u = distance(G, dist, set);
        set[u] = true;
        for (int i = 0; i < G.v; i++) {
            if (!set[i] && G.edge[u][i] && dist[u] != M && dist[u] + G.edge[u][i] < dist[i]) {
                dist[i] = dist[u] + G.edge[u][i];
                parent[i] = u; // Update the parent vertex
            }
        }
    }

    cout << "Vertex Root: " << src << endl;
    print(G, src, dist, parent);
}

int main() {
    Graph G;
    create(G);
    dijkstra(G, 4);
}
