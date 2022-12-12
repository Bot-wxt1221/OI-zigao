#include <cstdio>
//#include <unordered_set>
#include <set>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

struct node{
	int x,y,s;
	bool operator < (const node in) const{
		if(x!=in.x) return x<in.x;
		if(y!=in.y) return y<in.y;
		return s<in.s;
	}
};

std::multiset<node> up_points,down_points;

int map[52][52];
int pre[52][52];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

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
			map[j][i]=read();
			pre[i][j]=pre[i][j-1]+map[j][i];
		}
		
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j){
			pre[i][j]+=pre[i-1][j];
		}
		
	for(i=1;i<=n;++i)//x1
		for(j=1;j<=n;++j)//y1
			for(k=i;k<=n;++k)//x2
				for(l=j;l<=n;++l){//y2             x2 y2     x1-1 y2     x2 y1-1     x1-1  y1-1
					up_points.insert((node){i,j,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]});
					down_points.insert((node){i,l,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]});
//					printf("%d %d %d %d %d\n",i,j,k,l,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]);
				}
				
	for(i=1;i<=n;++i)//x1
		for(j=1;j<=n;++j)//y1
			for(k=i;k<=n;++k)//x2
				for(l=j;l<=n;++l){//y2
					cnt+=down_points.count((node){k+1,j-1,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]});
					cnt+=up_points.count((node){k+1,l+1,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]});
//					if(up_points.count((node){k+1,j-1,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]})) printf("CNT %d %d %d %d %d\n",i,j,k,l,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]);
//					if(down_points.count((node){k+1,l+1,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]})) printf("CNT %d %d %d %d %d\n",i,j,k,l,pre[k][l]-pre[i-1][l]-pre[k][j-1]+pre[i-1][j-1]);
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
