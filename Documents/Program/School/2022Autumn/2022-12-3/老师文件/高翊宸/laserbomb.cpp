#include <cstdio>
#include <algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

int map[6000][6000];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int count(int x1,int y1,int x2,int y2){
    return map[x2][y2]-map[x1-1][y2]-map[x2][y1-1]+map[x1-1][y1-1];
}

int main(){
	#ifdef file
	freopen("laserbomb.in", "r", stdin);
	freopen("laserbomb.out", "w", stdout);
	#endif

    register int i,j,x,y,t;
    int n=read();
    int r=read();
    int maxx=-1,maxy=-1;

    for(i=0;i<n;++i){
        x=read()+1;
        y=read()+1;
        t=read();
        maxx=std::max(maxx,x);
        maxy=std::max(maxy,y);
        map[x][y]+=t;
    }

    for(i=1;i<=std::max(maxx,r+1);++i)
        for(j=1;j<=std::max(maxy,r+1);++j)
            map[i][j]+=map[i][j-1];

    for(i=1;i<=std::max(maxx,r+1);++i)
        for(j=1;j<=std::max(maxy,r+1);++j)
            map[i][j]+=map[i-1][j];

    t=0;

    for(i=1;i<=std::max(maxx-r+1,1);++i)
        for(j=1;j<=std::max(maxy-r+1,1);++j)
            t=std::max(t,count(i,j,i+r-1,j+r-1));

    printf("%d",t);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
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