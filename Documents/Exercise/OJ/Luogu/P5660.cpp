#include<cstdio>

int read();

int main(){
    int ans=0;
    ans+=getchar();
    ans+=getchar();
    ans+=getchar();
    ans+=getchar();
    ans+=getchar();
    ans+=getchar();
    ans+=getchar();
    ans+=getchar();

    putchar(ans-('0'<<3)+'0');

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}