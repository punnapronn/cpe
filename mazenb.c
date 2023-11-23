#include <stdio.h>
int main(){
    int n,p,now,next,a,b;
    scanf("%d %d",&n,&p);
    int num[n][n];
    if (p==1){
        for (int i=1;i<=n;i++){
            now=i;
            for (int j=1;j<=n;j++){
                printf("%d ",now);
                now+=n;
            }
            printf("\n");
        }
    }
    if (p==2){
        for (int i=1;i<=n;i++){
            next=now=i;
            for (int j=1;j<=n;j++){
                if (j%2==1){
                    now=next;
                    printf("%d ",now); 
                    next+=(2*n);
                }
                if (j%2==0){
                    printf("%d ",now+((2*n)-(1+2*(i-1))));
                }
            }
            printf("\n");
        }  
    }
    if (p==3){
        now=1;
        for (int i=1;i<=n;i++){
            if(i%2==0){
                for (a=n-i,b=0;a<n,b<i;a++,b++){
                    num[a][b]=now++;
                }
            }
            else{
                for(a=n,b=i;a>=n-i+1,b>=1;a--,b--){
                    num[a-1][b-1]=now++;
                }
            }
        }
        for(int i=1;i<n;i++){
            if((i%2==0 && n%2==1) || (i%2==1 && n%2==0)){
                for(a=n-i,b=n;a>=1,b>=i+1;a--,b--){
                    num[a-1][b-1]=now++;
                }
            }
            else{
                for(a=0,b=i;a<n-i,b<n;a++,b++){
                    num[a][b]=now++;
                }
            }
        }
        for (a=0;a<n;a++){
            for(b=0;b<n;b++){
                printf("%d ",num[a][b]);
            }
            printf("\n");
        }
    }
    if (p==4){
        int now=1;
        int top=0,under=n-1,left=0,right=n-1;
        while (now<=n*n){
            for(a=top;a<=under;a++){
                num[a][left]=now++;
            }
            left++;
            for (b=left;b<=right;b++){
                num[under][b]=now++;
            }
            under--;
            for (a=under;a>=top;a--){
                num[a][right]=now++;
            }
            right--;
            for (b=right ; b>=left ; b--){
            num[top][b] = now++;
        }
        top++;
        }
        for (a=0;a<n;a++){
            for(b=0;b<n;b++){
                printf("%d ",num[a][b]);
            }
            printf("\n");
        }
    }
}