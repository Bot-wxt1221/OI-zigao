#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
#define file

struct node{
	int s;
	int w;
}arr[500000+10];

int read();
int n,d,k,dp[500000+10];
std::deque<node> dq;

int count(int g){
	memset(dp,0,sizeof(dp));
	dq.clear();
	register int i,j;
	dq.push_front((node){0,0});
	for(i=0,j=0;i<n;++i){
		while(dq.size()&&arr[i].w-dq.front().w>d+g) dq.pop_front();
		while(arr[i].w-arr[j].w>=std::max(1,d-g)){
			while(dq.size()&&dp[j]>dq.back().s) dq.pop_back();
			dq.push_back((node){dp[j],arr[j].w});
			++j;
		}
		if(dq.size()) dp[i]=dq.front().w;
	}
	return dp[n-1];
}

int main(){
	#ifdef file
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	#endif
	
	register int i,l,r,mid,t;
//	n=read();
//	d=read();
//	k=read();
//	
//	for(i=0;i<n;++i){
//		arr[i].w=read();
//		arr[i].s=read();
//	}
//	
//	l=0;
//	r=n+1;
//	
//	while(l<r){
//		mid=(l+r)>>1;
//		t=count(mid);
//		if(t>=k){
//			r=mid;
//		}else{
//			l=mid+1;
//		}
//	}
	
	printf("%d",-1);

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
