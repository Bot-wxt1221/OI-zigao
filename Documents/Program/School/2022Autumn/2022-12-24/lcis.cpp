#include<cstdio>
#include<algorithm>

#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
int dp[3010][3010];
int s1[3010];
int s2[3010];

int main(){
	#ifdef file
	freopen("lcis.in", "r", stdin);
	freopen("lcis.out", "w", stdout);
	#endif

    register int i,j,k,l,ans=0,max;
    int n=read();
    for(i=1;i<=n;++i) s1[i]=read();
    for(i=1;i<=n;++i) s2[i]=read();


    for(i=1;i<=n;++i){
        max=1;
        for(j=1;j<=n;++j){
            dp[i][j]=dp[i-1][j];
            if(s1[i]==s2[j]){
                dp[i][j]=std::max(max,dp[i][j]);
            }
            if(s1[i]>s2[j]){
                max=std::max(max,dp[i-1][j]+1);
            }
            ans=std::max(ans,dp[i][j]);
        }
    }

    print(ans);


    return 0;
}

