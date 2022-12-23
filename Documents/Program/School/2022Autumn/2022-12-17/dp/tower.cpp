#include <cstdio>
#include <algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN (1000+10)

int tree[MAXN][MAXN];

inline INPUT_DATA_TYPE read();
inline void print(OUTPUT_DATA_TYPE x);
/*
5
13
11 8 
12 7 26 
6 14 15 8 
12 7 13 24 11
*/
int main(){
	#ifdef file
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	#endif
    int n=read();
    int best=0;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=i;++j){
            tree[i][j]=read()+std::max(tree[i-1][j],tree[i-1][j-1]);
            best=std::max(best,tree[i][j]);
        }

    print(best);

    return 0;
}

inline INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

inline void print(OUTPUT_DATA_TYPE x){
    char s[20];
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