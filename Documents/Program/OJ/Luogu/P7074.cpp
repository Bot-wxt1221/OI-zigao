#include<cstdio>
#include<algorithm>
#define maxn (1000+10)
int read();
int map[maxn][maxn],ans[maxn][maxn];

int main(){
    int n=read();
    int m=read();

    for(register int i=1;i<=n;i++)
        for(register int j=1;j<=m;j++)
            map[i][j]=read();

    ans[1][1]=map[1][1];

    for(register int i=1;i<=n;i++)
        for(register int j=1;j<=m;j++){
            ans[i][j]=std::max(ans[i+1][j],std::max(ans[i-1][j],ans[i][j-1]))+map[i][j];
            // ans[i+1][j]=std::max(ans[i][j]+map[i+1][j],ans[i+1][j]);
            // ans[i-1][j]=std::max(ans[i][j]+map[i-1][j],ans[i-1][j]);
            // ans[i][j+1]=std::max(ans[i][j]+map[i][j+1],ans[i][j+1]);
        }

    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=m;j++)
            printf("%d ",ans[i][j]);
        putchar('\n');
    }


    printf("%d",ans[n][m]);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}