#include<cstdio>
#include<cstring>
//#define file

const int STRING_LENGTH=1000010;
// const int STRING_LENGTH=10;

int read();
void kmp(char txt[],char pat[]);

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    char txt[STRING_LENGTH],pat[STRING_LENGTH];
    scanf("%s%s",txt,pat);
    kmp(txt,pat);

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

void kmp(char txt[],char pat[]){
    int kmp[STRING_LENGTH],txtlen=strlen(txt),patlen=strlen(pat);
    memset(kmp,0,sizeof(kmp));
    //init pat
    register int j=0;
    for(register int i=1;i<patlen;++i){
        while(j&&pat[i]!=pat[j]) j=kmp[j];
        kmp[i+1]=pat[i]==pat[j]?++j:0;
    }
    //search
    j=0;
    for(register int i=0;i<txtlen;++i){
        while(j&&txt[i]!=pat[j])j=kmp[j];
        j+=txt[i]==pat[j]?1:0;
        if(j==patlen) printf("%d\n",i-j+2);
    }

    for(register int i=1;i<=patlen;++i) printf("%d ",kmp[i]);

    return;
}

int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}