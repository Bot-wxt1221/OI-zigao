#include<cstdio>
#include<deque>

std::deque<char> q;

int read();

int main(){
	char c=getchar();
	register int cnt=0;
	while(c!='\n'){
		q.push_back(c);
		c=getchar();
	}

	int k=read();

	register std::deque<char>::iterator it=q.begin();
	register char flag;

	while(true){
		flag=1;
		for(it=q.begin();it!=q.end()&&(it+1)!=q.end();){
			if(k==cnt) goto loop;
			if(*it>*(it+1)){
				flag=0;
				it=q.erase(it);
				++cnt;
			}
			else ++it;
		}
		if(k==cnt) goto loop;
		if(flag){
			q.pop_back();
			++cnt;
		}
	}

	loop:;
	flag=1;
	while(!q.empty()){
		if(flag&&q.front()=='0'){}
		else{
			// printf("%c",q.front());
			putchar(q.front());
			flag=1;
		}
		q.pop_front();
	}

	if(!flag) printf("0");

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}