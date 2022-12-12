#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long


INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

long long x[1000010],p[1000010],c[1000010],sum_p[1000010],sum_px[1000010],Q[1000010],dp[1000010];

long long B(int i){return -c[i]-x[i]*sum_p[i]+sum_px[i];}
long long K(int i){return x[i];}
long long X(int j){return sum_p[j];}
long long Y(int j){return dp[j]+sum_px[j];}
long double slope(int i,int j){return ((X(i)-X(j))==0)?(1e18):(Y(i)-Y(j))/((X(i)-X(j)));}

int main(){
    register int i,head=1,tail=1,mem;
    // register long long ans=(1e18);
    int n=read();
    // sum_p[0]=1;
    for(i=1;i<=n;++i){
        x[i]=read();
        sum_p[i]=p[i]=read();
        c[i]=read();
        sum_p[i]+=sum_p[i-1];
        sum_px[i]=p[i]*x[i];
        sum_px[i]+=sum_px[i-1];
    }

    Q[tail]=0;

    for(i=1;i<=n;++i){
        while(head<tail&&slope(Q[head],Q[head+1])<(K(i)*1.0)) ++head;
        dp[i]=Y(Q[head])-K(i)*X(Q[head])-B(i);
        while(head<tail&&slope(i,Q[tail-1])<slope(Q[tail-1],Q[tail])) --tail;
        Q[++tail]=i;
    }

    long long haq=0x3f3f3f3f3f3f;
    for(int i=n;i>=1;i--){
        haq=std::min(haq,dp[i]);
        if(p[i])break;
    }
    printf("%lld\n",haq);



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