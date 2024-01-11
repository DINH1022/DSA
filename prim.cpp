#include "iostream"
#include "cstring"
using namespace std;
int const v=6;
int const M=1e6+7;
int minkey(int key[],bool set[]){
    int min=M;
    int min_index=0;
    for(int i=0;i<v;i++){
        if(set[i]==false && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

void print(int parent[],int graph[v][v]){
    for(int i=1;i<v;i++){
        cout<<"edge: "<<parent[i]<<"-"<<i<<" weight: "<<graph[i][parent[i]]<<endl;
    }
}

void prim(int graph[v][v]){
    int parent[v];
    int key[v];
    bool set[v];
    for(int i=0;i<v;i++){
        key[i]=M;
        set[i]=false;
    }

    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<v-1;count++){
        int u=minkey(key,set);
        set[u]=true;
        for(int i=0;i<v;i++){
            if(graph[u][i] && set[i]==false && graph[u][i] < key[i]){
                parent[i]=u;
                key[i]=graph[u][i];
            }
        }
    }
    print(parent,graph);
}

int main()
{
    int graph[v][v];
    memset(graph,M,sizeof(graph));
    graph[0][1]=12;
    graph[0][2]=7;
    graph[0][3]=5;
    graph[0][5]=10;
    graph[1][2]=15;
    graph[1][3]=16;
    graph[1][4]=6;
    graph[2][2]=8;
    graph[2][4]=10;
    graph[2][5]=9;
    graph[3][4]=5;
    for(int i=1;i<v;i++){
        for(int j=0;j<i;j++){
            graph[i][j]=graph[j][i];
        }
    }
    prim(graph);
}