#include<cstdio>
#include<algorithm>
#define maxn (500+10)
#define maxw (45000+10)

int arr[maxn],f[maxw];

int read();

int main(){
    int w=read();
    int n=read();

    for(register int i=1;i<=n;++i){
        arr[i]=read();
    }

    for(register int i=1;i<=n;++i)
        for(register int j=w;j>=arr[i];--j)
            f[j]=std::max(f[j-arr[i]]+arr[i],f[j]);

    printf("%d",f[w]);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}