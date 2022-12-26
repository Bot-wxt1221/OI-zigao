#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

#define QUEUE_DATA_TYPE int
const int QUEUE_SIZE = 3000+10;
struct QUEUE{
	QUEUE_DATA_TYPE q[QUEUE_SIZE];
	int head,tail,num;

	QUEUE(){
		head=0;
		tail=-1;
		num=0;
		return;
	}

	void push(QUEUE_DATA_TYPE in){
		tail=(tail+1)%QUEUE_SIZE;
		q[tail]=in;
		++num;
		return;
	}

	void push_front(QUEUE_DATA_TYPE in){
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


	QUEUE_DATA_TYPE front(){
		return q[head];
	}

	QUEUE_DATA_TYPE back(){
		return q[tail];
	}

	void clear(){
		head=0;
		tail=-1;
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

	QUEUE_DATA_TYPE read(int in){
		return q[(head+in)%QUEUE_SIZE];
	}
}q;

#define INPUT_DATA_TYPE int
#define MAXM (6000+10)
#define MAXN (3000+10)
#define INF ((0x7f7f7f7f)>>2)

struct EDGE{
    int to,next;
    EDGE(){
        next=-1;
        return;
    }
}list[MAXM];

int head[MAXN],dis1[MAXN],dis2[MAXN],dis3[MAXN],tot;
char book[MAXN];

void addEdge(register int u,register int v){
    list[tot].next=head[u];;
    head[u]=tot;
    list[tot].to=v;
    ++tot;

    list[tot].next=head[v];;
    head[v]=tot;
    list[tot].to=u;
    ++tot;
}

void SPFA(int s,int *dis){
    register int u,to;
    for(register int i=0;i<MAXN;i++) dis[i]=INF;
    dis[s]=0;
    q.push(s);
    book[s]=1;

    while(!q.empty()){
        u=q.front();
        book[u]=0;
        q.pop();
        for(register int i=head[u];~i;i=list[i].next){
            to=list[i].to;
            if(dis[u]+1<dis[to]){
                dis[to]=dis[u]+1;
                if(!book[to]){
                    q.push(to);
                    book[to]=1;
                }
            }
        }
    }
}

INPUT_DATA_TYPE read();
void print(int x);

int main(){
    memset(head,-1,sizeof(head));

    int n=read();
    int m=read();
    int s1,t1,s2,t2;
    register int ans=INF;
    for(register int i=0;i<m;++i) addEdge(read(),read());

    s1=read();
    t1=read();
    s2=read();
    t2=read();

    SPFA(1,dis1);
    SPFA(s1,dis2);
    SPFA(s2,dis3);

    if(dis1[s1]>t1||dis1[s2]>t2){
        printf("-1");
        return 0;
    }

    for(register int i=1;i<=n;++i){
        ans=std::min(ans,dis1[i]+dis2[i]+dis3[i]);
    }

    print(m-ans);

    return 0;
}

int read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(INPUT_DATA_TYPE x){
    char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
}