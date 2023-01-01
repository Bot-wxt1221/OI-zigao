#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ull unsigned long long
using namespace std;
const int N=6;
ull P;
struct matrix{
	ull a[N][N];
	void init()
	{
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				a[i][j]=((i==j)?1:0);
	}
};
ull mt(ull a,ull b)
{
	if (a==0ull) return 0ull;
	if (a>b) swap(a,b); 
	ull x=mt(a/10,b);
	x*=10LL;x%=P;
	x=(x+b*(a%10))%P;
	return x;
}
matrix mult(matrix a,matrix b)
{
	matrix ans;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			ans.a[i][j]=0ull;
			for (int k=0;k<N;k++)
				ans.a[i][j]=(ans.a[i][j]+mt(a.a[i][k],b.a[k][j]))%P;
		}
	}
	return ans;
}
matrix qpow(matrix a,long long n)
{
	matrix ans;ans.init();
	while(n>0)
	{
		if (n&1) ans=mult(ans,a);
		a=mult(a,a);
		n>>=1;
	}
	return ans;
}
ull Qpow(ull x,long long t)
{
	if (t==0ll) return 1ull;
	ull g=Qpow(x,t/2LL);
	g=mt(g,g)%P;
	if(t&1) g=mt(g,x)%P;
	return g;
}
int main() 
{
//	freopen("matrixx10.in","r",stdin);
//	freopen("matrixx10.out","w",stdout);
	matrix A;
	ull a,b,f0,f1,n;
	cin>>a>>b>>f0>>f1>>n>>P;
	a%=P;b%=P;
	A.a[0][0]=1ull;A.a[0][1]=1ull;A.a[0][2]=1ull;A.a[0][3]=1ull;A.a[0][4]=1ull;A.a[0][5]=b; 
	A.a[1][0]=1ull;A.a[1][1]=0ull;A.a[1][2]=0ull;A.a[1][3]=0ull;A.a[1][4]=0ull;A.a[1][5]=0ull; 
	A.a[2][0]=0ull;A.a[2][1]=0ull;A.a[2][2]=1ull;A.a[2][3]=2ull;A.a[2][4]=0ull;A.a[2][5]=1ull; 
	A.a[3][0]=0ull;A.a[3][1]=0ull;A.a[3][2]=0ull;A.a[3][3]=1ull;A.a[3][4]=0ull;A.a[3][5]=1ull; 
	A.a[4][0]=0ull;A.a[4][1]=0ull;A.a[4][2]=0ull;A.a[4][3]=0ull;A.a[4][4]=a;A.a[4][5]=0ull; 
	A.a[5][0]=0ull;A.a[5][1]=0ull;A.a[5][2]=0ull;A.a[5][3]=0ull;A.a[5][4]=0ull;A.a[5][5]=1ull; 
	A=qpow(A,n-1LL);
	ull sum=0ull;
	sum=(sum+mt(A.a[0][0],f1))%P;
	sum=(sum+mt(A.a[0][1],f0))%P;
	sum=(sum+mt(A.a[0][2],4ull))%P;
	sum=(sum+mt(A.a[0][3],2ull))%P;
	sum=(sum+mt(A.a[0][4],a*a%P))%P;
	sum=(sum+mt(A.a[0][5],1ull))%P;
	printf("%llu\n",sum);
	return 0;
}