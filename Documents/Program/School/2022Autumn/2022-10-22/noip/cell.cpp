#pragma GCC optimize(3,"Ofast","inline")
#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("cell.in", "r", stdin);
	freopen("cell.out", "w", stdout);
	#endif
	
	register long long i,j,temp,ans=0;
	long long R=read();
	long long C=read();
	long long int min=read();
	long long int max=read();
	
	for(i=3;i<=R;++i){
		temp=0;
		for(j=3;j<=C;++j)
			if(((i+j-2)<<1)<=max&&((i+j-2)<<1)>=min)
				temp=(temp+(i-2)*(j-2)*(C-j+1))%1000000007;
		ans=(ans+temp*(R-i+1))%1000000007;
	}
	
	printf("%lld",ans*6%1000000007);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
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
