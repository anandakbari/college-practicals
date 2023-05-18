#include<stdio.h>
#include<string.h>
int pie[100];
void prefix_fun(char p[]){
    int k=0;
    pie[0]=0;

    for(int i=1;i<strlen(p);i++){
        while(k>0&&p[k]!=p[i]){
            k=pie[k];
        }
        if(p[k]==p[i]) k++;
        pie[i]=k;
    }
}

void main(){
    int tlen, plen, q = 0;
    char text[200] = "xyzahxyfxyzd", pat[100] = "xyz";
    tlen = strlen(text);
    plen = strlen(pat);
    prefix_fun(pat);
    for(int i=0;i<tlen;i++){
        while(q>0&&pat[q]!=text[i]){
            q=pie[q-1];
        }
        if(pat[q]==text[i]){
            q++;
        }
        if(q==plen){
            printf("pattern occurs at %d",i-plen+1);
            q=pie[q-1];
            printf("\n");
        }
    }
}