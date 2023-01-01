#include<cstdio>
#include<cstring>
#include<deque>
#include<algorithm>
//#define file

struct node{
	long long s;
	long long w;
}arr[500000+10];

int read();
long long n,d,k1,dp[500000+10];
std::deque<node> dq;

long long count(long long g){
	memset(dp,0,sizeof(dp));
	dq.clear();
	register int i,j;
	register long long max=0;
	dq.push_front((node){0,0});
	for(i=0,j=0;i<n;++i){
		while(dq.size()&&arr[i].w-dq.front().w>d+g)
		dq.pop_front();
		while(arr[i].w-arr[j].w>=std::max(1ll,d-g)){
			while(dq.size()&&dp[j]>dq.back().s)
			dq.pop_back();
			dq.push_back((node){dp[j],arr[j].w});
			++j;
		}
		if(dq.size())
			if(arr[i].w-dq.front().w<=d+g&&arr[i].w-dq.front().w>=std::max(1ll,d-g)){
				dp[i]=dq.front().s+arr[i].s;
				max=std::max(dp[i],max);
			}
		
	}
	return max;
}

int main(){
	#ifdef file
	freopen("jump6.in", "r", stdin);
//	freopen("jump.out", "w", stdout);
	#endif
	
	register int i,mid,t=0;
	register long long l=0,r=0;
	n=read();
	d=read();
	k1=read();
	
	for(i=0;i<n;++i){
		arr[i].w=read();
		arr[i].s=read();
		r=std::max(arr[i].w,r);
	}
	
//	if(t<k){
//		puts("-1");
//		return 0;
//	}
	
	while(l<r){
		mid=(l+r)>>1;
		t=count(mid);
		if(t>=k1){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	
	printf("%lld",l);

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
