#include<cstdio>
#include<algorithm>
#define file

//************************************************************************************************
#include<cstring>
#define AC_TYPE char
#define QUEUE_HEAP int
const int MAX_N=200000+10;
const int AC_DATA_SIZE=26;
const int AC_TREE_SIZE=200000+10;
const int QUEUE_SIZE=AC_TREE_SIZE;

struct EDGE{
    int next,to;
    EDGE(){
        next=-1;
        return;
    }
};

struct FAIL_TREE{
    int head[MAX_N],nowm;
    EDGE tree[MAX_N];

    FAIL_TREE(){
        memset(head,-1,sizeof(head));
        nowm=0;
        return;
    }

    void addEdge(int u,int v){
        tree[nowm].next=head[u];
        head[u]=nowm;
        tree[nowm].to=v;
        ++nowm;
        return;
    }
};

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

struct AC{
    int tree[AC_TREE_SIZE][AC_DATA_SIZE],fail[AC_TREE_SIZE],val[AC_TREE_SIZE],cnt[MAX_N],book[MAX_N],nown,cntn;
    FAIL_TREE t;

    AC(){
        memset(tree,0,sizeof(tree));
        memset(fail,0,sizeof(fail));
        memset(val,0,sizeof(val));
        memset(cnt,0,sizeof(cnt));
        memset(book,0,sizeof(book));
        nown=0;
        cntn=0;
        return;
    }

    void insert(char *s,int len){
        int pos=0;
        for(register int i=0;i<len;++i)
            pos=tree[pos][s[i]]?tree[pos][s[i]]:(tree[pos][s[i]]=++nown);
        book[++cntn]=pos;
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
            ++val[u];
        }

        for(register int i=1;i<=nown;++i)
            t.addEdge(fail[i],i);

        dfs(0);

        for(register int i=1;i<=cntn;++i)
            cnt[i]=val[book[i]];

        return res;
    }

    void dfs(int u){
        for(register int i=t.head[u];~i;i=t.tree[i].next){
            dfs(t.tree[i].to);
            val[u]+=val[t.tree[i].to];
        }
        return;
    }

    void clear(){
        memset(this,0,sizeof(AC));
        return;
    }
}ac;
//************************************************************************************************

int read();

char s[AC_TREE_SIZE+10],s2[2000000];

int main(){
	#ifdef file
	// freopen("c:\\Users\\Administrator\\Desktop\\OI\\Documents\\Program\\Luogu\\P5357_15.in", "r", stdin);
	// // freopen("name.out", "w", stdout);
	#endif

    int n=read();
    register int cplen,len,x;

    for(register int i=1;i<=n;++i){
        scanf("%s",s);
        cplen=len=strlen(s);
        for(len-=1;~len;--len) s[len]-='a';
        ac.insert(s,cplen);
    }

    ac.build();

    scanf("%s",s2);
    cplen=len=strlen(s2);
    for(len-=1;~len;--len) s2[len]-='a';
    ac.find(s2,cplen);
    for(register int i=1;i<=n;++i)
        printf("%d\n",ac.cnt[i]);


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