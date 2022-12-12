#include <cstdio>
#include <algorithm>
#define _max(a,b) ((a)>(b)?(a):(b))
#define _min(a,b) ((a)<(b)?(a):(b))

struct rmq{
	int f_max[100010][20],f_min[100010][20],up0[100010][20],down0[100010][20];
	char have_0[100010][20];
	void build(int n,int *arr){
		register int i,j;
		int k=std::__lg(n);
		for(i=1;i<=n;++i) f_max[i][0]=f_min[i][0]=arr[i],have_0[i][0]=(arr[i]==0),up0[i][0]=(arr[i]>0?arr[i]:0x7FFFFFFF),down0[i][0]=(arr[i]<0?arr[i]:0x80000000);
		
		for(j=1;j<=k;++j)
			for(i=1;i<=(n-(1<<j)+1);++i)
				f_max[i][j]=_max(f_max[i][j-1],f_max[i+((1<<(j-1)))][j-1]),
				f_min[i][j]=_min(f_min[i][j-1],f_min[i+((1<<(j-1)))][j-1]),
				down0[i][j]=_max(down0[i][j-1],down0[i+((1<<(j-1)))][j-1]),
				up0[i][j]=_min(up0[i][j-1],up0[i+((1<<(j-1)))][j-1]),
				have_0[i][j]=_max(have_0[i][j-1],have_0[i+((1<<(j-1)))][j-1]);
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
	
	int q_down0(int l,int r){
		int k=std::__lg(r-l+1);
		return _max(down0[l][k],down0[r-(1<<k)+1][k]);
	}
	
	int q_up0(int l,int r){
		int k=std::__lg(r-l+1);
		return _min(up0[l][k],up0[r-(1<<k)+1][k]);
	}
	
	int q_have_0(int l,int r){
		int k=std::__lg(r-l+1);
		return _max(have_0[l][k],have_0[r-(1<<k)+1][k]);
	}
}L_st,Q_st;

int L_arr[100010],Q_arr[100010];

int read(){
	register int x=0;register char f=0,c=getchar();
	while(c<'0'||'9'<c) f|=(c=='-'),c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x; 
}
/*
3 2 2
0 1 -2
-3 4
1 3 1 2
2 3 2 2
*/
int main(){

	register int i,l_1,r_1,l_2,r_2;
	register long long L_max,L_min,Q_max,Q_min,L_up0,L_down0,Q_up0,Q_down0,ans,temp;
	register char L_have_0,Q_have_0;
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
		L_max=L_st.q_max(l_1,r_1);
		L_min=L_st.q_min(l_1,r_1);
		L_have_0=L_st.q_have_0(l_1,r_1);
		L_up0=L_st.q_up0(l_1,r_1);
		L_down0=L_st.q_down0(l_1,r_1);
		
		Q_max=Q_st.q_max(l_2,r_2);
		Q_min=Q_st.q_min(l_2,r_2);
		Q_have_0=Q_st.q_have_0(l_2,r_2);
		Q_up0=Q_st.q_up0(l_2,r_2);
		Q_down0=Q_st.q_down0(l_2,r_2);

		ans=0x8000000000000000ll;
		temp=0x7FFFFFFFFFFFFFFFll;
		temp=_min(temp,L_max*Q_max);
		temp=_min(temp,L_max*Q_min);
		if(Q_up0!=0x7FFFFFFFll) temp=_min(temp,L_max*Q_up0);
		if(Q_down0!=(int)(int)0x80000000ll)temp=_min(temp,L_max*Q_down0);
		ans=_max(ans,temp);
		
		temp=0x7FFFFFFFFFFFFFFFll;
		temp=_min(temp,L_min*Q_max);
		temp=_min(temp,L_min*Q_min);
		if(Q_up0!=0x7FFFFFFFll) temp=_min(temp,L_min*Q_up0);
		if(Q_down0!=0x80000000)temp=_min(temp,L_min*Q_down0);
		ans=_max(ans,temp);
		
		if(L_up0!=0x7FFFFFFFll){
			temp=0x7FFFFFFFFFFFFFFFll;
			temp=_min(temp,L_up0*Q_max);
			temp=_min(temp,L_up0*Q_min);
			if(Q_up0!=0x7FFFFFFFll) temp=_min(temp,L_up0*Q_up0);
			if(Q_down0!=(int)0x80000000ll)temp=_min(temp,L_up0*Q_down0);
			ans=_max(ans,temp);
		}
		
		if(L_down0!=(int)0x80000000ll){
			temp=0x7FFFFFFFFFFFFFFFll;
			temp=_min(temp,L_down0*Q_max);
			temp=_min(temp,L_down0*Q_min);
			if(Q_up0!=0x7FFFFFFFll) temp=_min(temp,L_down0*Q_up0);
			if(Q_down0!=(int)0x80000000ll)temp=_min(temp,L_down0*Q_down0);
			ans=_max(ans,temp);
		}
		
		if(L_have_0) ans=_max(ans,0);
		if(Q_have_0) ans=_min(ans,0);
		printf("%lld\n",ans);
	}

	return 0;
}