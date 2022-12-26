//multiset����
#include<bits/stdc++.h>
using namespace std;

int main()
{
  multiset<int> m;
  m.insert(11);               //��������
  m.insert(21);
  m.insert(10);
  m.insert(12);
  m.insert(12);
  m.insert(11);
  m.insert(11);
  m.insert(11);
  m.insert(9);
  cout<<"11�ĸ�����"<<m.count(11)<<endl;//���multiset��11�ĸ���
  cout<<"��һ�����ڵ���10��Ԫ��Ϊ��"<<*m.lower_bound(10)<<endl;
  cout<<"��һ������11��Ԫ��Ϊ:"<<*m.upper_bound(11)<<endl;
  multiset<int>::iterator it;
  for(it=m.begin(); it!=m.end(); it++)
    cout<<*it<<endl;          //��С�������
  cout<<"ɾ��12,��"<<m.erase(12)<<"��"<<endl;//ɾ������12��Ԫ��
  cout<<"����9\n";
  multiset<int>::iterator i=m.find(9);//����v,���ظ�Ԫ�صĵ�����λ��
  if(i!=m.end())              //�ҵ������������iΪend()������λ��
    cout<<*i<<endl;
  pair<multiset<int>::iterator,multiset<int>::iterator>p;
  int v=11;
  //equal_range:���������б�ʾһ��ֵ��һ�γ��������һ�γ��ֵĺ�һλ
  p=m.equal_range(v);         //����������ͬԪ��
  cout<<"���ڵ���"<<v<<"�ĵ�һ��Ԫ��Ϊ"<<*p.first<<endl;
  cout<<"����"<<v<<"�ĵ�һ��Ԫ��Ϊ"<<*p.second<<endl;
  cout<<"��ֵΪ"<<v<<"��ȫ��Ԫ��Ϊ";
  for(it=p.first; it!=p.second; it++) //��ӡ�ظ���ֵԪ��11
    cout<<*it<<" ";
  m.clear();                          //�������Ԫ��
  return 0;
}

