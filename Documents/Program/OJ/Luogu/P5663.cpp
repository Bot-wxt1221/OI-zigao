#include <cstdio>
#include <cstring>
#include <queue>
#define INPUT_DATA_TYPE int
#define MAXM (200000+10)
#define MAXN (100000+10)
#define INF 0x3f3f3f3f

struct EDGE{
    int to,next;
    EDGE(){
        next=-1;
        return;
    }
}list[MAXM];

int head[MAXN],dis0[MAXN],dis1[MAXN],tot;
char book[MAXN];
std::queue <int>q;

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

void SPFA(){
    register int u,to;
    for(register int i=0;i<MAXN;i++) dis0[i]=dis1[i]=INF;
    dis0[1]=0;
    q.push(1);
    book[1]=1;

    while(!q.empty()){
        u=q.front();
        book[u]=0;
        q.pop();
        for(register int i=head[u];~i;i=list[i].next){
            to=list[i].to;
            if(dis1[u]+1<dis0[to]){
                dis0[to]=dis1[u]+1;
                if(!book[to]){
                    q.push(to);
                    book[to]=1;
                }
            }
            if(dis0[u]+1<dis1[to]){
                dis1[to]=dis0[u]+1;
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
    int q=read();
    register int a,L;
    for(register int i=0;i<m;++i) addEdge(read(),read());

    SPFA();

    for(register int i=0;i<q;++i){
        a=read();
        L=read();
        if(L&1==1){
            if(L>=dis1[a])printf("Yes\n");
            else printf("No\n");
        }else{
            if(L>=dis0[a])printf("Yes\n");
            else printf("No\n");
        }
    }

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