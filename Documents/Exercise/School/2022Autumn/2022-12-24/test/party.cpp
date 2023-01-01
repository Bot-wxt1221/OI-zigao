#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int a[510];
int w[510];
int v[510];
int dp[6010];

int main(){
	#ifdef file
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	#endif

    register int i,j,k;
    int n=read();
	int C=read();
	for(i=0;i<n;++i) w[i]=read(),v[i]=read(),a[i]=read();

    for(i=0;i<n;++i)
        for(j=0;j<a[i];++j)
            for(k=C;k>=w[i];--k)
                dp[k]=std::max(dp[k],dp[k-w[i]]+v[i]);

    print(dp[C]);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

