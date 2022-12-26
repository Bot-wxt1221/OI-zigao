#include<cstdio>
#include<cstring>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int w1[1010],w2[1010],v[1010];

int dp[100][100];

int main(){
	#ifdef file
	freopen("gas.in", "r", stdin);
	freopen("gas.out", "w", stdout);
	#endif

    register int i,j,k;
    int W=read();
    int C=read();
    int n=read();
    for(i=0;i<n;++i)
        w1[i]=read(),w2[i]=read(),v[i]=read();

    memset(dp,0x7f,sizeof(dp));
    dp[0][0]=0;

    for(i=0;i<n;++i)
        for(j=W;j>=0;--j)
            for(k=C;k>=0;--k)
                if(j>=w1[i]&&k>=w2[i])
                    dp[j][k]=std::min(dp[j][k],dp[j-w1[i]][k-w2[i]]+v[i]);
                else if(j<w1[i]&&k<w2[i])
                    dp[j][k]=std::min(dp[j][k],v[i]);
                else if(j<w1[i])
                    dp[j][k]=std::min(dp[j][k],v[i]+dp[0][k-w2[i]]);
                else
                    dp[j][k]=std::min(dp[j][k],v[i]+dp[j-w1[i]][0]);

    print(dp[W][C]);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

