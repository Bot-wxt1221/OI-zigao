#include <cstdio>
#include <algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int dp[110][110],arr[110][110];

int main(){
	#ifdef file
	freopen("peanut.in", "r", stdin);
	freopen("peanut.out", "w", stdout);
	#endif

    register int i,j;
    int T=read(),r,c;
    while(T--){
        r=read();c=read();
        for(i=1;i<=r;++i)
            for(j=1;j<=c;++j)
                arr[i][j]=read(),dp[i][j]=0;
        for(i=1;i<=r;++i)
            for(j=1;j<=c;++j)
                dp[i][j]=std::max(dp[i-1][j],dp[i][j-1])+arr[i][j];
        print(dp[r][c]);
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