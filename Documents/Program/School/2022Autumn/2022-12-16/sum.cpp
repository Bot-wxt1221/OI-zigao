#include <cstdio>
#include <algorithm>
// #define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int a[3010];
char dp[4000];

int main(){
	#ifdef file
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	#endif

    register int i,j,W=0;
    int n=read();
    for(i=0;i<n;++i) a[i]=read(),W+=a[i];

    dp[0]=1;
    W=std::min(W,2100);

    for(i=0;i<n;++i)
        for(j=W;j>=a[i];--j)
            dp[j]|=dp[j-a[i]];

    n=read();
    while(n--)
        if(dp[read()])
            puts("yes");
        else
            puts("no");

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