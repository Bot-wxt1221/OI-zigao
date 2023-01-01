#include<cstdio>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int e[30][30];
int pr[30][30];

int stack[30];

void printp(int i,int j){
    if(i==j) return;
    if(!pr[i][j]){
        print(j);
        putchar(' ');
        return;
    }
    printp(i,pr[i][j]);
    printp(pr[i][j],j);
    return;
}

int main(){
	#ifdef file
	freopen("short.in", "r", stdin);
	freopen("short.out", "w", stdout);
	#endif

    register int i,j,k;
    int n=read();
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j){
            e[i][j]=read();
            if(i!=j&&!e[i][j]) e[i][j]=0x3f3f3f3f;
        }

    for(k=1;k<=n;++k)
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                if(e[i][j]>e[i][k]+e[k][j])
                    pr[i][j]=k,e[i][j]=e[i][k]+e[k][j];

    printf("minlong=");
    print(e[1][n]);
    putchar('\n');
    i=n;
    j=0;
    printf("1 ");
    printp(1,n);


	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
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