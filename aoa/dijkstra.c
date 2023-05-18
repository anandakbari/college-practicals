#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#define v 8
void isc(int distance[],bool visited[],int parent[],int source){
    for(int i=0;i<v+1;i++){
        distance[i]=INT_MAX;
        visited[i]=false;
        parent[i]=-1;
    }
    distance[source]=0;
}

int mindist(int distance[],bool visited[]){
    int min=INT_MAX,u;
    for(int i=0;i<v+1;i++){
        if(visited[i]==false&&distance[i]<min){
            min=distance[i];
            u=i;
        }
    }
    return u;
}

void relax1(int u,int x,int distance[],int graph[9][9],bool visited[],int parent[]){
    if(graph[u][x]!=0&&distance[x]>distance[u]+graph[u][x]){
        distance[x]=distance[u]+graph[u][x];
        parent[x]=u;
    }
}

void dijkstra(int graph[v+1][v+1],int source){
    int distance[v+1],parent[v+1];
    bool visited[v+1];
    int count=0;

    isc(distance,visited,parent,source);

    while(count!=v){
       int u=mindist(distance,visited);
       visited[u]=true;
       for(int x=0;x<v+1;x++){
        relax1(u,x,distance,graph,visited,parent);
       }
       count++;
    }


    for(int i=0;i<v+1;i++) {
        printf("%d\t%d\t%d\n",i,distance[i],parent[i]);
    }
}


void main(){

    int graph[v+1][v+1]={{ 0, 11, 0, 0, 0, 0, 0, 8, 0 },
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