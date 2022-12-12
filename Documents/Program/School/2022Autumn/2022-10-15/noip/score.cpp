#include <cstdio>
#define file

int read();

int main(){
	#ifdef file
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	#endif
	
	register int a=read();
	register int b=read();
	register int c=read();
	
	printf("%d",a/5+b/10*3+c/2);

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
