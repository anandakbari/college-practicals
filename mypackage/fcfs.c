#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

double avg(int a[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    return (double)sum/(double)n;
}
int main(){
    int At[]={2, 5, 1, 0, 4};
    int Bt[]={6, 2, 8, 3, 4};
    int n=sizeof(At)/sizeof(At[0]);
    int ganttC[n+1],gantP[n];
    ganttC[0]=0;
    int d[n][3];
    int Ct[n];
    int sum=0;
    for(int i=0;i<n;i++){
        d[i][0]=At[i];
        d[i][1]=Bt[i];
        d[i][2]=i;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(d[i][0]>d[j][0]){
                swap(&d[i][0],&d[j][0]);
                swap(&d[i][1],&d[j][1]);
                swap(&d[i][2],&d[j][2]);
            }
            
        }
    }
    for(int i=0;i<n;i++){
        gantP[i]=d[i][2]+1;
        ganttC[i+1]=sum+d[i][1];
        sum=sum+d[i][1];
    }
    for(int i=0;i<n;i++){
        Ct[i]=ganttC[i+1];
    }

    int taT[n],wt[n];
    for(int i=0;i<n;i++){
        taT[i]=ganttC[i+1]-At[i];
        
    }
    for(int i=0;i<n;i++){
        wt[i]=taT[i]-Bt[i];
        
    }

    double avgWt=avg(wt,n);
    double avgtat=avg(taT,n);

    for(int i=0;i<n;i++){
        printf("p%d ",gantP[i]);
        
    }
    printf("\n");

    for(int i=0;i<n+1;i++){
        printf("%d ",ganttC[i]);
        
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",Ct[i]);
    }
    printf("\n");
    printf("%f \n %f",avgtat,avgWt);

}