//set的结构体排序
#include <bits/stdc++.h>
using namespace std;

struct Info
{
  string name;
  double score;
  bool operator < (const Info &a) const //重载"<"操作符,照抄即可
  {
    return a.score <score;      //从大到小排序
    //return a.score >score;  //从小到大排序
  }
} info;

int main()
{
  set<Info> s;
  info= {"A",90.0};
  s.insert(info);
  info= {"B",92.0};
  s.insert(info);
  info= {"C",96.0};
  s.insert(info);

  set<Info>::iterator ii;
  for(ii=s.begin(); ii!=s.end(); ii++)//遍历
    cout<<(*ii).name<<' '<<(*ii).score<<endl;
  return 0;
}

