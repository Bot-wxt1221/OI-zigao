#include<cstdio>
#include<algorithm>

#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
int dp[2][5010];
char s1[5010];
char s2[5010];


int main(){
	#ifdef file
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
	#endif

    register int i,j,ans=0x3f3f3f3f;
    int n=read();
    scanf("%s",s1+1);
    for(i=1;i<=n;++i) s2[n-i+1]=s1[i];


    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j){
            dp[i&1][j]=std::max((dp[(i-1)&1][j-1]+(s1[i]==s2[j])),std::max(dp[(i-1)&1][j],dp[i&1][j-1]));
        }



    print(n-dp[n&1][n]);

    return 0;
}

