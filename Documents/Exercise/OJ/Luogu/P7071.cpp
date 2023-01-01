#include<cstdio>
#include<cstdlib>
#include<algorithm>

int read();

int main(){
    register int n=read();
    register int arri=0;
    if(n&1) printf("-1");
    else{
        while(n){
            printf("%d ",1<<((int)std::__lg(n)));
            n-=(1<<(int)std::__lg(n));
        }
    }

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}