#include<cstdio>

const int maxlen=100+10;

char tab[maxlen][maxlen]={
	{0,0,0,0,0,0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};

int f[maxlen][maxlen];
int sa[maxlen],sb[maxlen];

int read(){
    int x=0;char c=getchar(),f=1;
    while(c<'0'||c>'9') f=(c=='-'?-1:1),c=getchar();
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}

int max(int a,int b){
	if(a>b) return a;
	return b;
}

int main(){
    int n=read(),m;
    char c;

    for(register int i=1;i<=n;++i){
        c=getchar();
        if(c=='A'){
            sa[i]=1;
        }else if(c=='C'){
            sa[i]=2;
        }else if(c=='G'){
            sa[i]=3;
        }else if(c=='T'){
            sa[i]=4;
        }
    }

    m=read();

    for(register int i=1;i<=m;++i){
        c=getchar();
        if(c=='A'){
            sb[i]=1;
        }else if(c=='C'){
            sb[i]=2;
        }else if(c=='G'){
            sb[i]=3;
        }else if(c=='T'){
            sb[i]=4;
        }
    }

    for(register int i=1;i<=n;++i)
        f[i][0]=f[i-1][0]+tab[sa[i]][5];
    for(register int i=1;i<=m;++i)
        f[0][i]=f[0][i-1]+tab[5][sb[i]];


    for(register int i=1;i<=n;++i)
        for(register int j=1;j<=m;++j)
            f[i][j]=max(
                f[i-1][j-1]+tab[sa[i]][sb[j]],max(
                f[i-1][j]+tab[sa[i]][5],
                f[i][j-1]+tab[5][sb[j]]));

    printf("%d",f[n][m]);

    return 0;
}
