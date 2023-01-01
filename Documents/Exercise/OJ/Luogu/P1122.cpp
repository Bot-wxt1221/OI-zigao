#include<cstdio>
#include<cstring>
#include<algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN 16010

struct EDGE{
    int to,next;
    EDGE(){
        next=to=-1;
        return;
    }
}tree[MAXN<<1];

long long w[MAXN],best;
int head[MAXN],tot;
char book[MAXN];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
void addEdge(int u,int v){
    tree[tot].next=head[u];
    tree[tot].to=v;
    head[u]=tot;
    ++tot;

    tree[tot].next=head[v];
    tree[tot].to=u;
    head[v]=tot;
    ++tot;

    return;
}

long long dfs(int u){
    book[u]=1;
    long long now=0;
    long long temp;
    for(register int i=head[u];~i;i=tree[i].next){
        if(!book[tree[i].to]){
            temp=dfs(tree[i].to);
            now=std::max(now+temp,std::max(now,temp));
        }
    }
    best=std::max(std::max(now+w[u],w[u]),best);
    return std::max(now+w[u],w[u]);
}

int main(){
    memset(head,-1,sizeof(head));
    best=-2147483648;
    int n=read();
    int u,v;

    for(register int i=1;i<=n;++i) w[i]=read();

    for(register int i=0;i<n-1;++i){
        u=read();
        v=read();
        addEdge(u,v);
    }

    dfs(1);

    print(best);

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    char s[20];
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