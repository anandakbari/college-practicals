#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define ver 5


void initilizesinglesource(int distance[ver],int source,int parent[]){
    for(int i=0;i<9;i++){
        distance[i]=INT_MAX;
        
        parent[i]=-1;
    }
    distance[source]=0;
}


void relax1(int u,int v,int distance[],int graph[ver][ver],int parent[]){
    if(graph[u][v]!=0&&distance[u]+graph[u][v]<distance[v]){
        distance[v]=distance[u]+graph[u][v];
        parent[v]=u;
    }
}

int bellman(int graph[ver][ver],int distance[ver],int parent[ver],int source){
    
    bool path[ver];

    

    initilizesinglesource(distance,source,parent);
    for(int k=1;k<ver;k++){
        printf("iternation: %d",k);
    for(int i=0;i<ver;i++){
        for(int j=0;j<ver;j++)
        relax1(i,j,distance,graph,parent);
    }
    for(int i=0;i<ver;i++){
        printf("\n%d\t%d\t%d",i,distance[i],parent[i]);
    }
    printf("\n");
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
    int graph[ver][ver]={
{0, 6, 0, 7, 0},
{0, 0, 5, 8, -4},
{0, -2, 0, 0, 0},
{0, 0, -3, 0, 9},
{2, 0, 7, 0, 0}, };

int distance[ver],parent[ver];

    int x=bellman(graph,distance,parent,0);
    printf("%d",x);
    }