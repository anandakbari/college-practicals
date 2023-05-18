#include <stdio.h>
#include<stdlib.h>
#include <time.h>



void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 
  
void selectionsort(int arr[], int n) 
{ 
    int i, j, index; 

    for (i = 0; i < n-1; i++)
    {

        index = i; 
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[index]) 
              index = j;
        }

        if (index!=i)
            swap(&arr[index], &arr[i]);
    }
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
    int key,j,num=3;
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

    selectionsort(randarr,n);
    
    e=clock();
    result=(double)(e-s);

    printf("%f",result);

}