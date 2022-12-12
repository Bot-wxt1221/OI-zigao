#include <cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

#define HEAP_TYPE <
#define BST_DATA_TYPE int
const int HEAP_SIZE = 1000+10;

struct HEAP{
	BST_DATA_TYPE _null,h[HEAP_SIZE];
	int tail;

	HEAP(){
		tail=1;
		return;
	}

	void push(BST_DATA_TYPE in){
		insert(in,tail++);
	}

	void pop(){
		insert(h[--tail],1);
	}

	void insert(BST_DATA_TYPE in,int pos){
		h[pos]=in;
		register int next;
		while((pos<<1)<tail){
			next=pos<<1;
			if((next+1<tail)&&(h[next+1] HEAP_TYPE h[next])) ++next;
			if(h[next] HEAP_TYPE h[pos]){
				swap(pos,next);
				pos=next;
			}else break;
		}
		while((pos>>1)&&(h[pos] HEAP_TYPE h[pos>>1] )){
			swap(pos,pos>>1);
			pos>>=1;
		}
	}

	BST_DATA_TYPE top(){
		return h[1];
	}

	void clear(){
		tail=1;
	}

	bool empty(){
		if(tail==1){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return tail-1;
	}

	BST_DATA_TYPE read(int in){
		return h[in];
	}

	void swap(int s1,int s2){
		BST_DATA_TYPE temp=h[s1];
		h[s1]=h[s2];
		h[s2]=temp;
	}

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n\n", empty());
	}
}H;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

struct node{
	int next,to;
	node(){
		next=-1;
		return;
	}
}e[1000+10];

int head[1000+10],tot,d[1000+10];

void addEdge(int u,int v){
	e[tot].next=head[u];
	head[u]=tot;
	e[tot].to=v;
	++tot;
}

int main(){
	#ifdef file
	freopen("correct.in", "r", stdin);
	freopen("correct.out", "w", stdout);
	#endif
	
	register int i,u,v;
	int n=read();
	int m=read();
	
	for(i=0;i<=n;++i) head[i]=-1;
	
	for(i=0;i<m;++i){
		u=read();
		v=read();
		addEdge(u,v);
		++d[v];
	}
	
	for(i=1;i<=n;++i)
		if(d[i]==0) H.push(i);
		
	
	while(!H.empty()){
		u=H.top();
		H.pop();
		d[u]=-1;
		print(u);
		putchar(' ');
		for(v=head[u];~v;v=e[v].next){
			--d[e[v].to];
			if(!d[e[v].to]) H.push(e[v].to);
		}
	}

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
