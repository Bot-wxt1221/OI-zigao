#include<cstdio>
#include<algorithm>
//#define file
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
/*
3
12 2 1
2 3
14 2 2
4 5
16 2 2
5 7
*/
int main(){
	#ifdef file
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);
	#endif
	
	register int T=read(),K,P,i,t,sp;
	register long long N,min;
	while(T--){
		N=read();
		K=read();
		P=read();
		min=9223372036854775807LL;
		for(i=1;i<=K;++i){
			t=read();
			if(min>t) min=t;
			if(i==P) sp=t;
		}
		if(sp==min) print(N/sp);
		else print(std::min(((N%min)/(sp-min)),N/min));
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
