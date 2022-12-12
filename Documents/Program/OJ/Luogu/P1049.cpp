#include <cstdio>
#define max(a,b) (a)>(b)?(a):(b)
#define maxn 30+10
#define maxv 20000+10
int w[maxn],f[maxv];

int read(){
	int x=0;char f=1,c=getchar();
	while(c<'0'||c>'9') f=(c=='-'?-1:1),c=getchar();
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c&15);
		c=getchar();
	}
	return x*f;
}

int main(){
	int V=read();
	int N=read();
	
	for(register int i=1;i<=N;++i)
		w[i]=read();
		
	for(register int i=1;i<=N;++i)
		for(register int j=V;j>=w[i];--j)
			f[j]=max(f[j-w[i]]+w[i],f[j]);
				
	printf("%d",V-f[V]);			
	 
	return 0;
}
