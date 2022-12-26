#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    register int m=read();
    register int s=read();
    register int s1=0;
    register int s2=0;
    register int t=read();

    for(register int i=1;i<=t;++i){
        if(m>=10){
            s2+=60;
            m-=10;
        }else{
            m+=4;
        }

        s1+=17;

        if(s2>s1){
            s1=s2;
        }
        if(s1>s){
            puts("Yes");
            print(i);
            return 0;
        }
    }

    puts("No");
    print(s1);

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