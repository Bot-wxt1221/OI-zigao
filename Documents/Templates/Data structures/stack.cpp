/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include<cstdio>

//#define file

//**************************************************************************************************
#define STACK_DATA_TYPE int
const int STACK_SIZE = 10000;
struct stack{
	STACK_DATA_TYPE _null,s[STACK_SIZE];
	int s_top;

	stack(){
		s_top=0;
		return;
	}

	void push(STACK_DATA_TYPE in){
		s[s_top] = in;
		++s_top;
		return;
	}

	void pop(){
		--s_top;
		return;
	}

	void pop(int in){
		s_top-=in;
		return;
	}

	STACK_DATA_TYPE top(){
		return s[s_top-1];
	}

	void clear(){
		s_top=0;
	}

	bool empty(){
		if(s_top==0){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return s_top;
	}

	STACK_DATA_TYPE read(int in){
		return s[in];
	}
}S;
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
