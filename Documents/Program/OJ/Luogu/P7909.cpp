#include <cstdio>
#define mn(a,b) ((a)<(b)?(a):(b))

int read();

int main(){
    int n=read();
    int l=read();
    int r=read();
    int mx=(l/n)*n;
    printf("%d",mn(n-1,r-mx));

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}