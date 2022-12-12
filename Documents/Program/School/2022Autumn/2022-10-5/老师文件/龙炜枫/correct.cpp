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
const int maxn=1e3+10;
typedef struct
{
	int u,nex;
}side;
side s[maxn];
int n,m,cnt;
int cnt_in[maxn],fir[maxn];
priority_queue <int,vector<int>,greater<int> > q;
void add(int x,int y)
{
	s[++cnt]=(side){y,fir[x]};fir[x]=cnt;
}
int main()
{
	freopen("correct.in","r",stdin);freopen("correct.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(RI x,y;m;--m)
	{
		cin >> x >> y;
		add(x,y);++cnt_in[y];
	}
	for(RI i=1;i<=n;++i)
		if(!cnt_in[i]) q.push(i);
	for(RI tpf;!q.empty();)
	{	
		tpf=q.top();q.pop();
		printf("%d ",tpf);
		for(RI i=fir[tpf];i;i=s[i].nex)
		{
			--cnt_in[s[i].u];
			if(!cnt_in[s[i].u]) q.push(s[i].u);
		}
	}	
	fclose(stdin);fclose(stdout);
	return 0;
}
