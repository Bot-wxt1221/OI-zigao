#include<cstdio>
#define mx(a,b) ((a)>(b)?(a):(b))
int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}
int main(){
    int n=read();
    long long int now,cnt=0,best=-2147483648;

    while(n--)now=read(),cnt=mx(cnt+now,now),best=mx(cnt,best);

    printf("%lld",best);

    return 0;
}