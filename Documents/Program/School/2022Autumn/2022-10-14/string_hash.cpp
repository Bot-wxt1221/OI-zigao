#include <cstdio>
#include <cstring>
//#define file

unsigned long long hash1[1000010],hash2[1000010],base1[1000010],base2[1000010];
char s1[1000010],s2[1000010];
int read();
void countHash(int n,register unsigned long long mod,register unsigned long long mul_base,char *s,unsigned long long *hash,unsigned long long *base){
	register int i;
	base[0]=1;
	hash[0]=s[0];
	if(mod) mul_base%=mod;
	for(i=1;i<n;++i){
		if(mod)
			base[i]=base[i-1]*mul_base%mod;
		else
			base[i]=base[i-1]*mul_base;
		hash[i]=hash[i-1]*mul_base+s[i];
		if(mod) hash[i]%=mod;
	}
	return;
}

int getHash(int l,int r,register unsigned long long mod,unsigned long long *hash,unsigned long long *base){
	if(mod) return ((hash[r]-(!l?0:hash[l-1])*(base[r-l+1])%mod)%mod+mod)%mod;
	return (hash[r]-(!l?0:hash[l-1])*(base[r-l+1]);
}

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif
	
	scanf("%s %s",s1,s2);
	register int i;
	int s1len=strlen(s1),s2len=strlen(s2);
	countHash(s1len,0,256,s1,hash1,base1);
	countHash(s2len,0,256,s2,hash2,base2);
	
	for(i=0;i<s1len-s2len;++i){
		if(getHash(i,))
	}
	

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
