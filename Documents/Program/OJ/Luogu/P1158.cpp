#include <cstdio>
#include <cmath>
#include <algorithm>

int read();
int left[100000],li;
int main(){
    int x1,y1,x2,y2;
    x1=read();
    y1=read();
    x2=read();
    y2=read();

    register int mx1,mx2,x,y,s1,s2;
    int n=read();

    for(register int i=0;i<n;++i){
        x=read();
        y=read();
        s1=(x-x1)*(x-x1)+(y-y1)*(y-y1);
        s2=(x-x2)*(x-x2)+(y-y2)*(y-y2);
        if(s1<=s2){
            mx1=std::max(mx1,s1);
        }else if(s1>s2){
            mx2=std::max(mx2,s2);
        }
    }

    printf("%d",mx1+mx2);

    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}