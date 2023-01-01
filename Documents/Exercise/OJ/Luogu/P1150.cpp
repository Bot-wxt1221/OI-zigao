#include<cstdio>

int read();

int main(){
    register int s=read();
    register int n=s;
    register int k=read();

    while(n>=k){
        s+=n/k;
        n=n%k+n/k;
    }

    printf("%d",s);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}