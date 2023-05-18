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
    int n=5;
    int At[]={2,5,1,0,4};
    int Bt[]={6,2,8,3,4};
    int ganttC[n+1],gantP[n];
    ganttC[0]=0;
    int d[n][3],v[n];
    int sum=0;

    for(int i=0;i<n;i++){
        d[i][0]=At[i];
        d[i][1]=Bt[i];
        d[i][2]=i; 
        v[i]=0;   
    }
    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){
            if(d[j][1]>d[j+1][1]){
                swap(&d[j][0],&d[j+1][0]);
                swap(&d[j][1],&d[j+1][1]);
                swap(&d[j][2],&d[j+1][2]);
            }
        }
    }
    
    
    int flag=0;
    int k=0;
    int index=0;
    while(flag!=n){
        int f=0;
        for(int j=0;j<n;j++){
            if(d[j][0]<=k&&v[j]==0){
                gantP[index]=d[j][2]+1;
                ganttC[index+1]=sum+d[j][1];
                sum=sum+d[j][1];
                k=sum;
                f=1;
                v[j]=1;
                flag++;
                index++;
                break;
            }
        }
        if(f==0) k++;
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
        printf("  p%d ",gantP[i]);
        
    }
    printf("\n");

    for(int i=0;i<n+1;i++){
        printf("%d    ",ganttC[i]);
        
    }
    printf("\n");
    
    printf("%f \n %f",avgtat,avgWt);
    
}