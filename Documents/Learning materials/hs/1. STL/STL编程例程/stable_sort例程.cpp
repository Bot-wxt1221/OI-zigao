//stable_sort����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

struct stu
{
  int id;
  char *name;
  int score;
};

bool comByscore(stu s1,stu s2)
{
  return s1.score<s2.score?1:0;
}

bool comByid(stu s1,stu s2)
{
  return s1.id>s2.id?1:0;
}

int main()
{
  vector<stu> v;
  struct stu master;
  master.id = 3;
  master.name = "clare";
  master.score=60;
  v.push_back(master);
  master.id = 2;
  master.name = "Liqiang";
  master.score=99;
  v.push_back(master);
  master.id = 1;
  master.name = "qiangYi";
  master.score=88;
  v.push_back(master);
  stable_sort(v.begin(),v.end(),comByscore);//����������
  for(int i=0; i<v.size(); i++)
    cout<<v[i].id<<' '<<v[i].name<<' '<<v[i].score<<endl;
  stable_sort(v.begin(),v.end(),comByid);//��ѧ��������
  for(int i=0; i<v.size(); i++)
    cout<<v[i].id<<' '<<v[i].name<<' '<<v[i].score<<endl;
  return 0;
}

