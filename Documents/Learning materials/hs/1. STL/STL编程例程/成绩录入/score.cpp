//pairѧ���ɼ�¼��
#include <bits/stdc++.h>
using namespace std;
typedef pair<string, double> p;//ʹ��typedef��pair������Ϊp

int main()
{
  freopen("score.in","r",stdin);
  freopen("score.out","w",stdout);
  vector< p > VP;
  p p1;
  while(cin>>p1.first>>p1.second)
  {
    if(p1.second==0)
      break;
    VP.push_back(make_pair(p1.first,p1.second));
  }
  vector<p>::iterator it;
  for(it=VP.begin(); it!=VP.end(); ++it)
    cout<<it->first<<","<<it->second<<endl;
  return 0;
}

