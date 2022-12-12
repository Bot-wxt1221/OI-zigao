//Éä¼ý
#include <bits/stdc++.h>
using namespace std;

map <int,int> Map;

int main()
{
  freopen("toxophily.in","r",stdin);
  freopen("toxophily.out","w",stdout);
  int t,n,v,m;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&t);
    Map[t]=i;
  }
  cin>>v;
  for(int i=1; i<=v; i++)
  {
    scanf("%d",&m);
    printf("%d\n",Map[m]);
  }
  return 0;
}

