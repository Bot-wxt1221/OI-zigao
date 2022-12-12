#include <cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

int n,L,head,tail,Q[50010];
double sum[50010],dp[50010];
double a(int i){return sum[i]+i;}
double b(int i){return a(i)+L+1;}
double X(int i){return b(i);}
double Y(int i){return dp[i]+b(i)*b(i);}
double slope(int i,int j){return (Y(i)-Y(j))/(X(i)-X(j));}

// int slope(int i,int j){re}

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    register int i;
    n=read();
    L=read();

    for(i=1;i<=n;++i) sum[i]=read(),sum[i]+=sum[i-1];

    head=tail=1;

    for(i=1;i<=n;++i){
        while(head<tail&&slope(Q[head],Q[head+1])<(a(i)*2)) ++head;
        dp[i]=dp[Q[head]]+(a(i)-b(Q[head]))*(a(i)-b(Q[head]));
        while(head<tail&&slope(i,Q[tail-1])<slope(Q[tail-1],Q[tail])) --tail;
        Q[++tail]=i;
    }

    printf("%lld",(long long )dp[n]);

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