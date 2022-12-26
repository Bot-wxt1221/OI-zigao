#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
inline int abs(int a){return a<0?-a:a;}

int main(){
    register int T=read(),x1,x2,x3,y1,y2,y3;
    register char ans;
    while(T--){
        ans=0;
        x1=read();
        y1=read();
        x2=read();
        y2=read();
        x3=read();
        y3=read();
        if(y1==y2&&x2==x3) ans|=1;
        if(y1==y3&&x3==x2) ans|=1;
        if(y2==y1&&x1==x3) ans|=1;
        if(y2==y3&&x3==x1) ans|=1;
        if(y3==y1&&x1==x2) ans|=1;
        if(y3==y2&&x2==x1) ans|=1;
        
        puts(ans?"NO":"YES");
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