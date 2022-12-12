#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int arr[100];
int dp[200][200];

int main(){
    register int i,j,l,ans=0;
    int n=read();

    for(i=1;i<=n;++i) arr[i]=arr[i+n]=read();

    for(l=1;l<n;++l)
        for(i=1;i+l<=(n<<1);++i)
            for(j=i;j<i+l;++j)
                dp[i][i+l]=std::max(dp[i][i+l],dp[i][j]+dp[j+1][i+l]+arr[i]*arr[j+1]*arr[i+l+1]);

    for(i=1;i<=n;++i)
        ans=std::max(ans,dp[i][i+n-1]);

    printf("%d",ans);

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