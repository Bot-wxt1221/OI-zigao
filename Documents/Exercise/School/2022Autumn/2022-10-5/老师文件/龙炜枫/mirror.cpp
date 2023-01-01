#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<ctime>
#define ll long long
#define RL register long long
#define RN register node
using namespace std;
const ll maxn=1e6+10;
typedef struct
{
	ll x,y;
	bool type;/*0->\ 1->/*/
}node;
node lsr;
node ex[maxn],ey[maxn],dir[4]={(node){1,0,0},(node){0,1,0},(node){-1,0,0},(node){0,-1,0}};
ll n,m,T;
char inp[5];
bool cmp_x(node x,node y);
bool cmp_y(node x,node y);
ll get_mdis(node x,node y);
node fm(node x,ll d);
ll change_d(ll d,node x);
void final_calc(node s,ll rs,ll d);
ll read();
void print(ll x);
int main()
{
	freopen("mirror.in","r",stdin);freopen("mirror.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	n=read();m=read();T=read(); 
	for(RL i=1;i<=n;++i)
	{
		ex[i]=(node){read(),read()};
		scanf("%s",inp);
		ex[i].type=(inp[0]=='/')?1:0;
		ey[i]=ex[i];
	}
	lsr=(node){0,0,0};
	sort(ex+1,ex+n+1,cmp_x);sort(ey+1,ey+n+1,cmp_y);
	for(ll s=0,d=0;s<T;)
	{
		RN nex=fm(lsr,d);
		if(!nex.x && !nex.y && !nex.type)
		{
			final_calc(lsr,T-s,d);
			s+=T;
		}
		else if(get_mdis(nex,lsr)+s<T)
		{
			s+=get_mdis(nex,lsr);
			lsr=nex;d=change_d(d,nex);
		}
		else 
		{
			final_calc(lsr,T-s,d);
			s+=get_mdis(nex,lsr);
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
bool cmp_x(node x,node y)
{
	if(x.x==y.x) return x.y<y.y;
	else return x.x<y.x;
}
bool cmp_y(node x,node y)
{
	if(x.y==y.y) return x.x<y.x;
	else return x.y<y.y;
}
ll get_mdis(node x,node y){return abs(x.x-y.x)+abs(x.y-y.y);}
node fm(node x,ll d)
{
	ll lx,rx,ly,ry;
	if(!d)
	{
		ly=1;ry=n;
		while(ly<ry)
		{
			RL mid=(ly+ry)>>1;
			if(ey[mid].y<x.y) ly=mid+1;
			else ry=mid;
		}
		if(ey[ly].y!=x.y) return (node){0,0,0};
		lx=ly;ly=1;ry=n;
		while(ly<ry)
		{
			RL mid=(ly+ry)>>1;
			if(ey[mid].y<x.y+1) ly=mid+1;
			else ry=mid;
		}
		rx=ly-1;
		if(ey[rx].x<x.x) return (node){0,0,0};
		while(lx<rx)
		{
			RL mid=(lx+rx)>>1;
			if(ey[mid].x<x.x) lx=mid+1;
			else rx=mid;
		}
		return ey[lx];
	}
	else if(d==1)
	{
		lx=1;rx=n;
		while(lx<rx)
		{
			RL mid=(lx+rx)>>1;
			if(ex[mid].x<x.x) lx=mid+1;
			else rx=mid;
		}
		if(ex[lx].x!=x.x) return (node){0,0,0};
		ly=lx;lx=1;rx=n;
		while(lx<rx)
		{
			RL mid=(lx+rx)>>1;
			if(ex[mid].x<x.x+1) lx=mid+1;
			else rx=mid;
		}
		ry=lx-1;
		if(ex[ry].y<x.y) return (node){0,0,0};
		while(ly<ry)
		{
			RL mid=(ly+ry)>>1;
			if(ex[mid].y<x.y) ly=mid+1;
			else ry=mid;
		}
		return ex[ly];
	}
	else if(d==2)
	{
		ly=1;ry=n;
		while(ly<ry)
		{
			RL mid=(ly+ry)>>1;
			if(ey[mid].y<x.y) ly=mid+1;
			else ry=mid;
		}
		if(ey[ly].y!=x.y) return (node){0,0,0};
		lx=ly;ly=1;ry=n;
		while(ly<ry)
		{
			RL mid=(ly+ry)>>1;
			if(ey[mid].y<x.y+1) ly=mid+1;
			else ry=mid;
		}
		rx=ly-1;
		if(ey[rx].x>x.x) return (node){0,0,0};
		while(lx<rx)
		{
			RL mid=(lx+rx)>>1;
			if(ey[mid].x<=x.x) lx=mid+1;
			else rx=mid;
		}
		return ey[lx-1];
	}
	else
	{
		lx=1;rx=n;
		while(lx<rx)
		{
			RL mid=(lx+rx)>>1;
			if(ex[mid].x<x.x) lx=mid+1;
			else rx=mid;
		}
		if(ex[lx].x!=x.x) return (node){0,0,0};
		ly=lx;lx=1;rx=n;
		while(lx<rx)
		{
			RL mid=(lx+rx)>>1;
			if(ex[mid].x<x.x+1) lx=mid+1;
			else rx=mid;
		}
		ry=lx-1;
		if(ex[ry].y>x.y) return (node){0,0,0};
		while(ly<ry)
		{
			RL mid=(ly+ry)>>1;
			if(ex[mid].y<=x.y) ly=mid+1;
			else ry=mid;
		}
		return ex[ly-1];
	}
}
ll change_d(ll d,node x)
{
	if(x.type) return (!d)?1:(d==1)?0:(d==2)?3:2;
	else return (!d)?3:(d==1)?2:(d==2)?1:0;
}
void final_calc(node s,ll rs,ll d)
{
	printf("%lld %lld",s.x+rs*dir[d].x,s.y+rs*dir[d].y);
	return;
}
ll read(void)
{
	char putin;bool isneg=false;RL ret=0;
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
void print(ll x)
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

