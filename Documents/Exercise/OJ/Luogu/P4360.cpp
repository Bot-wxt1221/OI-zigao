#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int


INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int totsum,w[20010],dis[20010],sum[20010],Q[20010],dp[20010];

int B(int i){return -totsum+dis[i]*sum[i];}
int K(int i){return -dis[i];}
int X(int j){return sum[j];}
int Y(int j){return -dis[j]*sum[j];}
long double slope(int i,int j){return ((X(i)-X(j))==0)?(1e18):(Y(i)-Y(j))/((X(i)-X(j)));}

int main(){
    register int i,j,head=1,tail=1,ans=0x7fffffff;
    int n=read();
    for(i=1;i<=n;++i) w[i]=read(),dis[i]=read();
    for(i=n;i;--i) dis[i]=dis[i+1]+dis[i];
    for(i=1;i<=n;++i) sum[i]=w[i]+sum[i-1],totsum+=dis[i]*w[i];

    Q[tail]=0;

    for(i=1;i<=n;++i){
        while(head<tail&&slope(Q[head],Q[head+1])<(K(i)*1.0)) ++head;
        j=Q[head];
        dp[i]=Y(Q[head])-K(i)*X(Q[head])-B(i);
        ans=std::min(ans,dp[i]);
        while(head<tail&&slope(i,Q[tail-1])<slope(Q[tail-1],Q[tail])) --tail;
        Q[++tail]=i;
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