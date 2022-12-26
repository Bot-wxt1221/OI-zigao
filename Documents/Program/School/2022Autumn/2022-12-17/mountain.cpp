#include<cstdio>
#include<algorithm>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int f1[1010],f2[1010],arr[1010];

int main(){
	#ifdef file
	freopen("mountain.in", "r", stdin);
	freopen("mountain.out", "w", stdout);
	#endif

    register int i,j,best=-1;
    int n=read();
    for(i=0;i<n;++i) arr[i]=read();

    f1[0]=1;

    for(i=1;i<n;++i){
        f1[i]=1;
        for(j=0;j<i;++j)
            if(arr[j]<arr[i])
                f1[i]=std::max(f1[i],f1[j]+1);
    }

    f2[n-1]=1;

    for(i=n-2;i>=0;--i){
        f2[i]=1;
        for(j=n-1;j>i;--j)
            if(arr[j]<arr[i])
            f2[i]=std::max(f2[i],f2[j]+1);
    }

    for(i=0;i<n;++i){
        best=std::max(best,f1[i]+f2[i]-1);
    }

    print(best);

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