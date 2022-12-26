//�ṹ��map����
#include<bits/stdc++.h>
using namespace std;

struct Info                             //ѧ����Ϣ�ṹ��
{
  char *xm;                             //����
  int y;                                //���
  char *d;                              //��ַ
};

struct Record                           //ѧ����¼�ṹ��
{
  int id;                               //ѧ������ֵ
  Info sf;                              //ѧ����Ϣ��ӳ������
};

int main()
{
  Record srArray[]=
  {
    {4,"Li",21,"beijing"},
    {2,"wang",29,"shanghai"},
    {3,"zhang",30,"shengzheng"}
  };
  map<int,Info, greater<int> >m;        //����ֵ�ɴ�С����
  for(int j=0; j<3; j++)                //װ������ѧ����Ϣ
    m[srArray[j].id]=srArray[j].sf;
  Record s1= {5,"Ling",23,"XINJIANG"};
  m.insert(make_pair(s1.id,s1.sf));     //����������Ϣ
  map<int,Info>::iterator i;
  for(i=m.begin(); i!=m.end(); i++)     //�������
    cout<<(*i).first<<' '<<(*i).second.xm<<' '<<(*i).second.d<<'\n';
  i=m.find(2);                          //���Ҽ�ֵΪ2�ļ�¼�����
  cout<<"��ֵ2��"<<(*i).second.xm<<' '<<(*i).second.d;
  return 0;
}

