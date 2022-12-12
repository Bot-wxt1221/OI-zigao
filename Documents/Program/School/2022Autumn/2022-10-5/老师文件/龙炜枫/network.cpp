#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<ctime>
#define RI register int
using namespace std;
const int maxn=1e5+10,maxlog=18;
typedef struct
{
	int pre,dep;	
}node;
typedef struct
{
	int u,v;
}side;
typedef struct
{
	int u,nex;
}graph;
node tr[maxn],e[maxn];
side s[maxn];
graph g[maxn<<1];
int n,t,r,cnt;
int fir[maxn],anc[maxn][maxlog+1];
char inp[5];
int mod(int x);
void add(int x,int y);
void btr(int x,int pre);
int get_LCA(int x,int y);
void init(int lim);
int find(int x);
void merge(int x,int y);
int read();
void print(int x);
int main()
{
	freopen("network.in","r",stdin);freopen("network.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	n=read();t=read();init(n);
	for(RI i=1;i<n;++i) 
	{
		s[i]=(side){read(),read()};
		add(s[i].u,s[i].v);
	}
	btr(1,0);
	for(RI i=1,x,y,k,LCA;i<=t;++i)
	{
		scanf("%s",inp);
		if(inp[0]=='C')
		{
			x=read();
			merge(s[x].u,s[x].v);
		}
		else
		{
			x=read();y=read();
			if(find(x)!=find(y)) r=r^(i+x+y);
			else
			{
				LCA=get_LCA(x,y);k=e[x].dep+e[y].dep-(e[LCA].dep<<1);
				r=mod(r+(i^k));
			}
		}
	}
	printf("%d",r);
	fclose(stdin);fclose(stdout);
	return 0;
}
int mod(int x){return (x%998244353+998244353)%998244353;}
void add(int x,int y)
{
	g[++cnt]=(graph){y,fir[x]};fir[x]=cnt;
	g[++cnt]=(graph){x,fir[y]};fir[y]=cnt;
	return;
}
void btr(int x,int pre)
{
	e[x].pre=pre;e[x].dep=e[pre].dep+1;anc[x][0]=pre;
	for(RI i=1;i<=maxlog;++i)
		anc[x][i]=anc[anc[x][i-1]][i-1];
	for(RI i=fir[x];i;i=g[i].nex)
		if(g[i].u!=pre) btr(g[i].u,x);	
}
int get_LCA(int x,int y)
{
	if(e[x].dep<e[y].dep) swap(x,y);
	for(RI i=maxlog;i>=0;--i)
		if(e[anc[x][i]].dep>=e[y].dep) x=anc[x][i];
	if(x==y) return x;
	else
	{
		for(RI i=maxlog;i>=0;--i)
			if(anc[x][i]!=anc[y][i])
			{
				x=anc[x][i];
				y=anc[y][i];
			}
		return anc[x][0];	
	}	
}
void init(int lim)
{
	for(RI i=1;i<=lim;++i) tr[i]=(node){i,1};
	return;
}
int find(int x)
{
	return (tr[x].pre==x)?x:(tr[x].pre=find(tr[x].pre));
}
void merge(int x,int y)
{
	RI fx=find(x),fy=find(y);
	if(tr[fx].dep<=tr[fy].dep) tr[fx].pre=fy;
	else tr[fy].pre=fx;
	if(tr[fx].dep==tr[fy].dep && fx!=fy) ++tr[fy].dep;
	return;
}
int read(void)
{
	char putin;bool isneg=false;RI ret=0;
	putin=getchar();
	while((putin>'9' || putin<'0') && putin!='-')
		putin=getchar();
	if(putin=='-')
	{
		isneg=true;
		putin=getchar();
	}
	while(putin>='0' && putin<='9')
	{
		ret=(ret<<3)+(ret<<1)+(putin&15);
		putin=getchar();
	}
	return isneg?-ret:ret;
}
void print(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
	return;
}
/*
6 7
1 2
2 4
1 3 
3 5
5 6
C 1
C 2
C 3
C 4
C 5
Q 4 6
Q 1 6
*/
