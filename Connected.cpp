#include "iostream"
#include "list"
#include "cstring"
using namespace std;
struct Graph {
    int V;
    list<int>* adj;
};
int V=0;
void create(Graph &G){
    cout<<"Nhap so dinh: ";
    cin>>V;
    G.V=V;
    G.adj = new list<int>[V];
}
void add_edge(Graph &G, int v1,int v2 ){
    G.adj[v1].push_back(v2);
    G.adj[v2].push_back(v1);
}
void DFS_until(Graph &G,int v,bool visited[]){
    visited[v]=true;
    cout<<v<<" ";
    list<int>::iterator i;
    for(i=G.adj[v].begin();i!=G.adj[v].end();++i){
        if (!visited[*i]){
            DFS_until(G,*i,visited);
        }
    }
}
void Connected(Graph &G){
    bool* visited =new bool[V];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            DFS_until(G,i,visited);
            cout<<endl;
        }
    }
    delete[] visited;
}

int main(){
    Graph G;
    create(G);
    add_edge(G,1,0);
    add_edge(G,2,1);
    add_edge(G,3,4);
    Connected(G);
}