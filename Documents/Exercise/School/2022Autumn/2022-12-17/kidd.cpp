#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int arr[110],dp1[110],dp2[110];

int main(){
	#ifdef file
	freopen("kidd.in", "r", stdin);
	freopen("kidd.out", "w", stdout);
	#endif

    int T=read(),n;
    register int i,j,best;
    while(T--){
    best=1;
    n=read();
    for(i=0;i<n;++i) arr[i]=read(),dp1[i]=dp2[i]=0;
    dp1[0]=dp2[0]=1;
    for(i=1;i<n;++i){
        dp1[i]=dp2[i]=1;
        for(j=0;j<i;++j){
            if(arr[i]<arr[j])
                dp1[i]=std::max(dp1[i],dp1[j]+1);
            if(arr[i]>arr[j])
                dp2[i]=std::max(dp2[i],dp2[j]+1);
        }
        best=std::max(dp1[i],best);
        best=std::max(dp2[i],best);
    }

    print(best);
    putchar('\n');
    }


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