#include <cstdio>
#include <algorithm>
#define _max(a,b) ((a)>(b)?(a):(b))
#define _min(a,b) ((a)<(b)?(a):(b))

struct rmq{
	int f_max[100010][20],f_min[100010][20];
	void build(int n,int *arr){
		register int i,j;
		int k=std::__lg(n);
		for(i=1;i<=n;++i) f_max[i][0]=f_min[i][0]=arr[i];

		for(j=1;j<=k;++j)
			for(i=1;i<=(n-(1<<j)+1);++i)
				f_max[i][j]=_max(f_max[i][j-1],f_max[i+((1<<(j-1)))][j-1]),
				f_min[i][j]=_min(f_min[i][j-1],f_min[i+((1<<(j-1)))][j-1]);
		return;
	}

	int q_max(int l,int r){
		int k=std::__lg(r-l+1);
		return _max(f_max[l][k],f_max[r-(1<<k)+1][k]);
	}

	int q_min(int l,int r){
		int k=std::__lg(r-l+1);
		return _min(f_min[l][k],f_min[r-(1<<k)+1][k]);
	}
}L_st,Q_st;

int L_arr[100010],Q_arr[100010];

int read(){
	register int x=0;register char f=0,c=getchar();
	while(c<'0'||'9'<c) f|=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x; 
}

int main(){
	register int i,l_1,r_1,l_2,r_2;
	register long long L,Q;
	int n=read();
	int m=read();
	int q=read();

	for(i=1;i<=n;++i) L_arr[i]=read();
	for(i=1;i<=m;++i) Q_arr[i]=read();

	L_st.build(n,L_arr);
	Q_st.build(m,Q_arr);

	for(i=0;i<q;++i){
		l_1=read();
		r_1=read();
		l_2=read();
		r_2=read();
		L=L_st.q_max(l_1,r_1);
		Q=Q_st.q_min(l_2,r_2);

		printf("%lld\n",L*Q);
	}

	return 0;
}