#include<stdio.h>
int check(int z,int b){
    while(z!=0){
        int y = z;
        y %= 10;
        if(y==b){
            return 1;
        }
        z /= 10;
    }  
    return 0;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int arr[a];
    for(int i = 0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    int y=a;
    int z=0;
    int m=1;
    while(y>1){
        if(arr[z%a]<0){
            z++;
            continue;
        }
        if(m%b==0||check(m,b)){
            arr[(z%a)] -= 1;
            if(arr[z%a]<0){
                y--;
            }   
        }
        m++;
        z++;
    }  
    for(int k = 0;k<a;k++){
            if(arr[k]>=0){
                printf("%d",k+1);
            }
        }
}