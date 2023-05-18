#include<stdio.h>
void main()
{
    float profit[100],weight[100],pwratio[100],knapsack[100],totalprofit=0,totalweight=10,max=0;
    int i,j,n,visited[100],maxInd;
    printf("Enter no. of elements ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter profit and wt of element%d ",i+1);
        scanf("%f %f",&profit[i],&weight[i]);
        pwratio[i]=profit[i]/weight[i];
        visited[i]=0;
    }

    for(int i=0;i<n;i++){
        int max=-1;
        for(int i=0;i<n;i++){
            if(visited[i]==0&&pwratio[i]>max){
                max=pwratio[i];
                maxInd=i;
            }
        }
        visited[maxInd]=1;
        if(weight[maxInd]<=totalweight){
            totalweight-=weight[maxInd];
            knapsack[maxInd]=1;
        }
        else{
            knapsack[maxInd]=totalweight/weight[maxInd];
            totalweight=0;
        }
        totalprofit+=knapsack[maxInd]*profit[maxInd];
    }

    printf("\nprofit\t\tweight\t\tp/w\t\t\tknapsack\n");
    for(i=0;i<n;i++)
    printf("%f\t%f\t%f\t%f\n",profit[i],weight[i],pwratio[i],knapsack[i]);
    printf("max profit is %f",totalprofit);





}