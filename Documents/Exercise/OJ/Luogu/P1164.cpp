#include<cstdio>
#define maxn (100+10)
#define maxm (10000+10)

int w[maxn],f[maxm];

int read();

int main(){
    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i) w[i]=read();

    f[0]=1;

    for(register int i=1;i<=n;++i)
        for(register int j=m;j>=w[i];--j)
            f[j]+=f[j-w[i]];

    printf("%d",f[m]);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}