#include <cstdio>
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE int

int n,q[500010],k;
long long sum[500010],a[500010],dp[500010],i_watch1,i_watch2,i_watch3,i_watch4;
bool watch,watch2,watch3;

long long K(int i){return i;}
long long X(int j){return a[j+1];}
long long B(int i){return -sum[i];}
long long Y(int j){return dp[j]-sum[j]+a[j+1]*j;}
long double slope(int i,int j){return (X(i)==X(j)?1e18:(Y(i)-Y(j))*1.0/(X(i)-X(j)));}
bool check1(int p1,int p2,int p3,int p4){
    watch=(slope(p1,p2)<=slope(p3,p4));
    i_watch1=X(p1)-X(p2);
    i_watch2=Y(p1)-Y(p2);
    i_watch3=X(p3)-X(p4);
    i_watch4=Y(p3)-Y(p4);
    watch2=(((Y(p1)-Y(p2))*(X(p3)-X(p4)))<=((Y(p3)-Y(p4))*(X(p1)-X(p2))));
    watch3=((X(p1)==X(p2)?1e18:((Y(p1)-Y(p2))*1.0/(X(p1)-X(p2))))<=(X(p3)==X(p4)?1e18:((Y(p3)-Y(p4))*1.0/(X(p3)-X(p4)))));
    return watch2;
}
bool check2(int p1,int p2,int i){
    watch=(slope(p1,p2)<=K(i));
    watch2=((X(p1)-X(p2)==0)?false:((Y(p1)-Y(p2))>=(K(i)*(X(p1)-X(p2)))));
    watch3=((X(p1)==X(p2)?1e18:((Y(p1)-Y(p2))*1.0/(X(p1)-X(p2))))<=(K(i)*1.0));
    i_watch1=X(p1)-X(p2);
    i_watch2=Y(p1)-Y(p2);
    i_watch3=K(i);
    return watch2;
}

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
    int T=read();

    while(T--){
    register int i,head,tail;
    n=read();
    k=read();

    dp[0]=0;

    for(i=1;i<=n;++i){
        if(i<k) dp[i]=0x3f3f3f3f3f3f3f3fll;
        a[i]=sum[i]=read();
        sum[i]+=sum[i-1];
    }

    head=tail=1;

    for(i=k;i<=n;++i){
        // while(head<tail&&slope(i-k,q[tail-1])<=slope(q[tail-1],q[tail])) --tail;
        while(head<tail&&check1(i-k,q[tail-1],q[tail-1],q[tail])) --tail;
        q[++tail]=i-k;
        // while(head<tail&&(slope(q[head],q[head+1])<=K(i)*1.0)) ++head;
        while(head<tail&&(check2(q[head],q[head+1],i))) ++head;
        dp[i]=Y(q[head])-K(i)*X(q[head])-B(i);
    }

    printf("%lld\n",dp[n]);
    }

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