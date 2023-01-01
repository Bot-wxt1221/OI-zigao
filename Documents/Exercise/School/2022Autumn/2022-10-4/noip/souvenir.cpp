#include<cstdio>
#include<cstring>
#include<algorithm>
#define file

int read();
int P[1000+1][1000+1];
int dp[10000+1];

/*
6 1 100
50
20
25
20
25
50
*/

int main(){
	#ifdef file
	freopen("souvenir.in", "r", stdin);
	freopen("souvenir.out", "w", stdout);
	#endif
	
	register int i,j,k,t;
	
	register int T=read();
	register int N=read();
	register int M=read();
	
	for(i=1;i<=T;++i)
		for(j=1;j<=N;++j)
			P[i][j]=read();
	for(i=1;i<T;++i){
		for(j=1;j<=N;++j)
			for(k=P[i][j];k<=M;++k)
				dp[k]=std::max(dp[k-P[i][j]]+P[i+1][j]-P[i][j],dp[k]);
				
		M+=dp[M];
		memset(dp,0,sizeof(dp));
	}

				
	printf("%d",M);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    register int x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
