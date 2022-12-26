#include<cstdio>
#include<algorithm>
// #define file

//************************************************************************************************
#include<cstring>
#define AC_TYPE char
#define QUEUE_HEAP int
const int MAX_N=160;
const int AC_DATA_SIZE=26;
const int AC_TREE_SIZE=MAX_N*70;
const int QUEUE_SIZE=2*AC_TREE_SIZE;

struct QUEUE{
	QUEUE_HEAP q[QUEUE_SIZE];
	int head,tail,num;

	QUEUE(){
		head=0;
		tail=-1;
		num=0;
		return;
	}

	void push(QUEUE_HEAP in){
		tail=(tail+1)%QUEUE_SIZE;
		q[tail]=in;
		++num;
		return;
	}

	void push_front(QUEUE_HEAP in){
		head=(head-1)%QUEUE_SIZE;
		q[head]=in;
		++num;
		return;
	}

	void pop(){
		head=(head+1)%QUEUE_SIZE;
		--num;
		return;
	}

	void pop_back(){
		tail=(tail-1)%QUEUE_SIZE;
		--num;
		return;
	}


	QUEUE_HEAP front(){
		return q[head];
	}

	QUEUE_HEAP back(){
		return q[tail];
	}

	void clear(){
		head=0;
		tail=0;
		num=0;
		return;
	}

	bool empty(){
		if(num==0)
			return true;
		else
			return false;
	}

	int size(){
		return num;
	}

	QUEUE_HEAP read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}
}q;

// #include<queue>
// std::queue <int>q;

struct AC{
    int tree[AC_TREE_SIZE][AC_DATA_SIZE],fail[AC_TREE_SIZE],book[AC_TREE_SIZE],val[AC_TREE_SIZE],cnt[MAX_N],nown,cntn;

    AC(){
        memset(this,0,sizeof(AC));
        return;
    }

    void insert(char *s,int len){
        int pos=0;
        for(register int i=0;i<len;++i)
            pos=tree[pos][s[i]]?tree[pos][s[i]]:(tree[pos][s[i]]=++nown);
        book[pos]=++cntn;
        return;
    }

    void build(){
        register int u;
        memset(fail,0,sizeof(fail));

        for(register int i=0;i<AC_DATA_SIZE;++i)
            if(tree[0][i]) q.push(tree[0][i]);

        while(q.size()){
            int u=q.front();
            q.pop();
            for(register int i=0;i<AC_DATA_SIZE;++i)
                if(tree[u][i]){
                    fail[tree[u][i]]=tree[fail[u]][i];
                    q.push(tree[u][i]);
                }else
                    tree[u][i]=tree[fail[u]][i];
        }

        return;
    }

    int find(char *s,int len){
        register int u=0,res=0;
        for(register int i=0;i<len;++i){
            u=tree[u][s[i]];
            for(register int j=u;j&&~book[j];j=fail[j])
                ++val[j];
        }

        for(register int i=0;i<=nown;++i)
            if(book[i]) res=std::max(res,val[i]),cnt[book[i]]=val[i];
        return res;
    }

    void clear(){
        memset(this,0,sizeof(AC));
        return;
    }
}ac;
//************************************************************************************************

int read();

int main(){
	#ifdef file
	freopen("c:\\Users\\Administrator\\Desktop\\OI\\Documents\\Program\\Luogu\\P3808_2.in", "r", stdin);
	// freopen("name.out", "w", stdout);
	#endif

    while(true){
        int n=read();
        if(!n) break;
        ac.clear();
        register int cplen,len,x;
        char s[MAX_N][80],s2[1000010];

        for(register int i=1;i<=n;++i){
            scanf("%s",s[i]);
            cplen=len=strlen(s[i]);
            for(len-=1;~len;--len) s[i][len]-='a';
            s[i][79]=cplen;
            ac.insert(s[i],cplen);
        }

        ac.build();

        scanf("%s",s2);
        cplen=len=strlen(s2);
        for(len-=1;~len;--len) s2[len]-='a';
        x=ac.find(s2,cplen);
        printf("%d\n",x);
        for(register int i=1;i<=n;++i)
            if(ac.cnt[i]==x){
                for(register int j=0;j<s[i][79];++j)
                    if(s[i][j]+'a'==0) break;
                    else printf("%c",s[i][j]+'a');
                putchar('\n');
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