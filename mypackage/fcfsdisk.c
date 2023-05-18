#include<stdio.h>
#include<stdlib.h>
void main(){
    int st=0;
    int tracks=8;
    int head=50;
    int data[]={176,79,34,60,92,11,41,114};

    for(int i=0;i<tracks;i++){
        st+=abs(data[i]-head);
        head=data[i];
    }
    printf("%d",st);
}