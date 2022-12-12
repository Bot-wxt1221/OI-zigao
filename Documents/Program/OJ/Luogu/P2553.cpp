#include <cstdio>

// #define file
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

//************************************************************************************************
#include <cstring>
#include <complex>
//************************************************************************************************

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

char in[100000];
long long a[100000],b[100000],ans[100000];

int main(){
	#ifdef file
	freopen("c:\\Users\\Administrator\\Downloads\\P1919_1.in", "r", stdin);
	freopen("c:\\Users\\Administrator\\Desktop\\OI\\Documents\\Templates\\Algorithms\\Mathematical algorithms\\out", "w", stdout);
	#endif

    register int i,temp1,temp2;
    char c,flag=0;
    int len,lena,lenb;

    while(gets(in)){
        i=len=lena=lenb=flag=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        len=strlen(in);
        while(i<len){
            if(in[i]=='*'){
                flag=1;
            }else if(in[i]>='0'&&in[i]<='9'){
                temp1=temp2=0;
                while(in[i]>='0'&&in[i]<='9')temp1=(temp1<<3)+(temp1<<1)+(in[i]&15),++i;
                if(in[i+1]=='^'){
                    c=in[i];
                    i+=2;
                    while(in[i]>='0'&&in[i]<='9')temp2=(temp2<<3)+(temp2<<1)+(in[i]&15),++i;
                }
                if(flag){
                    a[temp2]+=temp1;
                    lena=std::max(lena,temp2);
                }else{
                    b[temp2]+=temp1;
                    lena=std::max(lena,temp2);
                }
            }
            ++i;
        }

        len=lena+lenb+2;

        for(i=0;i<=len;++i)
            for(register int j=0;j<len;++j)
                ans[i+j]+=a[i]*b[j];


        for(i=len,flag=0;~i;--i)
            if(ans[i]){
                if(flag) putchar('+');
                else flag=1;
                print(ans[i]);
                if(i){
                    putchar(c);
                    putchar('^');
                    print(i);
                }
            }

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