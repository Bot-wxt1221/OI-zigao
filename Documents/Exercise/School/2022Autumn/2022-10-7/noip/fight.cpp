#include<cstdio>

long long read();

int arr[100000+10];

long long abs(long long x){
	return x>0?x:-x;
}

/*
6
2 3 2 3 2 3
4 6 5 2

6
1 1 1 1 1 16
5 4 1 1
*/

int main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);

	register long long i,sum1=0,sum2=0,min=9223372036854775807ll,minpos;
	int n=read(),m,p1,s1,s2;
	
	for(i=1;i<=n;++i) arr[i]=read();
	
	m=read();
	p1=read();
	s1=read();
	s2=read();
	
	arr[p1]+=s1;
	
	for(i=1;i<m;++i) sum1+=arr[i]*(m-i);
	for(i=m+1;i<=n;++i) sum2+=arr[i]*(i-m);
	
	for(i=1;i<=m;++i)
		if(abs(sum1+s2*(m-i)-sum2)<min){
			minpos=i;
			min=abs(sum1+s2*(m-i)-sum2);
		}
	for(i=m+1;i<=n;++i)
		if(abs(sum2+s2*(i-m)-sum1)<min){
			minpos=i;
			min=abs(sum2+s2*(i-m)-sum1);
		}
	
	printf("%lld",minpos);

	return 0;
}

long long read(){
	register long long x=0;register char c=0,f=0;
	while('0'>c||c>'9') f=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x;
}
