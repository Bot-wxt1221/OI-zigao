#include<cstdio>
#define maxn (10000+10)
#define mx(a,b) ((a)>(b)?(a):(b))
int arr[maxn],f[maxn];
int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c&15),c=getchar();
    return f?-x:x;
}

int main(){
    int best=0;
    int cnt=1;
    int n=read();
    int last=-1,now;
    for(register int i=1;i<=n;++i){
        now=read();
        if(now==last+1){
            cnt++;
        }else{
            best=mx(best,cnt);
            cnt=1;
        }
        last=now;
    }

    best=mx(best,cnt);

    printf("%d",best);
}