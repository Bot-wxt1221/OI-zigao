#include <cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE long long
#define MAXN (20+10)

long long map[MAXN][MAXN];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
char abs(char x){
    return x<0?-x:x;
}

int main(){
    char Bx=read()+1;
    char By=read()+1;
    char Hx=read()+1;
    char Hy=read()+1;

    map[1][1]=1;

    for(register char i=1;i<=Bx;++i)
        for(register char j=1;j<=By;++j)
            if(!((abs(i-Hx)==2&&abs(j-Hy)==1)||(abs(i-Hx)==1&&abs(j-Hy)==2)||(i==j&&i==1)||(i==Hx&&j==Hy)))
                map[i][j]=map[i-1][j]+map[i][j-1];

    print(map[Bx][By]);

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