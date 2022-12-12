#include <cstdio>

struct node{
    int a,b,xlen,ylen;
}arr[10000+10];

int read();

int main(){
    int n=read();

    for(register int i=1;i<=n;++i){
        arr[i].a=read();
        arr[i].b=read();
        arr[i].xlen=read();
        arr[i].ylen=read();
    }

    int x=read();int y=read();
    int ans=-1;

    for(register int i=1;i<=n;++i)
        if((x>=arr[i].a&&x<=(arr[i].a+arr[i].xlen))&&(y>=arr[i].b&&y<=(arr[i].b+arr[i].ylen))) ans=i;

    printf("%d",ans);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}