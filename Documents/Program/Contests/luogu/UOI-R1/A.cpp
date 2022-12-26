#include<cstdio>
// #define file
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

long long arr[1000010];

int main(){
	#ifdef file
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
    register int x,y;
    int n=read();
    int m=read();
    register int i;

    for(i=1;i<=n;++i){
        arr[i]=read();
    }

    for(i=0;i<m;++i){
        x=read();
        y=read();
        if(0<x&&x<=n) arr[x]-=y;
    }

    for(i=1;i<=n;++i){print(arr[i]);putchar(' ');}

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