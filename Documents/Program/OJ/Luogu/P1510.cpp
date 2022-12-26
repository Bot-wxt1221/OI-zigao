#include<cstdio>
#include<algorithm>
#define maxdata (10000+10)
#define mx(a,b) ((a)>(b)?(a):(b))

int w[maxdata],v[maxdata],f[maxdata];

int read();

int main(){
    int ww=read();
    int n=read();
    int c=read();

    for(register int i=1;i<=n;++i) v[i]=read(),w[i]=read();

    for(register int i=1;i<=n;++i)
        for(register int j=c;j>=w[i];--j)
            f[j]=mx(f[j-w[i]]+v[i],f[j]);


    if(f[c]<ww)
        printf("Impossible");
    else{
        int add=std::lower_bound(f+1,f+c+1,ww)-f;
        printf("%d",c-add);
    }

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}