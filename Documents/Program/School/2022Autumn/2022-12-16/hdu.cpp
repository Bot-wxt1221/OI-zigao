#include <cstdio>
#include <cstring>
#include <algorithm>
//#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int v[2001],w[2001],dp[2001];

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    int T=read();
    register int i,j;
    int n,C;
    while(T--){
        memset(dp,0,sizeof(dp));
        n=read();
        C=read();
        for(i=0;i<n;++i) v[i]=read();
        for(i=0;i<n;++i) w[i]=read();
        dp[0]=0;
        for(i=0;i<n;++i)
            for(j=C;j>=w[i];--j)
                dp[j]=std::max(dp[j-w[i]]+v[i],dp[j]);

        printf("%d",dp[C]);
        putchar('\n');
    }



	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
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