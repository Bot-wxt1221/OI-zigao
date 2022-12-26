//set�Ľṹ������
#include<bits/stdc++.h>
using namespace std;

struct Info
{
  string name;
  double score;
  bool operator < (const Info &a) const //����"<"������,�ճ�����
  {
    return a.score <score;      //�Ӵ�С����
    //return a.score >score;  //��С��������
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
  for(ii=s.begin(); ii!=s.end(); ii++)//����
    cout<<(*ii).name<<' '<<(*ii).score<<endl;
  return 0;
}

