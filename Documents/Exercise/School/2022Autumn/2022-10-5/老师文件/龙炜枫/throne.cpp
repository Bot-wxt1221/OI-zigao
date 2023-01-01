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
const int maxn=1e7+5e6+10;
typedef struct
{
	int s;
	bool gdr;
}node;
node e[maxn];
int n,m,ans;
int read();
void print(int x);
void calc(int x,int l,int r);
int main()
{
	freopen("throne.in","r",stdin);freopen("throne.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	n=read()-1;m=read();
	for(RI i=0;i<=n;++i) e[i]=(node){read(),read()};
	for(RI i=1,pre=0;i<=n;)
		if(i==m) 
		{
			calc(i,pre+1,pre+e[pre].s);
			break;
		}
		else if(m>i && m<=i+e[i].s)
		{
			calc(i,pre+1,pre+e[pre].s);
			pre=i;++i;
		}
		else i+=e[i].s+1;
	print(ans);	
	fclose(stdin);fclose(stdout);
	return 0;
}
void calc(int x,int l,int r)
{
	if(e[x].gdr)
		for(RI i=l;i<x;i+=e[i].s+1)
			if(!e[i].gdr) ans-=e[i].s+1;
	if(!e[x].gdr)
		for(RI i=x;i<=r;i+=e[i].s+1)
			if(e[i].gdr) ans+=e[i].s+1;
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
