#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

std::queue<int>Q;

struct node{
    int to,next;
    node(){
        next=-1;
    }
}e[5000005];

int head[50005],d[50005],time[50005],tot;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
void addEdge(int u,int v){
    e[tot].next=head[u];
    e[tot].to=v;
    head[u]=tot;
    ++tot;
}
/*
5 5 2
1 2
4
3 2 1 2
4 3 1 2 3
5 3 1 3 4
1 0
*/
int main(){
    memset(head,-1,sizeof(head));
    memset(time,-1,sizeof(time));
    register int i,j;
    int v,s,u;
    int n=read();
    int k=read();
    int p=read();

    for(i=0;i<p;++i){
        u=read();
        time[u]=0;
        Q.push(u);
    }

    int r=read();

    for(i=1;i<=r;++i){
        v=read();
        s=read();
        d[v]=s;
        for(j=0;j<s;++j){
            u=read();
            addEdge(u,v);
        }
        if(!time[v]) d[v]=0;
    }

    while(!Q.empty()){
        u=Q.front();
        Q.pop();
        for(i=head[u];~i;i=e[i].next){
            --d[e[i].to];
            time[e[i].to]=std::max(time[e[i].to],time[u]+1);
            if(!d[e[i].to]){
                Q.push(e[i].to);
            }
        }
    }

    if(d[k]) time[k]=-1;
    printf("%d",time[k]);

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