#include <stdio.h>
int main(){
    int time,num,max=0;
    int data[101]={0};
    printf("time = "); 
    scanf("%d",&time);
    while (time>0){
        scanf("%d",&num);
        data[num]++;
        time--;
        if (max<data[num]){
            max=data[num];
        }
    }
    for (int i=0;i<=101;i++){
        if (data[i]==max){
            printf("%d ",i);
        }
    }
    return 0;
}
