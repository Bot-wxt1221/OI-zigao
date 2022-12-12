#include <cstdio>
#define maxn (1000+10)
#define mx(a,b) ((a)>(b)?(a):(b))

int f1[maxn],f2[maxn];

int read();

int main(){
    int n=read();
    int best=0;

    for(register int i=1;i<=n;++i)
        for(register int j=2;j*i<=n;++j)
            f1[j*i]+=i;

    for(register int i=1;i<=n;++i)
        for(register int j=n;j>=i;--j){
            f2[j]=mx(f2[j],f1[i]+f2[j-i]);
            best=mx(f2[j],best);
        }

    printf("%d",best);


    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}