#include <cstdio>
#include <algorithm>
//**************************************************************************************************
#include <cstring>
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
int arr[10];
char arr2[40];

int read();
int qpow(int base,int exponential){
    int res = 1;
    while(exponential){
        if(exponential&1)
            res=res*base;
        base=base*base;
        exponential>>=1;
    }
    return res;
}

int main(){
    int n,m,in,k,mx,now;

    register char c=getchar();
    while(c!=' '){
        ++arr[c-'0'];
        c=getchar();
    }

    k=read();

    for(register int i=0;i<k;++i){
        now=read();
        ++arr2[arr[now]];
        read();
        mx=std::max(mx,int(arr[now]));
    }

    register int t;
    register int cnt;
    int ans=1;

    q.push(0);
    q.push(1);
    q.push(0);
    if(arr2[0]) ans*=qpow(cnt,arr2[0]);



    for(register int i=1;i<=mx;++i){
        cnt=0;
        for(register int j=0;j<=i;++j){
            t=q.front();
            q.pop();
            t+=q.front();
            q.push(t);
            cnt+=t;
        }
        q.push(0);
        if(arr2[i]) ans*=qpow(cnt,arr2[i]);
    }

    printf("%d",ans);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}