#include<stdio.h>
int prime(int n,int c,int i){
    if (n%i==0){
        c+=1;
    }
    if (i==n){
        return c;
    } else if(c>2){
        return c;
    } else{
        return prime(n,c,i+1);
        
    }
}
int main(){
    int n,c=1,i=3;
    scanf("%d",&n);
    if (n==0 ||n==1){
        c=1 ;
    } else if (n==2 ){
        c+=1 ;
    } else if(n%2==0){
        c+=2 ;
    } else{
        c=prime(n,c,i);
    }
    if (c==2){
        //printf("c is %d\n",c);
        printf("1");
    } else{
        //printf("c is %d\n",c);
        printf("0");
    }
}