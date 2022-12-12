/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
//#define file
int read();

#define stack_type int
const int STACK_SIZE = 500000+10;
// const int STACK_SIZE = 50;
struct stack{
	stack_type _null,s[STACK_SIZE];
	int top;

	stack(){
		top=1;
		return;
	}

	void push(stack_type in){
		s[top] = in;
		++top;
		return;
	}

	void pop(){
		--top;
		return;
	}

	void pop(int in){
		top-=in;
		return;
	}

	stack_type top(){
		return s[top-1];
	}

	void clear(){
		top=1;
	}

	bool empty(){
		if(top==1){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return top;
	}

	stack_type read(int in){
		return s[in];
	}
};

bool cmp(int a, int b){
    return a>b;
}

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

	stack s;
	int n=read();
	register int e;
	register unsigned long long cnt=0;
	int add;

	for(register int i=0;i<n;++i){
		e=-read();
	// for(register int i=0;i<500000;++i){
	// 	e=10;
        //count
        if(!s.empty()){
			add=std::lower_bound(s.s+1,s.s+s.top,e)-s.s;
			cnt+=s.top-add+1;
			if(add<=1) --cnt;
			if(add==0) --cnt;
			add=std::upper_bound(s.s+1,s.s+s.top,e)-s.s;
			s.top=add;
        }
		s.push(e);
	}

	printf("%lld",cnt);

	#ifdef file5
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