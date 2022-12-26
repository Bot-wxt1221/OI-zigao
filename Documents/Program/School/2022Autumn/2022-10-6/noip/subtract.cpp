#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("subtract.in", "r", stdin);
	freopen("subtract.out", "w", stdout);
	#endif
	
	register int T=read(),N,K,type,i;
	register long long max,s,in;
	
	while(T--){
		N=read();
		K=read();
		type=read();
		max=0;
		s=0;
		for(i=0;i<N;++i){
			in=read();
			max=std::max(in,max);
			s+=in;
		}
		if(!type){
			if(max*K<=s) puts("YES");
			else puts("NO");
		}else{
			if(s%K==0&&(max*K<=s)) puts("YES");
			else puts("NO");
		}
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
