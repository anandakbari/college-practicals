#include<stdio.h>

void main(){
    int n=4,nmem=6,memloc[100],visited[100],index=0;
    int memsizes[]={200,400,600,500,300,250};
    int processsizes[]={357,210,468,491};

    for(int i=0;i<nmem;i++){
        visited[i]=0;
        memloc[i]=-1;
    }

    for(int i=0;i<n;i++){
        int min=9999;
        for(int j=0;j<nmem;j++){
            if(memsizes[j]-processsizes[i]<min &&memsizes[j]-processsizes[i]>=0&&visited[j]==0){
                min=memsizes[j]-processsizes[i];
                memloc[i]=j;
            }
        }
        visited[memloc[i]]=1;
    }

    for(int i=0;i<n;i++){
        if(memloc[i]!=-1) printf("processize=%d location=%d hole=%d\n",processsizes[i],memsizes[memloc[i]],memsizes[memloc[i]]-processsizes[i]);
         else
        printf("%d not allocated to memory",processsizes[i]);
    }

    
}