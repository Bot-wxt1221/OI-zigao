#include<cstdio>
// #define file
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

#define QUEUE_DATA_TYPE int
const int QUEUE_SIZE = 210;
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

	void pop(){
		head=(head+1)%QUEUE_SIZE;
		--num;
		return;
	}

	void pop_back(){
		tail=(tail-1+QUEUE_SIZE)%QUEUE_SIZE;
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
}Q;

struct node{
    int to,next;
    node(){
        next=-1;
    }
}e[200*200+10];

int head[210],V[210],d[210],dp[210],pr[210],stack[210],tot;

void addEdge(int u,int v){
    ++d[v];
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot;
    ++tot;
    return;
}

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
	#ifdef file
	freopen("mine.in", "r", stdin);
	freopen("mine.out", "w", stdout);
	#endif

    register int i,u,v,best;
    int n=read();

    for(i=1;i<=n;++i) V[i]=read(),head[i]=-1;
    while(1){
        u=read();
        v=read();
        if(!u&&!v) break;
        addEdge(u,v);
    }

    for(i=1;i<=n;++i)
        if(!d[i]){
            Q.push(i);
            dp[i]=V[i];
        }


    best=-1;

    while(Q.size()){
        u=Q.front();
        if(dp[u]>best){
            best=dp[u];
            v=u;
        }
        Q.pop();
        for(i=head[u];~i;i=e[i].next){
            --d[e[i].to];
            if(dp[e[i].to]<dp[u]+V[e[i].to]){
                dp[e[i].to]=dp[u]+V[e[i].to];
                pr[e[i].to]=u;
            }
            if(!d[e[i].to])
                Q.push(e[i].to);
        }
    }

    u=0;
    while(v){
        stack[++u]=v;
        v=pr[v];
    }

    while(u){
        print(stack[u--]);
        if(u)putchar('-');
    }

    putchar('\n');
    print(best);

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