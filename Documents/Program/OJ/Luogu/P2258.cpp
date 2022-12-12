/*
5
8
12 15
3 9 6
8 10 5 12
16 4 18 19 9
*/
#include <cstdio>
#include <algorithm>

int ma[20][20],dp[20][20],s[20][20];
int que[20],q_i,n,m,r,c,_ans=0x3f3f3f3f;

int abs(int x){
    return x<0?-x:x;
}

int read(){
    register int x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void dfs(int step){
    if(step==r+1){
        register int i,j,k,l,ans;
        for(i=0;i<=m;++i)
            for(j=i+1;j<=m;++j){
                s[i][j]=0;
                for(l=1;l<=r;++l){
                    ans=0;
                    if(i!=0) ans+=abs(ma[que[l]][i]-ma[que[l]][j]);
                    if(l!=r) ans+=abs(ma[que[l+1]][j]-ma[que[l]][j]);
                    s[i][j]+=ans;
                }
            }

        for(l=1;l<=c;++l)
            for(j=l-1;j<=m;++j)
                dp[j][l]=0x3f3f3f3f;
        for(l=1;l<=c;++l)
            for(j=l;j<=m;++j)
                for(k=l-1;k<j;++k)
                    dp[j][l]=std::min(dp[k][l-1]+s[k][j],dp[j][l]);

        k=0x3f3f3f3f;
        for(j=c;j<=m;++j)
            k=std::min(dp[j][c],k);
        _ans=std::min(k,_ans);
        return;
    }

    for(register int i=que[step-1]+1;i<=n;++i){
        que[step]=i;
        dfs(step+1);
    }

    return;
}

int main(){
    register int i,j;
    n=read();
    m=read();
    r=read();
    c=read();

    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            ma[i][j]=read();

    dfs(1);

    printf("%d",_ans);

    return 0;
}