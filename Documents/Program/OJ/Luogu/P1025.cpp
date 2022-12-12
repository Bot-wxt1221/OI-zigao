#include <cstdio>

int cnt;

int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')f=(c=='-'?-1:f),c=getchar();
    while(c<='9'&&c>='0'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}

void dfs(int n,int k,int s){
    if(k==1){
        ++cnt;
        return;
    }
    for(register int i=s;i<=n/k;++i){
        dfs(n-i,k-1,i);
    }
    return;
}

int main(){
    int n=read();
    int k=read();
    dfs(n,k,1);

    printf("%d",cnt);
}