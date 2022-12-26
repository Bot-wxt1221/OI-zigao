#include<cstdio>
#include<algorithm>
#include<cstring>
#define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

char s1[1010],s2[1010];

int f[1010][1010];

int main(){
	#ifdef file
	freopen("lcs.in", "r", stdin);
	freopen("lcs.out", "w", stdout);
	#endif

    register int i,j;
    scanf("%s%s",&s1[1],&s2[1]);

    int len1=strlen(&s1[1]);
    int len2=strlen(&s2[1]);

    for(i=1;i<=len1;++i)
        for(j=1;j<=len2;++j)
            f[i][j]=std::max((f[i-1][j-1]+(s1[i]==s2[j])),std::max(f[i-1][j],f[i][j-1]));


    print(f[len1][len2]);

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