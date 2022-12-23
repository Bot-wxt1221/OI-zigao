#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

long long a[200010];

int main(){
    register int T=read(),i,n;
    while(T--){
        n=read();
        for(i=0;i<n;++i)
            a[i]=read();
        std::sort(a+1,a+n);
        for(i=1;i<n;++i)
            if(a[i]>a[0]){
                a[0]=(a[0]+a[i]+1)>>1;
            }
        print(a[0]);
        putchar('\n');
    }

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
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