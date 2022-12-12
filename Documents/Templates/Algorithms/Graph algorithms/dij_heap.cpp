#include <cstdio>
#include <cstring>

//#define file
const int MAX_N=1000+10;
const int MAX_M=2000+10;
const int INF=0x3FFFFFFF;

struct node{
	int v,d;
	bool operator < (const node in) const {
        return d<=in.d;
    }
};

struct edge{
	int to,next,w;
	edge(){
		next=-1;
	}
};

#define type_heap <
#define heap_type node
const int HEAP_SIZE = MAX_N;

struct HEAP{
	heap_type h[HEAP_SIZE];
	int book[MAX_N];
	int tail;

	HEAP(){
		std::memset(book,0,sizeof(book));
		tail=1;
		return;
	}

	void push(heap_type in){
		if(book[in.v]==0){
			book[in.v]=tail;
			insert(in,tail++);
		}else{
			insert(in,book[in.v]);
		}
		return;
	}

	void pop(){
		book[h[1].v]=-1;
		insert(h[--tail],1);
	}

	void insert(heap_type in,int pos){
		h[pos]=in;
		int next;
		while((pos<<1)<tail){
			next=pos<<1;
			if((next+1<tail)&&(h[next+1] type_heap h[next])) ++next;
			if(h[next] type_heap h[pos]){
				swap(pos,next);
				pos=next;
			}else break;
		}
		while((pos>1)&&(h[pos] type_heap h[pos>>1] )){
			swap(pos,pos>>1);
			pos>>=1;
		}
	}

	heap_type top(){
		return h[1];
	}

	bool empty(){
		return tail==1;
	}

	void swap(int s1,int s2){
		heap_type temp=h[s1];
		h[s1]=h[s2];
		h[s2]=temp;
		book[h[s1].v]=s1;
		book[h[s2].v]=s2;
	}

	void clear(){
		std::memset(book,0,sizeof(book));
		tail=1;
		return;
	}
};

int head[MAX_N],cnt,n,m,s,dis[MAX_N];
edge list[MAX_M];

int read();
void readGraph();
void DijkstraHeapList();

int main(){
	#ifdef file
	freopen("dij_heap.in", "r", stdin);
	freopen("dij_heap.out", "w", stdout);
	#endif

	register int i,j,t;
	register long long sum=1;

	readGraph();

	DijkstraHeapList();
	
	for(i=2;i<=n;++i){
		t=0;
		for(j=head[i];~j;j=list[j].next)
			if(dis[list[j].to]+list[j].w==dis[i])
				++t;
		sum=sum*t%((1ll<<31)-1);
	}

	printf("%d",sum);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

HEAP h;
void DijkstraHeapList(){
	int cur,to;
	for(register int i=0;i<MAX_N;++i)dis[i]=INF;

	h.push((node){s,0});
	dis[s]=0;

	while(!h.empty()){
		cur=h.top().v;
		h.pop();
		for(register int i=head[cur];~i;i=list[i].next){
			to=list[i].to;
			if((h.book[to]!=-1)&&(dis[to]>dis[cur]+list[i].w)){
				dis[to]=dis[cur]+list[i].w;
				h.push((node){to,dis[to]});
			}
		}
	}

//	for(int i=1;i<=n;++i)
//		if(dis[i]==INF) printf("INF ");
//		else printf("%d ",dis[i]);

	return;
}

void addEdge(int u,int v,int w,int nowm){
	list[nowm].to=v;
	list[nowm].w=w;
	list[nowm].next=head[u];
	head[u]=nowm;
	return;
}

void readGraph(){
	n=read();
	m=read();
	s=1;
	int u,v,w;
	memset(head,-1,sizeof(head));
	for(register int i=1;i<=(m<<1);++i){
		u=read();
		v=read();
		w=read();
		addEdge(u,v,w,i);
		i++;
		addEdge(v,u,w,i);
	}
	return;
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
