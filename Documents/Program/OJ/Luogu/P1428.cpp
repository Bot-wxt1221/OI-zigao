#include <cstdio>

int read();
int arr[100];

int main(){
    int n=read();
    register int cnt;
    for(register int i=0; i<n; ++i){
        arr[i]=read();
        cnt=0;
        for(register int j=0; j<i; ++j)
            if(arr[j]<arr[i])
                ++cnt;
        printf("%d ", cnt);
    }



    return 0;
}

int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}