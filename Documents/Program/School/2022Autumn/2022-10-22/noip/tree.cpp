#include <cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

struct U{
	int fa[500010];
	void build(int n){
		register int i;
		for(i=1;i<=n;++i) fa[i]=i;
		return;
	}
	
	int find(int x){
		return fa[x]=(x==fa[x]?x:find(fa[x]));
	}
	
	void merge(int i,int j){
		fa[find(i)]=find(j);
	}
}u;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	#endif

	int n=read();
	u.build(n);
	register int i,j;
	register long long ans=0;
	for(i=n/2;i>=1;--i)
		for(j=2;i*j<=n;++j)
			if(u.find(i)!=u.find(i*j)){
				u.merge(i,i*j);
				ans+=i;
			}

	printf("%lld %d",ans,n-1);
			

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
