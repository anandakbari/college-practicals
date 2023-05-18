#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void insertionsort(int arr[],int n){
    
        int i,key,j;
        for(int i=1;i<n;i++){
            key=arr[i];
            j=i-1;
        
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        }

}

void selectionsort(int arr[],int n){

}

void printarr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main(){
    int n=15000;
    int randarr[15000],i;
    int key,j,num=1;
    clock_t s,e;
    double result;

    switch(num){
        case 1:for(int i=0;i<n;i++){
                randarr[i]=rand();
               }
               break;
            case 2:for(int i=0;i<n;i++){
                    randarr[i]=i;
                   }
                   break;
        case 3:for(int i=0;i<n;i++){
                randarr[i]=n-i;
               }
               break;
    }
    
    s=clock();

    insertionsort(randarr,n);
    
    e=clock();
    result=(double)(e-s);

    printf("%f",result);

}

