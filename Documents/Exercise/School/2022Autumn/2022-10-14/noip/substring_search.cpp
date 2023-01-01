#include<cstdio>
#include<cstring>
#define file

char txt[1000010],pat[1000010];
int next[1000010];

int main(){
	#ifdef file
	freopen("substring_search.in", "r", stdin);
	freopen("substring_search.out", "w", stdout);
	#endif
	
	scanf("%s %s",txt,pat);
	int txtlen=strlen(txt),patlen=strlen(pat);
	
	register int i,j,cnt=0;
	
	for(i=1,j=0;i<patlen;++i){
		while(j&&pat[i]!=pat[j]) j=next[j];
		next[i+1]=pat[i]==pat[j]?++j:0;
	}
	
	for(i=0,j=0;i<txtlen;++i){
		while(j&&txt[i]!=pat[j]) j=next[j];
		j+=txt[i]==pat[j]?1:0;
		if(j==patlen) ++cnt;
	}
	
	printf("%d",cnt);
	

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    int x=0;char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
