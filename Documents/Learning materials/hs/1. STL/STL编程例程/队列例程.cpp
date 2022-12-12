//队列例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <queue> 
using namespace std;

int main()
{
  queue<int> q;
  q.push(3);//入队
  q.push(5);
  q.push(2);
  cout<<"元素个数为："<<q.size()<<endl;
  cout<<q.back();//取队尾元素
  while(!q.empty())//当队列未空
  {
    cout<<q.front()<<endl;//打印队首元素
    q.pop();//出队
  }
  return 0;
}

