#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int dp[2001][2001];

int main(){
    register int i,j,l,ans=0;
    int n=read();
    int k=read();
    for(i=1;i<=n;++i) dp[1][i]=1;
    for(i=1;i<k;++i)
        for(j=1;j<=n;++j)
            for(l=j;l<=n;l+=j)
                dp[i+1][l]=(dp[i+1][l]+dp[i][j])%1000000007;

    for(i=1;i<=n;++i)
        ans=((dp[k][i]+ans)%1000000007);

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