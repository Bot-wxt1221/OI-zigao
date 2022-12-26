#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int groups_w[20][40],groups_v[20][40];
int dp[210];

int main(){
	#ifdef file
	freopen("group.in", "r", stdin);
	freopen("group.out", "w", stdout);
	#endif

    register int i,j,k,l;
    int C=read();
    int n=read();
    int T=read();
    for(i=0;i<n;++i){
        j=read();
        k=read();
        l=read();
        groups_w[l][++groups_w[l][0]]=j;
        groups_v[l][++groups_v[l][0]]=k;
    }

    for(i=1;i<=T;++i)
        for(j=C;~j;--j)
            for(k=1;k<=groups_w[i][0];++k)
                if(groups_w[i][k]<=j)
                    dp[j]=std::max(dp[j],dp[j-groups_w[i][k]]+groups_v[i][k]);

    print(dp[C]);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

