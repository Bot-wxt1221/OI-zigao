#include <cstdio>
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

long long dp[20],pow[20],num[20],ansl[20],ansr[20];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
void solve(long long n,long long* ans){
    long long temp=n;
    register int len=0,i,j;
    while(n) num[++len]=n%10,n/=10;
    for(i=len;i;--i){
        for(j=0;j<10;++j) ans[j]+=dp[i-1]*num[i];
        for(j=0;j<num[i];++j) ans[j]+=pow[i-1];
        temp-=num[i]*pow[i-1],ans[num[i]]+=temp+1;
        ans[0]-=pow[i-1];
    }
    return;
}

int main(){
    register int i;
    long long l,r;
    l=read();
    r=read();

    pow[0]=1;

    for(i=1;i<=15;++i)
        dp[i]=dp[i-1]*10ll+pow[i-1],pow[i]=pow[i-1]*10ll;

    solve(l-1,ansl);
    solve(r,ansr);
    for(i=0;i<10;++i){
        print(ansr[i]-ansl[i]);
        putchar(' ');
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
    register char s[30];
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