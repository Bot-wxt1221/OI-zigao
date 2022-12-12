#include <cstdio>
#include <algorithm>
//#define file

//************************************************************************************************
#include <cstring>
#define MATRIX_MOD %MOD
#define MATRIX_DATA_TYPE unsigned long long
#define MUL_TYPE unsigned long long
const int MATRIX_MAX_N=8;
const int MATRIX_MAX_M=8;
unsigned long long MOD;


MUL_TYPE mul(MUL_TYPE x,MUL_TYPE y,MUL_TYPE p){//qiuckly x<=y<=1e18
	MUL_TYPE z=(long double)x/p*y;
	MUL_TYPE res=(unsigned long long)x*y-(unsigned long long)z*p;
	return (res+p)%p;
}

struct MATRIX{
    int n,m;
    MATRIX_DATA_TYPE matrix[MATRIX_MAX_N][MATRIX_MAX_M];

    MATRIX operator + (const MATRIX &a) const {
        MATRIX ans;
        ans.n=n;
        ans.m=m;
        for(register int i=0;i<n;++i)
            for(register int j=0;j<m;++j)
                ans.matrix[i][j]=(matrix[i][j]+a.matrix[i][j])MATRIX_MOD;

        return ans;
    }

    MATRIX operator * (const MATRIX &a) const {
        MATRIX ans;
        ans.n=n;
        ans.m=a.m;
        memset(ans.matrix,0,sizeof(ans.matrix));
        for(register int i=0;i<n;++i)
            for(register int k=0;k<m;++k)
                for(register int j=0;j<a.m;++j)
                    ans.matrix[i][j]=(ans.matrix[i][j]+mul(matrix[i][k],a.matrix[k][j],MOD))MATRIX_MOD;

        return ans;
    }

    friend MATRIX operator ^ (MATRIX base,MATRIX_DATA_TYPE exponential){
        MATRIX ans;
        ans.n=base.n;
        ans.m=base.n;
        memset(ans.matrix,0,sizeof(ans.matrix));

        for(register int i=0;i<base.n;++i)
            ans.matrix[i][i]=1;

        while(exponential){
            if(exponential&1) ans=ans*base;
            base=base*base;
            exponential>>=1;
        }

        return ans;
    }

    void print(){
        for(register int i=0;i<n;++i){
            for(register int j=0;j<m;++j)
                printf("%d ",matrix[i][j]MATRIX_MOD);
            putchar('\n');
        }

        return;
    }
}a,b;
//************************************************************************************************
unsigned long long f1,f0,A,B,N;

unsigned long long read();

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    A=read();
    B=read();
    f0=read();
    f1=read();
    unsigned long long N=read();
    MOD=read();

    a.matrix[0][0]=f1;
    a.matrix[0][1]=f0;
    a.matrix[0][2]=2;
    a.matrix[0][3]=4;
    a.matrix[0][4]=1;
    a.matrix[0][5]=mul(A,A,MOD);
    a.matrix[0][6]=B;

    b.matrix[0][0]=1;
    b.matrix[1][0]=1;
    b.matrix[2][0]=1;
    b.matrix[3][0]=1;
    b.matrix[5][0]=1;
    b.matrix[6][0]=1;
    b.matrix[0][1]=1;
    b.matrix[2][2]=1;
    b.matrix[4][2]=1;
    b.matrix[2][3]=2;
    b.matrix[3][3]=1;
    b.matrix[4][3]=1;
    b.matrix[4][4]=1;
    b.matrix[5][5]=A;
    b.matrix[6][6]=1;

    a.n=1;a.m=7;
    b.n=b.m=7;

    // a.print();
    // putchar('\n');
    // b.print();

    if(N==1){
        printf("%lld",f1%MOD);
        return 0;
    }else if(N==0){
        printf("%lld",f0%MOD);
        return 0;
    }

    b=b^(N-2);
    a=a*b;

    // printf("%d\n%d %d %d %d %d %d %d\n%d",F(N),
    // a.matrix[0][0],a.matrix[0][1],a.matrix[0][2],a.matrix[0][3],a.matrix[0][4],a.matrix[0][5],a.matrix[0][6],
    // a.matrix[0][0]+a.matrix[0][1]+a.matrix[0][2]+a.matrix[0][3]+a.matrix[0][5]+a.matrix[0][6]);

    printf("%lld",(((((a.matrix[0][0]+a.matrix[0][1])%MOD+a.matrix[0][2])%MOD+a.matrix[0][3])%MOD+a.matrix[0][5])%MOD+a.matrix[0][6])%MOD);


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

unsigned long long read(){
    unsigned long long x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}