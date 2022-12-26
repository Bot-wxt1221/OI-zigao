#include<cstdio>
#define maxn 32768

int f[maxn][5];

int read(){
    int x=0;char f=1,c=getchar();
    while(c<'0'||c>'9') f=(c=='-'?-1:1),c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return x*f;
}

int main(){
    f[0][0]=1;
    for(register int i=1;i*i<=maxn;++i)
        for(register int j=i*i;j<=maxn;++j)
            for(register int k=1;k<=4;++k)
                f[j][k]+=f[j-i*i][k-1];

    register int T=read();
    register int n;
    while(T--){
        n=read();
        printf("%d\n",f[n][1]+f[n][2]+f[n][3]+f[n][4]);
    }
}