#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

long long sum[100010];

int main(){
	#ifdef file
	freopen("subsequence.in", "r", stdin);
	freopen("subsequence.out", "w", stdout);
	#endif

     int i,pos,ans;
    int n;
    long long s;

    while(~scanf("%d%lld",&n,&s)){
        ans=0x3f3f3f3f;
        for(i=1;i<=n;++i) sum[i]=read()+sum[i-1];
        for(i=1;i<=n;++i){
            pos=std::upper_bound(sum,sum+i,sum[i]-s)-sum-1;
            if(i>=0&&sum[i]-sum[pos]>=s) ans=std::min(ans,i-pos);
        }
        printf("%d\n",ans==0x3f3f3f3f?0:ans);
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