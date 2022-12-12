#include <cstdio>
#include <cstring>
// #define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

char s1[1000],s2[1000];

int main(){
	#ifdef file
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

    register int i,first,i_s1,i_s2,len_s1,len_s2;
    register int T=read();
    while(T--){
        scanf("%s%s",s1,s2);
        len_s1=strlen(s1);
        len_s2=strlen(s2);
        for(first=0;first<len_s1;++first){
            i_s2=0;
            for(i_s1=0;i_s1<len_s1&&i_s2<len_s2;++i_s1){
                if(s2[i_s2]==s1[(i_s1+first)%len_s1]) ++i_s2;
            }
            if(i_s2==len_s2){
                puts("Y");
                goto loop;
            }
        }
        puts("N");
        loop:;
    }

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