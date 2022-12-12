// #pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <cstring>
//#include <unordered_set>
//#include <set>
// #define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

int ans;

int map[52][52];
int pre[52][52];
int d[5000000];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
int getsum(int x1,int y1,int x2,int y2){
	return pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]+2500000;
}

int main(){
	#ifdef file
	freopen("horse.in", "r", stdin);
	freopen("horse.out", "w", stdout);
	#endif
	
	register int i,j,k,l;
	register long long cnt=0;
	int n=read();
	
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			map[i][j]=read();
			pre[i][j]=pre[i][j-1]+map[i][j];
		}
		
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			pre[i][j]+=pre[i-1][j];
		}
		
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
//			memset(d,0,n*(int));
			for(k=1;k<=i;++k)
				for(l=1;l<=j;++l)
					++d[getsum(k,l,i,j)];
			for(k=i+1;k<=n;++k)
				for(l=j+1;l<=n;++l)
					cnt+=d[getsum(i+1,j+1,k,l)];
			for(k=1;k<=i;++k)
				for(l=1;l<=j;++l)
					d[getsum(k,l,i,j)]=0;

			for(k=i;k<=n;++k)
				for(l=1;l<=j;++l)
					++d[getsum(i,l,k,j)];
			for(k=1;k<i;++k)
				for(l=j+1;l<=n;++l)
					cnt+=d[getsum(k,j+1,i-1,l)];
			for(k=i;k<=n;++k)
				for(l=1;l<=j;++l)
					d[getsum(i,l,k,j)]=0;
		}

				
	printf("%lld",cnt);	

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
