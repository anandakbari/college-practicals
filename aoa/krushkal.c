#include<stdio.h>
#include<stdlib.h>

int parent[10];

int find(int i){
    while(parent[i]) i=parent[i];
    return i;
}
int uni(int i,int j){
    if(i!=j){
        parent[j]=i;
        return 1;
    }
    return 0;
}

void main(){
    int n=5,a,v,u,b;
    int min=0,mincost=0,ne=1,i,j;
    int parent[10];
    printf("Enter number of vertices:\n");
   // scanf("%d",&n);
    int cost[5][5]={{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    printf("Enter adjacency matrix:\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
         //   scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            {
                cost[i][j]=999;
            }
        }
    }

    while(ne<n){
        for(i=0,min=999;i<n;i++){
            for(j=0;j<n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u=find(u);
        v=find(v);

        if(uni(u,v)){
            printf("edge %d:(%d %d) cost: %d",ne++,a+1,b+1,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=999;
    }
    printf("minimum cost:%d \n",mincost);
}