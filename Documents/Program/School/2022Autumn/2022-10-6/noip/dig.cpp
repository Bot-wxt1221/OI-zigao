#include <cstdio>
#include <iostream>
#include <algorithm>
#define file
#define INPUT_DATA_TYPE  long long
#define OUTPUT_DATA_TYPE  long long

#define QUEUE_DATA_TYPE long long
const int QUEUE_SIZE = 200000+10;
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

	void push_front(QUEUE_DATA_TYPE in){
		head=(head-1)%QUEUE_SIZE;
		q[head]=in;
		++num;
		return;
	}

	void pop(){
		head=(head+1)%QUEUE_SIZE;
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
}dists,times;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("dig.in", "r", stdin);
	freopen("dig.out", "w", stdout);
	#endif
	
	register int v=1;
	register double dis=0,time=0;
	register char op;
	int n=read();
	int m=read();
	
	for(register int i=0,in;i<n;++i){
		loop:op=getchar();
		if(op!='D'&&op!='T') goto loop;
		in=read();
		if(op=='D'){
			dists.push(in);
		}else{
			times.push(in);
		}
	}
	
	std::sort(times.q,times.q+times.num);
	std::sort(dists.q,dists.q+dists.num);
	
	for(;dis<=m;){//         /(1/v)  *v
	
		if(dists.empty()&&times.empty()) break;
		if((!times.empty())&&((dists.empty())||((dists.front()-dis)*v>(times.front()-time)))){
			if(dis+(times.front()-time)/(v*1.0)>m)break;
			dis+=(times.front()-time)/(v*1.0);
//			std::cout<<times.top()<<'\n';
			time=(times.front()*1.0);
//			std::cout<<times.top()<<time<<'\n';
			++v;
			times.pop();
		}else{
			if(dists.front()>m) break;
			time+=(dists.front()-dis)*v;
			dis=dists.front();
			++v;
			dists.pop();
		}
		
	}
	
	if(dis<m){
		time+=(m-dis)*v;
	}
	
	std::cout<<(long long)(time);

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
