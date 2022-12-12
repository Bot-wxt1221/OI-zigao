//deque例程
#include <bits/stdc++.h>
using namespace std;

int main()
{
  deque<string>d;//定义一个包含string类型的deque
  d.push_back("A");//尾部插入元素
  d.push_back("B");
  d.push_back("C");
  d.push_front("X");//头部插入元素
  d.push_front("Y");
  //d.pop_front();//删除首元素
  //d.pop_back();//删除尾元素
  //d.erase(d.begin()+1);//删除指定位置元素
  //d.clear();//删除所有元素
  d.insert(d.end()-2,"O");//指定位置插入

  reverse(d.begin(),d.end());//反转元素顺序
  for(int i=0; i<d.size(); i++) //数组方式访问
    cout<<d[i]<<" ";
  cout<<endl;

  swap(d[1],d[2]);//两元素交换
  deque<string>::iterator i;//迭代器访问
  for(i=d.begin(); i!=d.end(); i++)
    cout<<*i<<" ";
  cout<<endl;

  cout<<"\ndeque是否为空 "<<d.empty();
  cout<<"\ndeque元素个数为 "<<d.size();
  cout<<"\ndeque的首元素为 "<<d.front();
  cout<<"\ndeque的末元素为 "<<d.back();
  return 0;
}

