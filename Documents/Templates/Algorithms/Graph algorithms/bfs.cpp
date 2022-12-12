#include <cstdio>

#define file
const int MAX_N=5000+10;
const int MAX_M=MAX_N*MAX_N;
const char INF=127;

#define queue_type int
const int QUEUE_SIZE = MAX_N;
struct QUEUE{
	queue_type q[MAX_N];
	int head,tail,num;

	QUEUE(){
		head=0;
		tail=0;
		num=0;
		return;
	}

	void push(queue_type in){
		if(num < QUEUE_SIZE){
			q[tail] = in;
			++tail;
			tail%=QUEUE_SIZE;
			++num;
		}
		return;
	}

	void pop(){
		if(num>0){
			++head;
			--num;
			head%=QUEUE_SIZE;
		}
		return;
	}

	queue_type front(){
		return q[head];
	}

	bool empty(){
		if(head==tail){
			return true;
		}else{
			return false;
		}
	}
};

int s,n,m;
char matrix[MAX_N][MAX_N];

void init();
int read();
void readGraph();
void breadthFirstSearchMatrix();

int main(){
	#ifdef file
	freopen("bfs.in", "r", stdin);
	freopen("bfs.out", "w", stdout);
	#endif

	init();
	readGraph();

	breadthFirstSearchMatrix();

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void breadthFirstSearchMatrix(){
	QUEUE que;
	int book[MAX_N]={0},cur=s;

	que.push(cur);
	book[cur]=1;

	while(!que.empty()){
		cur=que.front();
		for(register int i=1;i<=n;++i){
			if(matrix[cur][i]!=INF&&!book[i]){
				que.push(i);
				book[i]=1;
			}
		}
		printf("%d ",cur);
		que.pop();
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
