#include <cstdio>
// #define file

//************************************************************************************************
#include <cstring>
#define TRIE_TYPE char
const int TRIE_DATA_SIZE=128;
const int TRIE_TREE_SIZE=100;

struct TRIE{
    int next[TRIE_TREE_SIZE][TRIE_DATA_SIZE],nown;
    bool book[TRIE_TREE_SIZE];

    void insert(char *s,int len){
        int pos=0;
        for(register int i=0;i<len;++i)
            pos=next[pos][s[i]]?next[pos][s[i]]:(next[pos][s[i]]=++nown);
        book[pos]=1;
        return;
    }

    bool find(char *s,int len){
        int pos=0;
        for(register int i=0;i<len;++i){
            if(!next[pos][s[i]]) return 0;
            pos=next[pos][s[i]];
        }
        return book[pos];
    }

    void del(char *s){
        int pos=0;
        int len=strlen(s);
        for(register int i=0;i<len;++i){
            if(!next[pos][s[i]]) return;
            pos=next[pos][s[i]];
        }
        book[pos]=0;
        return;
    }

    void clear(){
        memset(this,0,sizeof(TRIE));;
        return;
    }
}t;
//************************************************************************************************

int read();

int main(){
	#ifdef file
	freopen("name.in", "r", stdin);
	freopen("name.out", "w", stdout);
	#endif

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