#include <cstdio>

// #define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

//************************************************************************************************
#include <cstring>
#include <complex>
#define POL_SIZE (4000000+10)

const double pi=acos(-1);
struct POL{
    int rev[POL_SIZE],len,FFTlen;
    char isFFT;
    std::complex <double> items[POL_SIZE];

    void init(){
        isFFT=1;
        initRev(initLen());

        return;
    }

    int initLen(){
        register int k=0;
        FFTlen=1;
        while((1<<k)<len) ++k,FFTlen<<=1;

        return k;
    }

    void initRev(int k){
        for(register int i=0;i<FFTlen;++i)
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));

        return;
    }

    void clear(){
        memset(this,0,sizeof(POL));
        return;
    }

    void fft(){
        for(register int i=0;i<FFTlen;++i)
            if(i<rev[i]) swap(items[i],items[rev[i]]);
        register std::complex <double>wn,w,x,y;
        for(register int h=1,j,k;h<FFTlen;h<<=1){
            wn=exp(std::complex <double>(0,1.0*isFFT*pi/h));
            for(j=0;j<FFTlen;j+=(h<<1)){
                w=1;
                for(k=j;k<j+h;k++){
                    x=items[k];
                    y=w*items[k+h];
                    items[k]=x+y;
                    items[k+h]=x-y;
                    w*=wn;
                }
            }
        }
        if(isFFT==-1){
            for(register int i=0;i<FFTlen;++i)
                items[i]/=FFTlen;
            isFFT=1;
        }else isFFT=-1;

        return;
    }
}a,b;
//************************************************************************************************

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("c:\\Users\\Administrator\\Downloads\\P1919_1.in", "r", stdin);
	freopen("c:\\Users\\Administrator\\Desktop\\OI\\Documents\\Templates\\Algorithms\\Mathematical algorithms\\out", "w", stdout);
	#endif

    int len1=read();
    int len2=read();
    int len=len1+len2+2;

    for(register int i=0;i<=len1;++i)
        a.items[i]=read();

    for(register int i=0;i<=len2;++i)
        b.items[i]=read();

    a.len=len;
    b.len=len;

    a.init();
    b.init();

    a.fft();
    b.fft();

    for(register int i=0;i<a.FFTlen;++i)
        a.items[i]*=b.items[i];

    a.fft();



    for(register int i=0;i<len1+len2+1;++i)
        {
            print((int)(a.items[i].real()+0.5));
            putchar(' ');
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
/*
数 to 多项式
n次多项式 带入 n个x求出n个值 to 点值表示法
f(x)={(x_0,f(x_0)),(x_1,f(x_1))...(x_n,f(x_n))}
g(x)={(x_0,g(x_0)),(x_1,g(x_1))...(x_n,g(x_n))}
f(x)*g(x)={(x_0,f(x_0)*g(x_0)),(x_1,f(x_1)*g(x_1))...(x_n,f(x_n)*g(x_n))}
O(n)枚举x O(n)计算 O(n)*O(n)=O(n^2)
w_0_n,w_2_n...,w_n-1_n带入--DFT
快速求 DFT?
将A(x)分成A_0(x)和A_1(x)
A(x)=A_0(x^2)+x*A_1(x^2)
x=w_k_n带入
蝴蝶变化 规模减半 O(nlogn)
点值 to 系数表示法 IFFT
DFT(A(x))作为系数 单位根导数带入B(x) 除以n 得到A(x)系数 IFFT

优化 迭代FFT
分组位置
after      before
010(2)     010(2)
011(2)     110(2)
110(2)     011(2)
O(nlogn)
*/