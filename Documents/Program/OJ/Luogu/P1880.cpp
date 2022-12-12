#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int a[210],sum[210],f[210][210];

int main(){
    int n=read();
    register int l,i,j,ans;
    for(i=1;i<=n;++i) a[i+n]=a[i]=read();
    for(i=1;i<=(n<<1);++i) sum[i]=a[i]+sum[i-1];

    for(i=1;i<=n*2;++i)
        for(j=1;j<=n*2;++j)
            if(i!=j) f[i][j]=0x3f3f3f3f;
            else f[i][j]=0;

    for(l=1;l<n;++l)
        for(i=1;i+l<=(n<<1);++i)
            for(j=i;j<i+l;++j)
                f[i][i+l]=std::min(f[i][j]+f[j+1][i+l]+sum[i+l]-sum[i-1],f[i][i+l]);

    ans=0x3f3f3f3f;

    for(i=1;i<=n;++i){
        ans=std::min(ans,f[i][i+n-1]);
    }

    print(ans);
    putchar('\n');

    for(i=1;i<=n*2;++i)
        for(j=1;j<=n*2;++j)
            f[i][j]=0;

    for(l=1;l<n;++l)
        for(i=1;i+l<=(n<<1);++i)
            for(j=i;j<i+l;++j)
                f[i][i+l]=std::max(f[i][j]+f[j+1][i+l]+sum[i+l]-sum[i-1],f[i][i+l]);

    ans=0;

    for(i=1;i<=n;++i){
        ans=std::max(ans,f[i][i+n-1]);
    }

    print(ans);


    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
        putchar('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}