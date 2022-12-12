#include <cstdio>
#define maxn (3402+10)
#define maxm (12880+10)
#define mx(a,b) ((a)>(b)?(a):(b))

int f[maxm],w[maxn],v[maxn];

int read();

int main(){
    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i) w[i]=read(),v[i]=read();

    for(register int i=1;i<=n;++i)
        for(register int j=m;j>=w[i];--j)
            f[j]=mx(f[j],f[j-w[i]]+v[i]);

    printf("%d",f[m]);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
} 