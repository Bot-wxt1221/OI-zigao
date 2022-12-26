#include<cstdio>
#include<algorithm>

struct node{
	int l,r,w;
}tree[1000000+10];

int read();
char flag;
int cnt;
bool issame(int u,int v){
	if(u==-1&&v==-1) return true;
	if(tree[u].w!=tree[v].w||(u==-1||v==-1)){
		flag=true;
		return false;
	}
	cnt+=2;
	if(flag) return false;
	return issame(tree[u].l,tree[v].r)&&issame(tree[u].r,tree[v].l);
}
/*
10
2 2 5 5 5 5 4 4 2 3
9 10
-1 -1
-1 -1
-1 -1
-1 -1
-1 2
3 4]
5 6
-1 -1
7 8
*/
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);

	int n=read();
	register int i,max=0;
	for(i=1;i<=n;++i) tree[i].w=read();
	for(i=1;i<=n;++i){
		tree[i].l=read();
		tree[i].r=read();
	}
	
	for(i=1;i<=n;++i){
		flag=false;
		cnt=1;
		if(issame(tree[i].l,tree[i].r)){
			max=std::max(cnt,max);
		}
	}
	
	printf("%d",max);

	return 0;
}

int read(){
	register int x=0;register char c=0,f=0;
	while('0'>c||c>'9') f=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x;
}
