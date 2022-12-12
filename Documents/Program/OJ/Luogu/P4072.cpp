#include <cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

int n,L,Q[50010];
long long sum[50010],dp[50010],sig;
long long k(int i){return 2*n*sum[i];};
long long x(int j){return sum[j-1];};
long long b(int i){return 2*n*sig*sum[i]-(n*n)*(sum[i]*sum[i])-(sig*sig);}
long long y(int j){return 2*n*sig*sum[j-1]+dp[j]+(n*n)*(sum[j-1]*sum[j-1]);};
double slope(int i,int j){return (y(i)-y(j))/(x(i)-x(j)==0?(1e-9):x(i)-x(j));}

// int slope(int i,int j){re}

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
     int i,head,tail;
    int n=read();
    int m=read();
    for(i=1;i<=n;++i) sum[i]=read(),sum[i]+=sum[i-1];

    sig=sum[n];

    head=tail=1;

    for(i=1;i<=m;++i){
        while(head<tail&&slope(Q[head],Q[head+1])<(k(i))) ++head;
        if(i!=1) dp[i]=y(Q[head])-k(i)*x(Q[head])-b(i);
        else dp[i]=(sum[1]*n-sig)*(sum[1]*n-sig);
        while(head<tail&&slope(i,Q[tail-1])<slope(Q[tail-1],Q[tail])) --tail;
        Q[++tail]=i;
    }

    printf("%lld",dp[m]*m/(n*n));

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