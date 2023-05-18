#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int arr[],int low,int high){
    int i=low,j=high,temp;
    int pivot=arr[low];
    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);

        do{
            j--;
        }while(arr[j]>pivot);

        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    arr[low]=arr[j];
    arr[j]=pivot;

    return j;
}

int quick(int arr[],int low,int high){
 
    if(low<high){
       int j=partition(arr,low,high);
        quick(arr,low,j);
        quick(arr,j+1,high);
    }
}
void merge(int arr[],int left[],int right[],int leftsize,int rightsize){
    int i=0,j=0,k=0;
    while(i<leftsize&&j<rightsize){
        if(left[i]<right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }

    while(i<leftsize){
        arr[k++]=left[i++];
    }
    while(j<rightsize){
        arr[k++]=right[j++];
    }
}

void mergesort(int arr[],int n){
    int mid,i;
    if(n<2) return;
    mid=n/2;
    int left[mid],right[n-mid];
    for(int i=0;i<mid;i++){
        left[i]=arr[i];
    }
    for(int i=mid;i<n;i++){
        left[i-mid]=arr[i];
    }

    mergesort(left,mid);
    mergesort(right,n-mid);
    merge(arr,left,right,mid,n-mid);
}
void main(){
    int arr[50000];
    int n=50000;
    int small,temp;
    clock_t t1,t2;
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    
   /* for(int i=0;i<n;i++){
        int j=i-1;
        while(j>=0&&arr[j]>arr[i]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=arr[i];
    }*/
    t1=clock();
    mergesort(arr,n);
    /*for(int i=0;i<n-1;i++){
        small=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[small]){
                small=j;
            }
            int temp=arr[j];
            arr[j]=arr[small];
            arr[small]=temp;
        }
    }*/
    t2=clock();
    
   

    
    double time_taken=((double)t2)-((double)t1);

    printf("%lf",time_taken);
}