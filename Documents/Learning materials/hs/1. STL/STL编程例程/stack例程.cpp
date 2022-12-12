//stack例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <stack> 
using namespace std;
#define STACK_SIZE 100

int main()
{
  stack<string> s;
  s.push("aaa");//入栈
  s.push("bbb");
  s.push("ccc");
  if(s.size()<STACK_SIZE)//可限制大小
    s.push("68");
  cout<<s.size()<<endl;//输出栈内元素个数
  while(!s.empty())//当栈不为空
  {
    cout<<s.top()<<endl;//出栈
    s.pop();//出栈
  }
  return 0;
}

