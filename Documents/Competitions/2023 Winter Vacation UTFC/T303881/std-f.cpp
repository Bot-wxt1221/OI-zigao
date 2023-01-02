#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
class node{
    public:
        int x,y;
        node(int nx=0,int ny=0){
            x=nx;
            y=ny;
        }
}p[100005],q[100005];
int dp[100005][5],k,b;
int dis(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	// freopen("a.in","r",stdin);
	// freopen("a.out","w",stdout);
	#endif
    int n=read(),m=read();
    k=read();
    b=read();
    int k2=read();
    int b2=read();
    for(int i=1;i<=n;i++){
        q[i].x=read();
        q[i].y=q[i].x*k+b;
        p[i].x=read();
        p[i].y=p[i].x*k2+b2;
        dp[i][1]=dis(p[i],q[i])+dis(node(0,0),q[i]);
    }
    for(int j=2;j<=m;j++){
        for(int i=1;i<=n;i++){
            dp[i][j%2]=0x3f3f3f3f3f3f3f3fll;
            for(int k=1;k<i;k++){
                dp[i][j%2]=std::min(dp[i][j%2],dp[k][(j-1)%2]+dis(p[i],q[i])+dis(q[i],p[k]));
            }
        }
    }
    int ans=0x3f3f3f3f3f3f3f3fll;
    for(int i=m;i<=n;i++){
        ans=std::min(ans,dp[i][m%2]);
    }
    printf("%lld",ans);
	return 0;
}
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/

