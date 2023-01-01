#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

int n,a,b,c,q[1000010];
long long sum_x[1000010],dp[1000010];

long long K(int i){return 2*a*sum_x[i];}
long long X(int j){return sum_x[j];}
long long B(int i){return -a*sum_x[i]*sum_x[i]-b*sum_x[i]-c;}
long long Y(int j){return a*sum_x[j]*sum_x[j]-b*sum_x[j]+dp[j];}
double slope(int i,int j){return (Y(i)-Y(j))*1.0/(X(i)-X(j));}

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    register int i,head,tail;
    n=read();
    a=read();
    b=read();
    c=read();

    for(i=1;i<=n;++i){
        sum_x[i]=read();
        sum_x[i]+=sum_x[i-1];
    }

    head=tail=1;

    for(i=1;i<=n;++i){
        while(head<tail&&slope(q[head],q[head+1])>=K(i)) ++head;
        dp[i]=Y(q[head])-K(i)*X(q[head])-B(i);
        while(head<tail&&slope(i,q[tail-1])>=slope(q[tail-1],q[tail])) --tail;
        q[++tail]=i;
    }

    printf("%lld",dp[n]);

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