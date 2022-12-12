#include <cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

const int MAX_N=100000+10;
const int ST_I=MAX_N;
const int ST_J=30;

struct EDGE{
	int from,to,w,next;
	EDGE(){
		next=-1;
		return;
	}
}tree[MAX_N<<1];

int ln(int n){
	return 63-__builtin_clzll(n);
}

struct ST{
	int f[ST_I][ST_J];

	void create(int p[],int n){
		int k=ln(n);
		for(register int i=1;i<=n;++i) f[i][0]=p[i];

		for(register int j=1;j<=k;++j)
			for(register int i=1;i<=n;++i)
				f[i][j]=f[f[i][j-1]][j-1];

		return;
	}
}st;

const int UFDS_SIZE=200000+10;
struct UFDS{
	int parents[UFDS_SIZE];

	UFDS(){
		for(register int i=0;i<UFDS_SIZE;++i)
			parents[i]=i;
		return;
	}

	int find(int x){
		return x==parents[x]?x:(parents[x]=find(parents[x]));
	}

	int find_b(int x){
		while(parents[x]!=x)
			x=parents[x];
		return x;
	}

	void merge(int i,int j){
		parents[find(i)]=find(j);
		return;
	}

	void clear(){
		for(int i=1;i<UFDS_SIZE;i++)
			parents[i]=i;
		return;
	}
}U;

int head[MAX_N],depths[MAX_N],p[MAX_N],n,tot;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

void addEdge(int u,int v){
	tree[tot].to=v;
	tree[tot].from=u;
	tree[tot].next=head[u];
	head[u]=tot;
	++tot; 
	return;
}

void count(int u,int pa){
	p[u]=pa;
	depths[u]=depths[pa]+1;
	for(register int i=head[u];~i;i=tree[i].next)
		if(tree[i].to!=pa){
			count(tree[i].to,u);
		}
	return;
}

int LCA_ST(int u,int v){
	if(depths[u]<depths[v]){
		u^=v;
		v=u^v;
		u=u^v;
	}

	int k=ln(n);

	while(depths[u]>depths[v])
		u=st.f[u][ln(depths[u]-depths[v]-1)];

	if(u==v) return u;

	for(register int i=k;i>=0;--i)
		if(st.f[u][i]!=st.f[v][i]){
			u=st.f[u][i];
			v=st.f[v][i];
		}

	return st.f[u][0];
}

/*
4 100
1 2
1 3
3 4
C 1
C 2
Q 2 3
*/

int main(){
	#ifdef file
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	#endif

	 int i,u,v,R=0;
	for(i=0;i<UFDS_SIZE;++i){
		head[i]=-1;
	}
		
	register char op;
	n=read();
	int T=read();
	
	for(i=0;i<n-1;++i){
		u=read();
		v=read();
		addEdge(u,v);
		addEdge(v,u);
	}
	
	count(1,1);
	st.create(p,n);
	
	
	for(i=1;i<=T;++i){
		loop:op=getchar();
		if(op!='C'&&op!='Q') goto loop;
		if(op=='C'){
			u=read();
			U.merge(tree[u*2-1].from,tree[u*2-1].to);
		}else{
			u=read();
			v=read();
			if(U.find(u)==U.find(v)){
				R=(R+(i^(depths[u]+depths[v]-(depths[LCA_ST(u,v)]<<1))))%998244353;
//				print(depths[u]+depths[v]-(depths[LCA_ST(u,v)]<<1));
//				putchar('\n');
			}else{
				R = R ^ (i + u + v);
//				puts("-1");
			}
//			printf("%d\n",R);
		} 
	}
	
	printf("%d",R);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}


void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
        putchar('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}
