#include<cstdio>
#define maxt (10000000+10)
#define maxm (10000+10)
#define mx(a,b) ((a)>(b)?(a):(b))

long long v[maxm],w[maxm],f[maxt];

int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}

int main(){
    int t=read();
    int m=read();

    for(register int i=1;i<=m;++i) v[i]=read(),w[i]=read();

    for(register int i=1;i<=m;++i)
        for(register int j=v[i];j<=t;++j)
            f[j]=mx(f[j-v[i]]+w[i],f[j]);

    printf("%lld",f[t]);

    return 0;
}