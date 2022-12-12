#include <cstdio>
#include <deque>
#include <set>
#define file

std::deque< std::pair<int,int> > q;//p t

int read();

/*
2
1 1 0
1 2 0
*/

int main(){
	#ifdef file
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	#endif

	register int n=read(),cnt=0;
	register std::pair<int,int> p;
	register char op;
	std::deque< std::pair<int,int> >::iterator it;
	
	for(register int i=0;i<n;++i){
		op=read();
		p.first=read();
		p.second=read();
		while((!q.empty())&&(p.second-q.front().second>45)) q.pop_front();
		if(op){
			if(q.empty()) goto loop2;
			it=q.begin();
			while(it!=q.end()){
				if((*it).first>=p.first){
					q.erase(it);
					goto loop;
				}
				it++;
			}
			
		}else{
			q.push_back(p);
		}
		loop2:;
		cnt+=p.first;
		loop:;
	}
	
	printf("%d",cnt);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
