#include<cstdio>
#define maxn 100+5
#define maxm 100+5
#define mod (1000000+7)

int a[maxn],f[maxn][maxm];

int read(){
    int x=0;char f=1,c=getchar();
    while(c<'0'||c>'9') f=(c=='-'?-1:1),c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return x*f;
}

int mn(int a,int b){
    if(a<=b)
        return a;
    return b;
}

int main(){
    int n=read();
    int m=read();

    for(register int i=1;i<=n;++i)
        a[i]=read();

    f[0][0]=1;
    for(register int i=1;i<=n;++i)
        for(register int j=0;j<=m;++j)
            for(register int k=0;k<=mn(a[i],j);++k)
                f[i][j]=(f[i][j]+f[i-1][j-k])%mod;

    printf("%d",f[n][m]);
}