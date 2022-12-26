//���ȶ�������
#include<bits/stdc++.h>
using namespace std;

int main()
{
  priority_queue<int> q;
  q.push(93);//��ӣ�������Ԫ��
  q.push(5);
  q.push(2);
  q.push(33);
  q.push(52);
  q.push(12);

  cout<<"Ԫ�ظ���Ϊ��"<<q.size()<<endl;
  while(!q.empty())//�����в�Ϊ��
  {
    cout<<q.top()<<endl;//ȡ����Ԫ��
    q.pop();//������Ҫ���ж��Ƿ�Ϊ��
  }
  return 0;
}

