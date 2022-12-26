#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE  long long
#define OUTPUT_DATA_TYPE long long

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

long long q[300010];
int q_i[300010];

int main(){
	#ifdef file
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	#endif

    register int i,head,tail;
    register long long best=0,now=0;
    int n=read();
    int m=read();
    head=tail=1;
    for(i=1;i<=n;++i){
        now+=read();
        if(q_i[head]+m<i) ++head;
        while(head<=tail&&q[tail]>now) --tail;
        q_i[++tail]=i;
        q[tail]=now;
        
        best=std::max(best,now-q[head]);
        
        
    }

    printf("%lld",best);




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