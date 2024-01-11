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
        G.edge[b][a]= weight;    // có hướng thì bỏ 
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
int parent[100];
int Find(int x){
    while(parent[x]!=x){
        x=parent[x];
    }
    return x;
}

void Union(int i,int j){
    int a=Find(i);
    int b=Find(j);
    parent[a]=b;
}

void Kruskal(Graph &G){
    int mincost=0;
    for(int i=0;i<G.v;i++){
        parent[i]=i;   
    }
    int edge=0;
    while(edge<G.v-1){
        int min=M;
        int a=-1;
        int b=-1;
        for(int i=0;i<G.v;i++){
            for(int j=0;j<G.v;j++){
                if(Find(i)!=Find(j) && G.edge[i][j]<min){
                    min=G.edge[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        Union(a,b);
        cout<<"edge "<<edge++;
        cout<<":("<<a<<"-"<<b<<") ";
        cout<<"cost = "<<min<<endl;
        mincost+=min;
    }
    cout<<"TOTAL COST = "<<mincost;
}

int main(){
    
    Graph G;
    create(G);
    Kruskal(G);
}