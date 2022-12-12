#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN (100+10)

int arr[MAXN],dp1[MAXN],dp2[MAXN];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    int n=read();
    register int best=0;

    for(register int i=0;i<n;i++) arr[i]=read(),dp1[i]=dp2[i]=1;

    for(register int i=0;i<n;++i)
        for(register int j=0;j<i;++j)
            if(arr[i]>arr[j]) dp1[i]=std::max(dp1[j]+1,dp1[i]);

    for(register int i=n-1;i>=0;--i)
        for(register int j=n-1;j>i;--j)
            if(arr[i]>arr[j]) dp2[i]=std::max(dp2[j]+1,dp2[i]);

    for(register int i=0;i<n;++i)
        best=std::max(best,dp1[i]+dp2[i]-1);

    print(n-best);

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    char s[20];
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