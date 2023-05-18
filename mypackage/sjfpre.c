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
int minbust(int at[],int bt[],int i,int n){
    int least=9999,minind;
    for(int j=0;j<n;j++){
        if(bt[j]<least&&at[j]<=i&&bt[j]>0){
            least=bt[j];
            minind=j;
        }
    }
    return minind;
}
int main(){
    int n=5;
    int at[]={2,5,1,0,4};
    int bt[]={6,2,8,3,4};
    int backupbt[n];
    int process[]={1,2,3,4,5};
    int ct[n],sumat=0;
    int gantt[100],ganttc[100],count=0,index=0,minind;
    int tat[n],wt[n],ttat=0,twt=0,ogbt[n];

    for(int i=0;i<n;i++){
        gantt[i]=0;
        ogbt[i]=bt[i];
    }
    int i=0;
    while(count!=n){
        minind=minbust(at,bt,i,n);
        if(process[minind]!=gantt[index-1]){
            gantt[index]=process[minind];
            ganttc[index]=i;
            index++;
        }
        else{
            ganttc[index]=i;
            bt[minind]--;
            i++;
            if(bt[minind]==0){
                count++;
                ct[minind]=i;
                tat[minind]=ct[minind]-at[minind];
            ttat+=tat[minind];
            wt[minind]=tat[minind]-ogbt[minind];
            twt+=wt[minind];
            }
        }
    }
    
    for(int i=0;i<index;i++){
        printf("  p%d",gantt[i]);
    }
    printf("\n");
    for(int i=0;i<index;i++){
        printf("%d   ",ganttc[i]);
    }
   
    
   
 



    printf("\n");
    printf("tat=%f \n wat=%f ",(float)ttat/n,(float)twt/n);
}