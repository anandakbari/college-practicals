#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define ver 8


void initilizesinglesource(int distance[9],bool path[9],int source){
    for(int i=0;i<9;i++){
        distance[i]=INT_MAX;
        path[i]=false;
    }
    distance[source]=0;
}


int mindist(int distance[9],bool path[9]){
    int min=INT_MAX,u;
    for(int i=0;i<9;i++){
        if(path[i]==false&&distance[i]<=min){
            min=distance[i];
            u=i;
        }
    }
    return u;
}
void relax1(int u,int v,int distance[],int graph[9][9],bool path[],int parent[]){
    if(path[v]==false&&graph[u][v]!=0&&distance[u]+graph[u][v]<distance[v]){
        distance[v]=distance[u]+graph[u][v];
        parent[v]=u;
    }
}

int dijkstra(int graph[9][9],int source){
    int distance[9],parent[9]={-1};
    bool path[9];

    int vertex=ver+1;

    initilizesinglesource(distance,path,source);

    while(vertex!=0){
        int u=mindist(distance,path);
        path[u]=true;
        for(int v=0;v<9;v++){
            relax1(u,v,distance,graph,path,parent);
        }
        vertex--;
    }

    for(int i=0;i<9;i++){
        printf("\n%d\t%d\t%d",i,distance[i],parent[i]);
    }
}
void main(){
    int graph[9][9]={{ 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    dijkstra(graph,0);
    }