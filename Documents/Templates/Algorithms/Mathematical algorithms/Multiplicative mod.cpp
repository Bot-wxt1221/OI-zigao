#include<cstdio>
//#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

//************************************************************************************************
#include<algorithm>
#define MUL_TYPE unsigned long long
MUL_TYPE mul1(MUL_TYPE x,MUL_TYPE y,MUL_TYPE p){//qiuckly x<=y<=1e18
	MUL_TYPE z=(long double)x/p*y;
	MUL_TYPE res=(unsigned long long)x*y-(unsigned long long)z*p;
	return (res+p)%p;
}

MUL_TYPE mul2(MUL_TYPE x,MUL_TYPE y,MUL_TYPE p){//mild need __int128 x<=y<=1e18
	return ((__int128)x*y)%p;
}

MUL_TYPE mul3(MUL_TYPE a,MUL_TYPE b,MUL_TYPE MOD){//计算x乘y的积 x<=y<=1e18
	if (a==0ull) return 0ull;
	if (a>b) std::swap(a,b);
	unsigned long long x=mul3(a/10,b,MOD);
	x*=10ull;x%=MOD;
	x=(x+b*(a%10))%MOD;
	return x;
}

MUL_TYPE mul4(MUL_TYPE x,MUL_TYPE y,MUL_TYPE p){//very slow x<=y<=1e18
	MUL_TYPE res=0;//加法初始化
	while(y){
		if(y&1)res=(res+x)%p;//模仿二进制
		x=(x<<1)%p; y>>=1;//将x不断乘2达到二进制
	}return res;
}


//************************************************************************************************

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

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
    char s[20];
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