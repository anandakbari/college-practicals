#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define ver 8


void initilizesinglesource(int distance[ver+1],bool path[ver+1],int source){
    for(int i=0;i<9;i++){
        distance[i]=INT_MAX;
        path[i]=false;
    }
    distance[source]=0;
}


   /* int mindist(int distance[9],bool path[9]){
        int min=INT_MAX,u;
        for(int i=0;i<9;i++){
            if(path[i]==false&&distance[i]<=min){
                min=distance[i];
                u=i;
            }
        }
        return u;
    }*/
void relax1(int u,int v,int distance[],int graph[ver+1][ver+1],bool path[],int parent[]){
    if(path[v]==false&&graph[u][v]!=0&&distance[u]+graph[u][v]<distance[v]){
        distance[v]=distance[u]+graph[u][v];
        parent[v]=u;
    }
}

int bellman(int graph[ver+1][ver+1],int source){
    int distance[ver+1],parent[ver+1]={-1};
    bool path[ver+1];

    int vertex=ver;

    initilizesinglesource(distance,path,source);
    for(int k=1;k<ver;k++){
    for(int i=1;i<=ver;i++){
        for(int j=0;j<ver;j++)
        relax1(i,j,distance,graph,path,parent);
    }
    }
    for(int i=0;i<ver+1;i++){
        printf("\n%d\t%d\t%d",i,distance[i],parent[i]);
    }

    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++){
            if(distance[j]>distance[i]+graph[i][j]){
                return 0;
            }
        }
    }
    return 1;
    
}
void main(){
    int graph[ver+1][ver+1]={{ 0, 11, 0, 0, 0, 0, 0, 8, 0 },
                { 11, 0, 8, 0, 0, 0, 0, 11, 0 },
                { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    int x=bellman(graph,0);
    printf("%d",x);
    }