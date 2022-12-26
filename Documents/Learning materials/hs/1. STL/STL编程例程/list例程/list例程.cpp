//list����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <list>
using namespace std;

int main()
{
  list<int>l;
  l.push_back(2);//β��������Ԫ�أ������Զ�����
  l.push_back(2);
  l.push_back(9);
  l.push_back(12);
  l.push_back(12);
  l.push_back(4);
  l.push_back(4);
  l.push_back(6);
  //l.clear();//�������
  l.push_front(9);//ͷ��������Ԫ�أ������Զ�����
  list<int>::iterator it;
  it=l.begin();
  it++;//����������ֻ��++��--���������ܽ���+n��������Ϊlist�ڵ㲻�������ڴ�
  l.insert(it,20);//��ǰλ�ò�����Ԫ��
  it++;
  l.erase(it);//ɾ��������λ���ϵ�Ԫ��
  for(it=l.begin(); it!=l.end(); it++) //�������
    cout<<*it<<" ";
  cout<<endl;
  l.remove(12);//ɾ������ֵΪ12��Ԫ��
  l.pop_front();//ɾ��������Ԫ��
  l.pop_back();//ɾ������βԪ��
  it=find(l.begin(),l.end(),4);//����Ԫ��ֵΪ4
  if(it!=l.end())
    cout<<"find "<<*it<<endl;
  l.sort();//��������
  l.unique();//ɾ�������ظ�Ԫ�أ�ֻ����һ����
  for(it=l.begin(); it!=l.end(); it++) //�������
    cout<<*it<<" ";
  cout<<endl;
  return 0;
}

