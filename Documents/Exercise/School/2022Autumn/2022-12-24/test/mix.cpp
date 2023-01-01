#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int w[40],v[40],p[40],dp[210];

int main(){
	#ifdef file
	freopen("mix.in", "r", stdin);
	freopen("mix.out", "w", stdout);
	#endif

    register int i,j,k;
    int C=read();
    int n=read();
    for(i=0;i<n;++i) w[i]=read(),v[i]=read(),p[i]=read();

    for(i=0;i<n;++i)
        if(p[i])
            for(k=0;k<p[i];++k)
                for(j=C;j>=w[i];--j)
                    dp[j]=std::max(dp[j],dp[j-w[i]]+v[i]);
        else
            for(j=w[i];j<=C;++j)
                dp[j]=std::max(dp[j],dp[j-w[i]]+v[i]);

    print(dp[C]);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

