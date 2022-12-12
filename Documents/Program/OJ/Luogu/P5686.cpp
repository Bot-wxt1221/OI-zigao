#include <cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
// #define MAXN (500000+10)
#define MAXN (500000+10)

long long a[MAXN],b[MAXN],prea[MAXN],preb[MAXN],ab[MAXN],preab[MAXN],preprea[MAXN],prepreb[MAXN];

INPUT_DATA_TYPE read();
void print(int x);

int main(){
    int n=read();
    register const int mod=1e9+7;
    register long long sum=0;

    for(register int i=1;i<=n;++i){
        a[i]=read();
        prea[i]=(a[i]+prea[i-1])%mod;
        preprea[i]=(prea[i]+preprea[i-1])%mod;
    }

    for(register int i=1;i<=n;++i){
        b[i]=read();
        preb[i]=(b[i]+preb[i-1])%mod;
        prepreb[i]=(preb[i]+prepreb[i-1])%mod;
        ab[i]=(prea[i]*preb[i])%mod;
        preab[i]=(ab[i]+preab[i-1])%mod;
    }

    for(register int i=1;i<=n;++i)
        sum=(sum+(preab[n]-preab[i-1])+(ab[i-1])*(n-i+1)-(prea[i-1]*(prepreb[n]-prepreb[i-1])%mod+preb[i-1]*(preprea[n]-preprea[i-1])%mod)%mod+mod)%mod;


    printf("%d",sum);

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
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
}