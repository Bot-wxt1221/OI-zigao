#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN 100

int arr[MAXN],dp[MAXN];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
int abs(int x){
    return x<0?-x:x;
}

int count(int i,int k){
    if(i==k) return arr[i];
    return abs(arr[i]-arr[k])*(k-i+1);
}


int main(){
    int n=read();

    for(register int i=1;i<=n;++i){
        arr[i]=read();
        for(register int k=0;k<i;++k)
            dp[i]=std::max(dp[i],dp[k]+count(k+1,i));
    }

    printf("%d",dp[n]);

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