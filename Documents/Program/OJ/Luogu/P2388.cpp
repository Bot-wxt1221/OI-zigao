#include<cstdio>
#define INPUT_DATA_TYPE unsigned long long
#define OUTPUT_DATA_TYPE unsigned long long

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    unsigned long long n=read();
    register unsigned long long ans=0,temp=0;;
    register unsigned long long x;

    for(register unsigned long long i=1;i<=n;++i){
        x=i;
        while(!(x%5)){
            ++temp;
            x/=5;
        }
        ans+=temp;
    }

    print(ans);

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