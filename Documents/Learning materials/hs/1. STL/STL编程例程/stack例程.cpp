//stack����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <stack> 
using namespace std;
#define STACK_SIZE 100

int main()
{
  stack<string> s;
  s.push("aaa");//��ջ
  s.push("bbb");
  s.push("ccc");
  if(s.size()<STACK_SIZE)//�����ƴ�С
    s.push("68");
  cout<<s.size()<<endl;//���ջ��Ԫ�ظ���
  while(!s.empty())//��ջ��Ϊ��
  {
    cout<<s.top()<<endl;//��ջ
    s.pop();//��ջ
  }
  return 0;
}

