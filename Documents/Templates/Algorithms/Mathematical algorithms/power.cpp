/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
//#define file


int read();

//************************************************************************************************
#define QPOW_DATA_TYPE int
QPOW_DATA_TYPE qpow(QPOW_DATA_TYPE base,QPOW_DATA_TYPE exponential){
    QPOW_DATA_TYPE res = 1;
    while(exponential){
        if(exponential&1)
            res=res*base;
        base=base*base;
        exponential>>=1;
    }
    return res;
}

QPOW_DATA_TYPE qpow_mod(QPOW_DATA_TYPE base,QPOW_DATA_TYPE exponential,const QPOW_DATA_TYPE mod){
    QPOW_DATA_TYPE res=1;
    base%=mod;
    while(exponential){
        if(exponential&1)
            res=(res*base)%mod;
        base=(base*base)%mod;
        exponential>>=1;
    }
    return res%mod;
}

QPOW_DATA_TYPE qpow_dg_mod(const QPOW_DATA_TYPE &a,QPOW_DATA_TYPE n,const QPOW_DATA_TYPE &mod){
    if(n==0)
        return 1;
    if(n%2==1){
        return qpow_dg_mod(a,n-1,mod)*a%mod;
    }
    int temp=qpow_dg_mod(a,n/2,mod)%mod;
    return temp*temp%mod;
}

int qpow_dg_mod(const QPOW_DATA_TYPE &a,QPOW_DATA_TYPE n){
    if(n==0)
        return 1;
    if(n%2==1){
        return qpow_dg_mod(a,n-1)*a;
    }
    int temp=qpow_dg_mod(a,n/2);
    return temp*temp;
}
//************************************************************************************************

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
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
