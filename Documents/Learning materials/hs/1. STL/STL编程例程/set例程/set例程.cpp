//set����
#include<bits/stdc++.h>
using namespace std;

int main()
{
  set<int> s;
  for(int i=10; i>0; --i)                       //�˴��ɴ�С��ֵ
    s.insert(i);                                //����Ԫ��
  set<int> s2(s);                               //����s����s2
  s.erase(s.begin());                           //ɾ������
  s.erase(6);
  s.insert(5);                                  //�����ظ�����
  set<int>::iterator ii;                        //iiΪǰ�������
  for(ii=s.begin(); ii!=s.end(); ii++)          //����
    cout<<*ii<<' ';
  cout<<"\nԪ�ظ���Ϊ"<<s.size();//ͳ��set��Ԫ�ظ�����ʱ�临�Ӷ�O(1)
  ii=s.find(10);    //����Ԫ��ֵ��������ָ���Ԫ�صĵ�����
  if(ii!=s.end())   //�������в����ڸ�Ԫ�أ�����ֵ����s.end()
    cout<<"\n����="<<*ii;
  if(s.count(5))    //����set��ֵΪ5��Ԫ�ظ�����ʱ�临�Ӷ�ΪO(log n)
    cout<<"\n����Ԫ��5";
  s.clear();        //�������Ԫ��
  cout<<"\nԪ���Ƿ�Ϊ��:"<<s.empty();
  return 0;
}

