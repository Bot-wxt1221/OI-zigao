#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int dp[110][110],arr[110][110];

int main(){
	#ifdef file
	freopen("tolls.in", "r", stdin);
	freopen("tolls.out", "w", stdout);
	#endif

    register int i,j;
    int r;
    r=read();
    for(i=1;i<=r;++i){
        dp[i][0]=0x3f3f3f3f;
        dp[0][i]=0x3f3f3f3f;
        for(j=1;j<=r;++j)
            arr[i][j]=read();
    }

    dp[1][0]=0;

    for(i=1;i<=r;++i)
        for(j=1;j<=r;++j)
            dp[i][j]=std::min(dp[i-1][j],dp[i][j-1])+arr[i][j];
    print(dp[r][r]);
    putchar('\n');

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