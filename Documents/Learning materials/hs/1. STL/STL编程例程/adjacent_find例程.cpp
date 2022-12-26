//adjacent_find����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

bool Equal(int x,int y)//�����ж��Ƿ���ż��ͬ
{
  return (x-y)%2==0?1:0;
}

int main()
{
  list<int>l;
  l.push_back(93);
  l.push_back(5);
  l.push_back(2);
  l.push_back(2);
  l.push_back(33);
  l.push_back(52);
  l.push_back(12);
  //�����ڽ���ȵ�Ԫ��
  list<int>::iterator i=adjacent_find(l.begin(),l.end());
  if(i!=l.end())
  {
    cout<<"�������ڵ�Ԫ�����"<<*i<<' ';
    i++;
    cout<<*i<<endl;
  }
  // �ҳ��׸��������ڵ�Ԫ����ż����ͬ
  list<int>::iterator ii=adjacent_find(l.begin(),l.end(),Equal);
  if(i!=l.end())
  {
    cout<<"�ҳ��׸��������ڵ�Ԫ����ż����ͬ"<<*ii<<' ';
    ii++;
    cout<<*ii<<endl;
  }
  return 0;
}

