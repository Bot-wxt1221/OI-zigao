#include<bits/stdc++.h>

#define QUEUE_DATA_TYPE int
const int QUEUE_SIZE = 5000100;
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

	QUEUE_DATA_TYPE read(register int in){
		return q[(head+in)%QUEUE_SIZE];
	}
};

using namespace std;
#define int long long
#define ll long long
const int Maxn=1000100;
const int Maxm=4000100;
int n,k1;
int S;
int head[Maxn],tot;
struct Edge{
    int to;
    int w;
    int nxt;
}E[Maxm];
void addedge(int u,int v,int w)
{
    tot++;
    E[tot].to=v;
    E[tot].w=w;
    E[tot].nxt=head[u];
    head[u]=tot;
}
int dis[Maxn],deg[Maxn];
char vis[Maxn];
//class Queue{
//  private:
//      int st[500010];
//      int Front,Tail;
//      int siz;
//  public:
//      bool empty()
//      {
//          return siz==0;
//      }
//      void clear()
//      {
//          memset(st,0,sizeof(st));
//          Front=1;
//          Tail=0;
//          siz=0;
//      }
//      void push(int x)
//      {
//          st[++Tail]=x;
//          siz++;
//      }
//      void pop()
//      {
//          st[Front++]=0;
//          siz--;
//      }
//      int front()
//      {
//          return st[Front];
//      }
//}q;
bool spfa(int S)
{
//  memset(dis,0x3f,sizeof(dis));
    QUEUE q;
    dis[S]=0;
    vis[S]=1;
    q.push(S);
    deg[S]=1;
    register int u,v,w,i;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        vis[u]=0;
        for(i=head[u];i;i=E[i].nxt)
        {
            v=E[i].to,w=E[i].w;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;

                if(!vis[v])
                {
                    if(++deg[v]>=n)
                    {
                        return false;
                    }
                    vis[v]=true;
                    q.push(v);
                }

            }
        }
    }

    return true;
}

int read(){
    register int x=0,f=1;register char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}

signed main()
{
    scanf("%lld%lld",&n,&k1);
    S=0;
    for(register int i=1;i<=k1;i++)
    {
        int x,a,b;
        x=read();
        a=read();
        b=read();
        switch(x)
        {
            case 1:{
                //Xa=Xb  ==> Xa-Xb<=0,Xa-Xb>=0 
                addedge(a,b,0);
                addedge(b,a,0);
                break;
            }
            case 2:{
                //Xa<Xb ==> Xa-Xb<=-1
                addedge(a,b,1);
                break;
            }
            case 3:{
                //Xa>=Xb ==> Xb-Xa<=0
                addedge(b,a,0);
                break;
            }
            case 4:{
                //Xa>Xb ==> Xb-Xa<0 Xb-Xa<=-1
                addedge(b,a,1);
                break;
            }
            default:{
                //Xa<=Xb ==> Xa-Xb<=0
                addedge(a,b,0); 
                break;
            }
        }
    }

    for(register int i=1;i<=n;i++)
    {
        addedge(S,i,1);
    }
    if(!spfa(S))
    {
        puts("-1");
    }else{
        register int ans=0;
        for(register int i=1;i<=n;i++)
        {
//          cout<<dis[i]<<" ";
            ans+=dis[i];
        }
//      cout<<endl;
        printf("%lld\n",ans);
    }
    return 0;
}

//a[u]-a[v]<=w:
//u->v: -w
//Calculate Longest Path