#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int a[6];
int w[6]={1,2,3,5,10,20};
char dp[2000];

int main(){
	#ifdef file
	freopen("weight.in", "r", stdin);
	freopen("weight.out", "w", stdout);
	#endif

    register int i,j,k;
    a[0]=read();
    a[1]=read();
    a[2]=read();
    a[3]=read();
    a[4]=read();
    a[5]=read();

    int max=a[0]*w[0]+a[1]*w[1]+a[2]*w[2]+a[3]*w[3]+a[4]*w[4]+a[5]*w[5];

    dp[0]=1;
    for(i=0;i<6;++i)
        for(j=0;j<a[i];++j)
            for(k=max;k>=w[i];--k)
                dp[k]|=dp[k-w[i]];

    for(j=0,i=1;i<=max;++i)
        j+=dp[i];

    printf("Total=");
    print(j);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

