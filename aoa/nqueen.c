#include<stdio.h>
#include<stdlib.h>
int place(int box[],int k,int i){
    for(int j=0;j<k;j++){
        if(box[j]==i||abs(box[j]-i)==abs(j-k)) return 1;
    }

    return 0;
}

void nqueens(int box[],int k,int n){
    for(int i=0;i<n;i++){
        
        if(place(box,k,i)==0){
            box[k]=i;
            if(k==n-1){
                printf("solution\n");
                for(int a=0;a<n;a++){
                    printf("queen %d placed at %d\n",a+1,box[a]+1);
                }
                printf("\n");
            }
            else nqueens(box,k+1,n);
        }
        
    }
}


void main(){
    int box[100];
    int n=5;
    nqueens(box,0,5);
}