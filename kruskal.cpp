#include "iostream"
#include "cstring"
using namespace std;
int const v=6;
int const M=1e6+7;
int parent[v];

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

void Kruskal(int graph[][v]){
    int mincost=0;
    for(int i=0;i<v;i++){
        parent[i]=i;   
    }
    int edge=0;
    while(edge<v-1){
        int min=M;
        int a=-1;
        int b=-1;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(Find(i)!=Find(j) && graph[i][j]<min){
                    min=graph[i][j];
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
    /*int graph[][v]={
        {M,12,7,M,M,10},
        {12,M,15,16,6,M},
        {7,15,M,M,10,9},
        {M,16,M,M,15,M},
        {M,6,10,15,M,M},
        {10,M,9,M,M,M},
    };*/
    int graph[v][v];
    memset(graph,M,sizeof(graph));
    graph[0][1]=12;
    graph[0][2]=7;
    graph[0][5]=10;
    graph[1][2]=15;
    graph[1][3]=16;
    graph[1][4]=6;
    graph[2][4]=10;
    graph[2][5]=9;
    graph[3][4]=15;
    for(int i=1;i<v;i++){
        for(int j=0;j<i;j++){
            graph[i][j]=graph[j][i];
        }
    }
    /*for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }*/
    Kruskal(graph);
}