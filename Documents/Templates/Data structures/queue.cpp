/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include<cstdio>

//#define file

//**************************************************************************************************
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
		tail=(tail+1)%QUEUE_SIZE;
		q[tail]=in;
		++num;
		return;
	}

	void pop(){
		head=(head+1)%QUEUE_SIZE;
		--num;
		return;
	}

	void pop_back(){
		tail=(tail-1+QUEUE_SIZE)%QUEUE_SIZE;
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
