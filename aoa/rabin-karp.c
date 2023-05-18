#include<stdio.h>
#include<string.h>
# define d 2
void matcher(char pattern[],char text[],int q){
    int n=strlen(text),m=strlen(pattern);
    int p=0;
    int t=0,i,j;
    int h=2;
    for( i=0;i<m-1;i++){
        h=(h*d)%q;
    }
    
    for(int i=0;i<m;i++){
        p=((d*p)+pattern[i])%q;
        
        t=((d*t)+text[i])%q;
    }

    for(i=0;i<=n-m;i++){
        
        if(p==t){
            for(j=0;j<m;j++){
                if(text[i+j]!=pattern[j])
                break;
            }

            if(j==m) printf("pattern at index: %d ",i);
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0) t=t+q; 
        }
    }

   
}


void main(){
    matcher("xyxydf","xyzahxyxydfxyzd",2 );
}