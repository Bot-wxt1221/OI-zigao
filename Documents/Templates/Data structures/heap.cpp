/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include<cstdio>

//#define file

//**************************************************************************************************
#define HEAP_TYPE <
#define BST_DATA_TYPE int
const int HEAP_SIZE = 1000;

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
};
//**************************************************************************************************
int read();
int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif



	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
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
