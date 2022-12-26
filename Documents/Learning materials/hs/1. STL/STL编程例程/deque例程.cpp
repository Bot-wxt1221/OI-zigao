//deque����
#include<bits/stdc++.h>
using namespace std;

int main()
{
  deque<string>d;//����һ������string���͵�deque
  d.push_back("A");//β������Ԫ��
  d.push_back("B");
  d.push_back("C");
  d.push_front("X");//ͷ������Ԫ��
  d.push_front("Y");
  //d.pop_front();//ɾ����Ԫ��
  //d.pop_back();//ɾ��βԪ��
  //d.erase(d.begin()+1);//ɾ��ָ��λ��Ԫ��
  //d.clear();//ɾ������Ԫ��
  d.insert(d.end()-2,"O");//ָ��λ�ò���

  reverse(d.begin(),d.end());//��תԪ��˳��
  for(int i=0; i<d.size(); i++) //���鷽ʽ����
    cout<<d[i]<<" ";
  cout<<endl;

  swap(d[1],d[2]);//��Ԫ�ؽ���
  deque<string>::iterator i;//����������
  for(i=d.begin(); i!=d.end(); i++)
    cout<<*i<<" ";
  cout<<endl;

  cout<<"\ndeque�Ƿ�Ϊ�� "<<d.empty();
  cout<<"\ndequeԪ�ظ���Ϊ "<<d.size();
  cout<<"\ndeque����Ԫ��Ϊ "<<d.front();
  cout<<"\ndeque��ĩԪ��Ϊ "<<d.back();
  return 0;
}

