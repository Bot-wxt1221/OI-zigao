#include <cstdio>
#include <cstring>

#define file
const int MAX_N=5000+10;
const int MAX_M=MAX_N*MAX_N;
const char INF=127;
int cnt,s,n,m;
char matrix[MAX_N][MAX_N];
char book[MAX_N];

void init();
int read();
void readGraph();
void depthFirstSearchMatrix(int cur);

int main(){
	#ifdef file
	freopen("dfs.in", "r", stdin);
	freopen("dfs.out", "w", stdout);
	#endif

	init();
	readGraph();

	book[s] = 1;
	depthFirstSearchMatrix(s);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void depthFirstSearchMatrix(int cur){
	printf("%d ",cur);
	++cnt;
	if(cnt==n) return;
	for(register int i=1;i<=n;++i)
		if(matrix[cur][i]<INF&&book[i]==0){
			book[i]=1;
			depthFirstSearchMatrix(i);
		}

	return;
}

void addEdge(int u,int v,int w){
	matrix[u][v]=w;
	return;
}

void readGraph(){
	n=read();
	m=read();
	s=read();
	int u,v,w;
	for(register int i=1;i<=m;++i){
		u=read();
		v=read();
		addEdge(u,v,1);
	}
	return;
}

void init(){
	for(register int i=0;i<MAX_N;++i){
		for(register int j=0;j<MAX_N;++j){
			if(i==j) matrix[i][j]=0;
			else matrix[i][j]=INF;
		}
	}
}

int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
