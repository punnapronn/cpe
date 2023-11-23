#include <stdio.h>
int a[100100];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        int j=i-1;
        int temp=a[i];
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
        for(int k=0;k<n;k++) printf("%d ",a[k]);
        printf("\n");
    }
    return 0;
}
