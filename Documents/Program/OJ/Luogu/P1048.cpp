#include<cstdio>
#define max(a,b) (a)>(b)?(a):(b)
#define maxm 100+10
#define maxw 1000+10
int read(){
	int x=0;char f=1,c=getchar();
	while(c<'0'||c>'9') f=(c=='-'?-1:1),c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
	return x*f;
}
int w[maxm],v[maxm],f[maxm][maxw];
int main(){
	int W=read();
	int M=read();
	
	
	for(register int i=1;i<=M;++i) 
		w[i]=read(),v[i]=read();
	
	for(register int i=1;i<=M;++i)
		for(register int j=W;j>=0;--j)
			if(j>=w[i])
				f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
			else 
				f[i][j]=f[i-1][j];
				
	printf("%d",f[M][W]);
	
	return 0;
} 
