#include<cstdio>
#include<cstring>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE long long 
#define OUTPUT_DATA_TYPE long long 
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

long long w[11],v[11];
long long  dp[1000010];

int main(){
	#ifdef file
	freopen("busses.in", "r", stdin);
	freopen("busses.out", "w", stdout);
	#endif

    register long long  i,j;
    long long  n=10;
    for(i=1;i<=n;++i) w[i]=i,v[i]=read();
    long long C=read();
    memset(dp,0x7f,sizeof(dp));
    dp[0]=0;
    for(i=1;i<=n;++i)
        for(j=w[i];j<=C;++j)
            dp[j]=std::min(dp[j-w[i]]+v[i],dp[j]);

    print(dp[C]);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

