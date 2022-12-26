#include<cstdio>
//**************************************************************************************************
#include<cstring>
#define mod 10007
#define queue_type int
const int QUEUE_SIZE = 10000+10;
struct QUEUE{
	queue_type _null,q[QUEUE_SIZE];
	int head,tail,num;

	QUEUE(){
		head=0;
		tail=0;
		num=0;
		memset(&_null,0,sizeof(_null));
		return;
	}

	void push(queue_type in){
		q[tail] = in;
		++tail;
		tail%=QUEUE_SIZE;
		++num;
		return;
	}

	void pop(){
		q[head]=_null;
		++head;
		--num;
		head%=QUEUE_SIZE;
		return;
	}

	queue_type front(){
		return q[head];
	}

	queue_type back(){
		return q[tail-1];
	}

	void clear(){
		head=0;
		tail=0;
		return;
	}

	bool empty(){
		if(head==tail){
			return true;
		}else{
			return false;
		}
	}

	int size(){
		return num;
	}

	queue_type read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}
}q;
//**************************************************************************************************

int read();
int qpow_mod(int base,int exponential){
    int res = 1;
    base%=mod;
    while(exponential){
        if(exponential&1)
            res=(res*base)%mod;
        base=(base*base)%mod;
        exponential>>=1;
    }
    return res;
}

int main(){
    int a,b,k,n,m;
    a=read();
    b=read();
    k=read();
    n=read();
    m=read();

    q.push(0);
    q.push(1);
    q.push(0);

    register int t;

    for(register int i=0;i<k;++i){
        for(register int j=0;j<=i+1;++j){
            t=q.front()%mod;
            q.pop();
            t+=q.front();
            q.push(t%mod);
            // printf("%d ",t);
        }
        q.push(0);
        // putchar('\n');
    }

    printf("%d",((((qpow_mod(a,n)*qpow_mod(b,m))%mod)*q.read(n+1))%mod));

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}