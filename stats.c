#include <stdio.h>
#include <stdlib.h>
void findStats(int n,int *nums,int *maxi,int *mini,double *avg ) {
    double sum;
    *maxi=*mini=nums[0];
    for (int i =0;i<n;i++){
        sum+=nums[i];
        if (nums[i]>*maxi){
            *maxi=nums[i];
        }
        if (nums[i]<*mini){
            *mini=nums[i];
        }
    }
    *avg=sum/n;
}
int main(){
    int n,i,maxi,mini;
    double avg;
    int *nums;

    scanf("%d",&n);
    nums=(int *)malloc(sizeof (int) *n);
    for (i=0;i<n;i++){
        scanf("%d",nums+i);
    }
    findStats(n,nums,&maxi,&mini,&avg);
    printf("%.2f %d %d",avg,maxi,mini);
    return 0;
}