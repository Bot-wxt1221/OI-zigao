#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN (100+10)

char map[MAXN][MAXN];
int dp[MAXN][MAXN],best;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    int n=read();
    int m=read();

    for(register int i=1,j,x,y;i<=n;++i)
        for(j=1;j<=m;++j){
            map[i][j]=read();
            if(map[i][j]){
                x=i-1;
                y=j-1;
                for(;i-x<=dp[i-1][j-1];x--)
                    if(!map[x][j])
                        break;
                for(;(j-y<=dp[i-1][j-1])&&((j-y)<=i-x);y--)
                    if(!map[i][y])
                        break;
                dp[i][j]=std::min(i-x,j-y);
                best=std::max(best,dp[i][j]);
            }
        }

    print(best);

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    char s[20];
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