#include <cstdio>
#include <algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

struct node{
    int u,v;
    bool operator < (const node another) const{
        if(u!=another.u) return u<another.u;
        return v<another.v;
    }
}arr[5010];

int d[5010];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("ship.in", "r", stdin);
	freopen("ship.out", "w", stdout);
	#endif

    register int i,pos,len=0;
    int n=read();
    for(i=0;i<n;++i){
        arr[i].u=read();
        arr[i].v=read();
    }

    std::sort(arr,arr+n);
    d[len++]=arr[0].v;
    for(i=1;i<n;++i){
        pos=std::upper_bound(d,d+len,arr[i].v)-d;
        d[pos]=arr[i].v;
        if(pos>=len) ++len;
    }

    print(len);


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