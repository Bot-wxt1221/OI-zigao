#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN (1000+10)

int map[MAXN][MAXN];
char book[MAXN][MAXN];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
char abs(char x){
    return x<0?-x:x;
}

int main(){
    int n=read();
    int m=read();
    for(register int i=0,x,y;i<m;++i){
        x=read();
        y=read();
        book[x][y]=1;
    }

    map[1][1]=1;
    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=n;++j)
            if(!book[i][j]){
                map[i+1][j]=map[i][j];
                map[i][j+1]=(map[i][j+1]+map[i][j])%100003;
            }

    print(map[n][n]%100003);

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