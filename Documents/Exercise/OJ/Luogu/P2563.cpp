#include<cstdio>
#define maxn (200+10)
int f[maxn];
int primelist[46]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
int read(){
    int x=0,f=0;char c=getchar();
    while(c<'0'||c>'9')f|=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^'0'),c=getchar();
    return f?-x:x;
}

int main(){
    f[0]=1;
    for(register int i=0;i<46;++i)
        for(register int j=primelist[i];j<=200;++j)
            f[j]+=f[j-primelist[i]];

    int n;
    while(~scanf("%d",&n)) printf("%d\n",f[n]);
}