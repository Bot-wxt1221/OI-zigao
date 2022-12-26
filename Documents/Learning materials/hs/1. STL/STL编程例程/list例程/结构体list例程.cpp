//�ṹ��list����
#include<bits/stdc++.h>
using namespace std;

struct student
{
  char *name;
  int age;
  char *city;
};

int main()
{
  student s[]=
  {
    {"����",18,"�㽭"},
    {"����",19,"����"},
    {"����",18,"�Ϻ�"}
  };
  list<student>l;
  l.push_back(s[0]);//����Ԫ��
  l.push_back(s[1]);
  l.push_back(s[2]);
  student x= {"����",19,"�½�"};
  l.push_front(x);//���뵽��λ�����Ӷ�ΪO(1)
  l.insert(l.begin(),x);//��������λ��,ʱ�临�Ӷ�O(1)
  //l.pop_front();//ɾ����Ԫ��
  //l.pop_back();//ɾ��βԪ��
  l.erase(l.begin());
  //l.erase(l.begin(),l.end());//ɾ�������Ԫ��
  for(list<student>::iterator i=l.begin(); i!=l.end(); i++)
    cout<<(*i).name<<"  "<<(*i).age<<"  "<<(*i).city<<"\n";
  return 0;
}

