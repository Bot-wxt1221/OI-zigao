//set�ıȽϺ���
#include<bits/stdc++.h>
using namespace std;

struct Comp
{
  bool operator() (const int &a,const int &b)//����()���������ճ�����
  {
    return a>b;      //�Ӵ�С����
    //return a < b;  //��С��������
  }
};//���ڽṹ���ڶ���ȽϺ���

int main()
{
  set<int,Comp> s;//set���õıȽϺ���ΪComp
  for(int i=1; i<=10; ++i)//�˴�����С������ֵ
    s.insert(i);
  set<int>::iterator ii;
  for(ii=s.begin(); ii!=s.end(); ii++)//����
    cout<<*ii<<' ';
  return 0;
}

