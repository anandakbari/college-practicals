#include<stdio.h>
#include<stdlib.h>
void main(){
    int st=0;
    int n=8;
    int head=50;
    int data[]={176,79,34,60,92,11,41,114};
    int v[n];
    int j=0,diff,index,curr=0;
    for(int i=0;i<n;i++) v[i]=0;
    curr=head;
    while(j<n){
        int min=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(v[i]==0){
                diff=abs(curr-data[i]);
                if(diff<min){
                    min=diff;
                    index=i;
                   
                }
            }
        }

        st+=min;
        curr=data[index];
        v[index]=1;


        j++;
    }
    printf("%d",st);

}