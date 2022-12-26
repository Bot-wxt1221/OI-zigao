//��������
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <queue> 
using namespace std;

int main()
{
  queue<int> q;
  q.push(3);//���
  q.push(5);
  q.push(2);
  cout<<"Ԫ�ظ���Ϊ��"<<q.size()<<endl;
  cout<<q.back();//ȡ��βԪ��
  while(!q.empty())//������δ��
  {
    cout<<q.front()<<endl;//��ӡ����Ԫ��
    q.pop();//����
  }
  return 0;
}

