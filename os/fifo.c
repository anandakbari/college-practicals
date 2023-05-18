#include<stdio.h>

int n=9;
    int nf=4;
    int in[]={ 5, 0, 1, 3, 2, 4, 1, 0, 5};
    int p[50];
    int pgfaultcnt=0,hit=0,least[50];
    int k=0;

int ishit(int data){
    hit =0;
   for (int i=0;i<nf;i++){
    if(p[i]==data){
        hit=1;
        break;

    }
   }
    return hit;
}
void dispPages()
{
    for (k = 0; k < nf; k++)
    {
        if (p[k] != 9999)
            printf(" %d", p[k]);
    }
}
int getHitIndex(int data)
{
    int hitind;
    for (k = 0; k < nf; k++)
    {
        if (p[k] == data)
        {
            hitind = k;
            break;
        }
    }
    return hitind;
}
void main(){
    

    for(int i=0;i<nf;i++){
        p[i]=9999;
    }
    
    /*for(int i=0;i<n;i++){
        printf("\nfor %d :",in[i]);
        if(ishit(in[i])==0){
            for(k=0;k<nf-1;k++)
                p[k]=p[k+1];
                p[k]=in[i];
                pgfaultcnt++;
                dispPages();
        }
            else printf("hit");
        
        
    }*/

    /*for(int i=0;i<n;i++){
        printf("\nfor %d :",in[i]);
        if(ishit(in[i])==0){
            for(int j=0;j<nf;j++){
                int pg=p[j];
                int found=0;
                for(k=i-1;k>=0;k--){
                    if(pg==in[k]){
                        least[j]=k;
                        found=1;
                        break;
                    }
                    else found=0;
                }
                if(!found) least[j]=-9999;
            }
            for(int i=0;i<n;i++){
                printf("p=%d ",least[i]);
            }
            int min=9999;
            int index;
            for(int j=0;j<nf;j++){
                if(least[j]<min){
                    min=least[j];
                    index=j;
                }
            }
            p[index]=in[i];
            pgfaultcnt++;
            dispPages();
        }
        else printf("hit");
    }
    printf("page faults=%d",pgfaultcnt);*/

    int usedcnt[100];
    int least,index,sofarcnt=0,bn=0,useindex;
    for(int i=0;i<nf;i++){
        usedcnt[i]=0;
    }
    for(int i=0;i<n;i++){
        printf("\nfor %d :",in[i]);
        if(ishit(in[i])){
            int hitindex=getHitIndex(in[i]);
            usedcnt[hitindex]++;
            printf("hit");

        }
        else{
            pgfaultcnt++;
            if(bn<nf){
                p[bn]=in[i];
                usedcnt[bn]++;
                bn++;
            }
            else{
                least=9999;
                for(k=0;k<nf;k++){
                    if(usedcnt[k]<least){
                        least=usedcnt[k];
                        index=k;
                    }
                } 
                p[index]=in[i];
                usedcnt[index]--;
                sofarcnt=0;

                for(k=0;k<=i;k++){
                    if(in[i]==in[k]) sofarcnt++;
                }
                usedcnt[index]=sofarcnt;
            }
             dispPages();
        }
    } printf("page faults=%d",pgfaultcnt);
}