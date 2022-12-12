#include <cstdio>
// #define file

//************************************************************************************************
#include <cstring>
#define TRIE_TYPE char
const int TRIE_DATA_SIZE=65;
const int TRIE_TREE_SIZE=3000015;
// const int TRIE_TREE_SIZE=100;

struct TRIE{
    int next[TRIE_TREE_SIZE][TRIE_DATA_SIZE],nown;
    int cnt[TRIE_TREE_SIZE];

    TRIE(){
        memset(this,0,sizeof(TRIE));
        return;
    }

    void insert(char *s,int len){
        int pos=0;
        for(register int i=0;i<len;++i){
            pos=next[pos][s[i]]?next[pos][s[i]]:(next[pos][s[i]]=++nown);
            ++cnt[pos];
        }
        return;
    }

    int find(char *s,int len){
        int pos=0;
        for(register int i=0;i<len;++i){
            if(!next[pos][s[i]]) return 0;
            pos=next[pos][s[i]];
        }
        return cnt[pos];
    }

    void clear(){
        for(register int i=0;i<=nown;++i)
            for(register int j=0;j<TRIE_DATA_SIZE;++j)
                next[i][j]=0;
        for(register int i=0;i<=nown;++i)
            cnt[i]=0;
        nown=0;
        return;
    }
}t;
//************************************************************************************************

int getnum(char x){
    if(x>='A'&&x<='Z')
        return x-'A';
    else if(x>='a'&&x<='z')
        return x-'a'+26;
    else
        return x-'0'+52;
}

int read();

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

    register int T=read();
    int n,q;
    register int i,len,cplen;
    register char c;
    char s[TRIE_TREE_SIZE];
    while(T--){
        t.clear();
        n=read();
        q=read();
        for(i=0;i<n;++i){
            scanf("%s",s);
            cplen=len=strlen(s);
            for(len-=1;~len;--len) s[len]=getnum(s[len]);
            t.insert(s,cplen);
        }
        for(i=0;i<q;++i){
            scanf("%s",s);
            cplen=len=strlen(s);
            for(len-=1;~len;--len) s[len]=getnum(s[len]);
            printf("%d\n",t.find(s,cplen));
        }
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