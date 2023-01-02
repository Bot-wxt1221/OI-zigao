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
int dp[100005][2],k,b;
int dis(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int y(int j,int m){
    return dp[j][m%2]+p[j].x*p[j].x+p[j].y*p[j].y-2*p[j].y*b;
}
int ka(int i){
    return 2*q[i].x;
}
int x(int j){
    return p[j].x+p[j].y*k;
}
int kb(int i,int m){
    return dp[i][m%2]-dis(p[i],q[i])-q[i].x*q[i].x-q[i].y*q[i].y;
}
int que[100005];
int l=0,r=0;
signed main(){
	// freopen("C:\\Users\\Administrator\\Desktop\\OI\\compare.in","r",stdin);
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
        l=r=1;
        que[l]=j-1;
        for(int i=j;i<=n;i++){
            while(l<r&&(y(que[l],j-1)-y(que[l+1],j-1))>ka(i)*(x(que[l])-x(que[l+1]))){
                l++;
            }
            int &to=que[l];
            dp[i][j%2]=dp[to][(j-1)%2]+dis(q[i],p[i])+dis(p[to],q[i]);
            while(l<r&&((y(i,j-1)-y(que[r],j-1))*(x(que[r])-x(que[r-1])))<((x(i)-x(que[r]))*(y(que[r],j-1)-y(que[r-1],j-1)))){
                r--;
            }
            que[++r]=i;
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