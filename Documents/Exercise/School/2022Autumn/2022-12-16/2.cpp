#include<cstdio>
#include<cstring>
#include<algorithm>
//#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int v[2001],w[2001],dp[20001];

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    memset(dp,0x3f,sizeof(dp));
    register int i,j,V=0;
    int n=read();
    int W=read();
    for(i=0;i<n;++i) w[i]=read(),v[i]=read(),V+=v[i];
    dp[0]=0;
    for(i=0;i<n;++i)
        for(j=V;j>=v[i];--j)
            dp[j]=std::min(dp[j-v[i]]+w[i],dp[j]);

    for(j=V;j>=v[i];--j)
        if(dp[j]<=W){
            printf("%d",j);
            break;
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