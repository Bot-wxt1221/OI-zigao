#include <cstdio>
#include <algorithm>
// #define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int arr[2010],dp[2010];

int main(){
	#ifdef file
	freopen("lic.in", "r", stdin);
	freopen("lic.out", "w", stdout);
	#endif

    register int i,j,best=-1;
    int n=0;
    while(~scanf("%d",&arr[n++]));
    dp[0]=1;
    for(i=1;i<n;++i){
        dp[i]=1;
        for(j=i-1;~j;--j)
            if(arr[i]>arr[j])
                dp[i]=std::max(dp[i],dp[j]+1);
        best=std::max(dp[i],best);
    }

    printf("max=");
    print(best);


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