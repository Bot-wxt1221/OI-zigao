#include <cstdio>
#define file
#define mx(a,b) ((a)>(b)?(a):(b))
#define mn(a,b) ((a)<(b)?(a):(b))
#define maxn (100000+10)
int arr[maxn],f1[maxn],f2[maxn];

inline int read();

int main(){
	#ifdef file
	freopen("missile.in", "r", stdin);
	freopen("missile.out", "w", stdout);
	#endif
    register int i=0;
    register int n=0;
    register int best1=0;
    register int best2=0;
    while(~scanf("%d",&arr[++i])){
        ++n;
    }

    for(register int i=1;i<=n;++i){
        for(register int j=i;j>=mn(f1[i],f2[i]);--j){
            if(arr[i]<=arr[j])
                f1[i]=mx(f1[i],f1[j]+1);
            if(arr[i]>arr[j])
                f2[i]=mx(f2[i],f2[j]+1);
        }
        best1=mx(best1,f1[i]);
        best2=mx(best2,f2[i]);
    }

    printf("%d\n%d",best1,best2);

    return 0;
}

inline int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}