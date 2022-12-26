#include<cstdio>

int read();

int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);

	register char c;
	register int ans=0;
	while(~scanf("%c",&c))
		if(c!=' '&&c!='\n') ++ans;
		
	printf("%d",ans);

	return 0;
}

int read(){
	register int x=0;register char c=0,f=0;
	while('0'>c||c>'9') f=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c&15),c=getchar();
	return f?-x:x;
}
