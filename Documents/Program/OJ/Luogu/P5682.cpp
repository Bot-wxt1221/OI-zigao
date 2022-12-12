#include <cstdio>
#include <algorithm>

int read();
bool cmp(int a, int b){
    return a>b;
}

int main(){
    int n=read();
    register int a1=0,a2=0,a3=0,now;

    for(register int i=0;i<n;++i){
        now=read();
        if(now>a3){
            if(now>a2){
                if(now>a1){
                    a3=a2;
                    a2=a1;
                    a1=now;
                }else if(now!=a1){
                    a3=a2;
                    a2=now;
                }
            }else if(now!=a1&&now!=a2){
                a3=now;
            }
        }
    }

    printf("%d",(!a1+!a2+!a3==2)?(-1):(a1%a2>a3?a1%a2:a3));

    return 0;
}

int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}