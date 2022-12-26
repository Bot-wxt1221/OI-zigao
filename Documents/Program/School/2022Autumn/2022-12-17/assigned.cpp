#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int V[25][25];
int dp[25][25],pre[25][25],stack[100];
/*
3 3
30 40 50
20 30 50
20 25 30
*/
int main(){
	#ifdef file
	freopen("assigned.in", "r", stdin);
	freopen("assigned.out", "w", stdout);
	#endif

    register int i,j,k;
    int n=read();
    int m=read();
    for(i=0;i<n;++i)
        for(j=1;j<=m;++j)
            V[i][j]=read();

    for(j=1;j<=m;++j)
        dp[0][j]=V[0][j];

    for(i=1;i<n;++i)
        for(j=0;j<=m;++j)
            for(k=0;k<=j;++k)
                if(dp[i-1][k]+V[i][j-k]>=dp[i][j])
                    dp[i][j]=dp[i-1][k]+V[i][j-k],pre[i][j]=k;

    j=0;
    --n;
    print(dp[n][m]);
    putchar('\n');

    while(n>=0){
        stack[j++]=m-pre[n][m];
        m=pre[n][m];
        --n;
    }

    i=1;
    while(j){
        print(i++);
        putchar(' ');
        print(stack[--j]);
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