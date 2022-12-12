#include <cstdio>
#include <queue>

#define HEAP_TYPE >
#define BST_DATA_TYPE long long
const int HEAP_SIZE = 14*1000000+10;

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

	void insert(register BST_DATA_TYPE in,register int pos){
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

	void swap(register int s1,register int s2){
		BST_DATA_TYPE temp=h[s1];
		h[s1]=h[s2];
		h[s2]=temp;
	}

	void print(){
		printf("size :%d\n", size());
		printf("empty:%d\n\n", empty());
	}
}h;




int read();
void print(register long long x);

int main(){
	freopen("earthworm.in","r",stdin);
	freopen("earthworm.out","w",stdout);

	int n,m,t;
	register int j;
	register long long u,v,i,q,llt;
	n=read();
	m=read();
	q=read();
	u=read();
	v=read();
	t=read();
	
	
	
	for(i=0;i<n;++i){
		h.push(read());
	}
	
	for(i=1,j=t;i<=m;++i){
		llt=h.top()+(i-1)*q;
		h.pop();
		if(i==j){
			print(llt);
			putchar(' ');
			j+=t;
		}
		h.push(llt*u/v-q*i);
		h.push(llt-llt*u/v-q*i);
	}
	
	putchar('\n');
	
	j=t;
	i=1;
	while(!h.empty()){
		if(i==j){
			print(h.top()+(m)*q);
			putchar(' ');
			j+=t;
		}
		h.pop();
		++i;
	}
	
	putchar('\n');
	
	return 0;
}

int read(){
	register int x=0;register char c=0,f=0;
	while('0'>c||c>'9') f=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x;
}

void print(register long long x){
	register char s[20],i;
	if(!x){
		putchar(' ');
		return;
	}
	if(x<0){
		putchar('-');
		x=-x;
	}
	i=0;
	while(x){
		s[i++]=x%10;
		x/=10;
	}
	while(i--) putchar(s[i]+'0');
}
