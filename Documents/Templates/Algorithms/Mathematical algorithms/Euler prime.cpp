#include <cstdio>
#include <bitset>
//#define file
#define INPUT_DATA_TYPE int

//************************************************************************************************
#define MAX_NUM (100000000+10)
#define DATA_TYPE long long

std::bitset<MAX_NUM> isPrime;
DATA_TYPE prime[MAX_NUM];
void Euler(DATA_TYPE n){
    register int cnt=0;
    for(register int i=2;i<=n;++i){
        if(!isPrime[i]) prime[++cnt]=i;
        for(register int j=1;j<=cnt&&prime[j]*i<=n;++j){
            isPrime.set(prime[j]*i,1);
            if(!i%prime[j]) break;
        }
    }
}
//************************************************************************************************


INPUT_DATA_TYPE read();
void print(int x);

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    int n=read();
    Euler(n);

    int k=read();
    for(register int i=0;i<k;++i){
        printf("%d\n",prime[read()]);
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(INPUT_DATA_TYPE x){
    char s[20];
    register int i=0;
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
}