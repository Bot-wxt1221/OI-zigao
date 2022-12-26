#include<cstdio>
#include<stack>
//#define file

struct node{
	int len,height;
};

std::stack<node> s;

int read();

int main(){
	#ifdef file
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	#endif

	int n=read();
	register node t;
	register int i,t_h,cnt;
	
	for(i=0;i<n;++i){
		t.height=read();
		t.len=1;
		t_h=-1;
		while(s.size()&&s.top().height<t.height){
			t.len+=s.top().len;
			if(t_h!=s.top().height) ++cnt;
			t_h=s.top().height;
			s.pop();
		}
		s.push(t);
	}
	
	while(s.size()){
		if(t_h!=s.top().height) ++cnt;
		s.pop();
	}
	
	printf("%d",cnt);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    register int x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
