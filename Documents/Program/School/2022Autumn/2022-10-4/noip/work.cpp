#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define file

#define QUEUE_DATA_TYPE int
const int QUEUE_SIZE = 1000;
struct QUEUE{
	QUEUE_DATA_TYPE q[QUEUE_SIZE];
	int head,tail,num;

	QUEUE(){
		head=0;
		tail=-1;
		num=0;
		return;
	}

	void push(QUEUE_DATA_TYPE in){
		tail=tail+1;
		if(QUEUE_SIZE==tail) tail=QUEUE_SIZE;
		q[tail]=in;
		++num;
		return;
	}

	void push_front(QUEUE_DATA_TYPE in){
		head=(head-1)%QUEUE_SIZE;
		q[head]=in;
		++num;
		return;
	}

	void pop(){
		head=head+1;
		if(QUEUE_SIZE==head) head=QUEUE_SIZE;
		--num;
		return;
	}

	void pop_back(){
		tail=(tail-1)%QUEUE_SIZE;
		--num;
		return;
	}


	QUEUE_DATA_TYPE front(){
		return q[head];
	}

	QUEUE_DATA_TYPE back(){
		return q[tail];
	}

	void clear(){
		head=0;
		tail=-1;
		num=0;
		return;
	}

	bool empty(){
		if(num==0)
			return true;
		else
			return false;
	}

	int size(){
		return num;
	}

	QUEUE_DATA_TYPE read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}
}Q;

struct edge{
	int to;
	int next;
	edge(){
		next=-1;
		return;
	}
}e[(100000+10)<<2];

long long dis0[100000+10],dis1[100000+10],head[100000+10],tot;
char book[100000+10];

long long read();
void addEdge(int u,int v){
	e[tot].next=head[u];
	head[u]=tot;
	e[tot].to=v;
	++tot;
	
	e[tot].next=head[v];
	head[v]=tot;
	e[tot].to=u;
	++tot;
	
	return;
}

/*
5 5 5
1 2
2 3
3 4
4 5
1 5
1 1
1 2
1 3
1 4
1 5
*/

int main(){
	#ifdef file
	freopen("work.in", "r", stdin);
	freopen("work.out", "w", stdout);
	#endif
	
	register int i,u,v;
	
	int n=read();
	int m=read();
	int q=read();

	memset(dis0,0x3f,sizeof(dis0));
	memset(dis1,0x3f,sizeof(dis0));
	for(i=1;i<=m;++i) head[i]=-1;

	for(i=0;i<m;++i){
		u=read();
		v=read();
		addEdge(u,v);
//		if(u==1) dis1[v]=1;
//		if(v==1) dis1[u]=1;
	}
	
//	dis1[1]=1;
	dis0[1]=0;
	book[1]=1;
	Q.push(1);
	
	while(!Q.empty()){
		u=Q.front();
		Q.pop();
		book[u]=0;
		for(i=head[u];~i;i=e[i].next){
			if(dis1[e[i].to]>dis0[u]+1){
				dis1[e[i].to]=dis0[u]+1;
				if(!book[u]) Q.push(e[i].to);
			}
			if(dis0[e[i].to]>(dis1[u]+1)){
				dis0[e[i].to]=dis1[u]+1;
				if(!book[u]) Q.push(e[i].to);
			}
			
		}
	}
	
	for(i=0;i<q;++i){
		u=read();
		v=read();
		if( ( (v&1) && (dis1[u]<=v) ) || ( (!(v&1)) && (dis0[u]<=v) ) ) puts("Yes");
		else puts("No");
	}

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

long long read(){
    long long x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
