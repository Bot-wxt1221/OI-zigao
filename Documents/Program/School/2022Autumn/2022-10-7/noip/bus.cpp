#include<cstdio>

int read();
int t[4000105],cnt[4000105],sum[4000105],f[4000105];

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);

	int n=read();
	int m=read();
	register int i,ti,t,j;
	
	for(i=0;i<n;++i){
		ti=read();
		++cnt[ti];
		sum[ti]+=ti;
		t=t>ti?t:ti;
	}
	
	for(i=1;i<t+m;++i) cnt[i]+=cnt[i-1],sum[i]+=sum[i-1];
	
	for(i=1;i<t+m;++i){
		if(i>=m&&cnt[i-m]==cnt[i]){
			f[i]=f[i-m];
			continue;
		}
		f[i]=cnt[i]*i-sum[i];
		for(j=(i-(m<<1)+1>0?i-(m<<1)+1:0);j<=i-m;++j) f[i]=f[i]<f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j])?f[i]:f[j]+(cnt[i]-cnt[j])*i-(sum[i]-sum[j]);
	}
	
	j=0x7fffffff;
	for(i=t;i<t+m;++i) j=j<f[i]?j:f[i];
	
	printf("%d",j);

	return 0;
}

int read(){
	register int x=0;register char c=0,f=0;
	while('0'>c||c>'9') f=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x;
}
