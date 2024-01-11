#include "iostream"
#include "cstring"
#include "limits.h"
using namespace std;
int const v = 6;
int const M = 1e6+7;

int distance(int dist[],bool set[]){
    int min=M;
    int min_index=0;
    for(int i=0;i<v;i++){
        if(set[i]==false && dist[i]<min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void print(int dist[]){
    for(int i=0;i<v;i++){
        cout<<"Distance to vertex: "<<i<<"\t: "<<dist[i]<<endl;
    }
}

void dijkstra(int graph[v][v],int src){
    int dist[v];
    bool set[v];
    memset(dist,M,sizeof(dist));
    memset(set,false,sizeof(set));
    dist[src]=0;
    for(int count=0;count<v-1;count++){
        int u=distance(dist,set);
        set[u]=true;

        for(int i=0;i<v;i++){
            if(!set[i] && graph[u][i] && dist[u]!=M && dist[u]+graph[u][i]<dist[i]){
                dist[i]=dist[u]+graph[u][i];
            }
        }
    }
    cout<<"Vertex Root: "<<src<<endl;
    print(dist);
}
int main(){

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
        dijkstra(graph,4);
}