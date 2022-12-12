#include <cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(int x);

int main(){
    register int k=read();
    register int sum = 0;
    register int i=1;
    while(k>=0){
        sum+=i*i;
        k-=i;
        ++i;
    }

    printf("%d",sum+k*(i-1));

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
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
}