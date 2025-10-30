#include<stdio.h>
int min(int a,int b,int c,int d){
    a=a<b?a:b;
    c=c<d?c:d;
    return a<c?a:c;
}
int main(){
    int n,left,right,top,down;
    int i=0,j=0;
    scanf("%d",&n);
    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            top=i;
            down=(2*n)-2-i;
            left=j;
            right=(2*n)-2-j;
            printf("%d ",min(t,d,l,r)+1);
        }
        printf("\n");
    }
    return 0;
}
