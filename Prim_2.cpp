#include "iostream"
#include "vector"
using namespace std;
int const M=1e6+7;

struct Graph{
    int v;
    vector<vector<int>> edge;
};
void add_edge(Graph &G,int a,int b,int weight){
    if (a >= 0 && a < G.v && b >= 0 && b < G.v) {    // co moi chay
        G.edge[a][b]= weight;
        G.edge[b][a]= weight;     // có hướng thì bỏ 
    }
}
void create(Graph &G){
    int v=0;
    cout<<"Nhap so dinh: ";
    cin>>v;
    G.v=v;
    G.edge=vector<vector<int>>(v,vector<int>(v,M));

    add_edge(G,0,1,12);
    add_edge(G,0,2,7);
    add_edge(G,0,5,10);
    add_edge(G,1,2,15);
    add_edge(G,1,3,16);
    add_edge(G,1,4,6);
    add_edge(G,2,4,10);
    add_edge(G,2,5,9);
    add_edge(G,3,4,15);
     /*for(size_t i=0;i<G.edge.size();++i){
        for(size_t j=0;j<G.edge[i].size();++j){
            cout<<G.edge[i][j]<<" ";
        }
        cout<<endl;
    }*/
}
int minkey(Graph &G,int key[],bool set[]){
    int min=M;
    int min_index=0;
    for(int i=0;i<G.v;i++){
        if(set[i]==false && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

void print(Graph G,int parent[]){
    for(int i=1;i<G.v;i++){
        cout<<"edge: "<<parent[i]<<"-"<<i<<" weight: "<<G.edge[i][parent[i]]<<endl;
    }
}

void prim(Graph &G){
    int parent[G.v];
    int key[G.v];
    bool set[G.v];
    for(int i=0;i<G.v;i++){
        key[i]=M;
        set[i]=false;
    }

    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<G.v-1;count++){
        int u=minkey(G,key,set);
        set[u]=true;
        for(int i=0;i<G.v;i++){
            if(G.edge[u][i] && set[i]==false && G.edge[u][i] < key[i]){
                parent[i]=u;
                key[i]=G.edge[u][i];
            }
        }
    }
    print(G,parent);
}

int main()
{
    Graph G;
    create(G);
    prim(G);
}