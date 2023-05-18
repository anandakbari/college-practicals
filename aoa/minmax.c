#include <stdio.h>
#include <stdlib.h>
#define n 10
int i, a[n];
int max, min;

void minmax(int a[],int i,int j)
{   int max1,min1;
    if(i==j) max=min=a[i];
    else
    {
         if(i==j-1)
         {
            if(a[i]<a[j])
            {
                max=a[j];
                min=a[i];
            }
            else
            {
                max=a[i];
                min=a[j];
            }
         }
         else
         {
            int mid=(i+j)/2;
            minmax(a,i,mid);
            max1=max;
            min1=min;
            minmax(a,mid+1,n);
            if(max<max1) max=max1;
            if(min>min1) min=min1;
         }
    }
}


void main(){
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
printf("elements of array are ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }

    min=a[0];
    max=a[0];
    minmax(a,0,n);
    printf("\n");
    printf("%d  %d",max,min);
}