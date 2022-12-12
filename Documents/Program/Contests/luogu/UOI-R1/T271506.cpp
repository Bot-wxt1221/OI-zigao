#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int p[5005];
int q[5005];
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen("sum2.in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    int n=read();
    int _max=0;
    for(int i=1;i<=n;i++){
        p[i]=read();
        q[i]=read();
        _max=std::max(_max,q[i]);
    }
    int ans=0;
    int pre=0;
    for(int i=1;i<=_max;i++){
        int sum=1;
        for(int j=1;j<=n;j++){
            if(q[j]>=i&&i>=p[j]){
                sum*=std::max(0ll,i-p[j]+1);
            }else if(p[j]>i){
                sum=0;
            }else{
                sum*=(q[j]-p[j]+1);
            }
            sum%=998244353;
        }
        sum-=pre;
        pre+=sum;
        pre%=998244353;
        if(sum<0){
            sum+=998244353;
        }
        sum%=998244353;
        ans+=i*sum;
        ans%=998244353;
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

