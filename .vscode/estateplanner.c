#include<stdio.h>
int size(int a){
    if (a == 0)
        return 0;
    while (a != 1) {
        if (a % 2 != 0)
            return 0;
        a = a / 2;
    }
    return 1;
}
int idk(int w,int l){
    int c=0,I;
    if (w>l){
        int x=w;
        w=l;
        l=x;
    }
    if (w==0||l==0){
        return 0;
    } else if (w==1||l==1){
        return w*l;
    } else {
        for (int i=w;i>0;i--){
            if (size(i)){
            c += 1;
            c += idk(i,l-i);
            c += idk(w-i,l);
            break;
        }
        }
        
    }
    return c;
}
int main(){
    int w,l,c=0;
    scanf("%d %d",&w,&l);
    c=idk(w,l);
    printf("c = %d",c);
}