//list例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <list>
using namespace std;

int main()
{
  list<int>l;
  l.push_back(2);//尾部插入新元素，链表自动扩张
  l.push_back(2);
  l.push_back(9);
  l.push_back(12);
  l.push_back(12);
  l.push_back(4);
  l.push_back(4);
  l.push_back(6);
  //l.clear();//清空链表
  l.push_front(9);//头部插入新元素，链表自动扩张
  list<int>::iterator it;
  it=l.begin();
  it++;//链表迭代器只能++或--操作，不能进行+n操作，因为list节点不是连续内存
  l.insert(it,20);//当前位置插入新元素
  it++;
  l.erase(it);//删除迭代器位置上的元素
  for(it=l.begin(); it!=l.end(); it++) //正向遍历
    cout<<*it<<" ";
  cout<<endl;
  l.remove(12);//删除所有值为12的元素
  l.pop_front();//删除链表首元素
  l.pop_back();//删除链表尾元素
  it=find(l.begin(),l.end(),4);//查找元素值为4
  if(it!=l.end())
    cout<<"find "<<*it<<endl;
  l.sort();//升序排列
  l.unique();//删除连续重复元素（只保留一个）
  for(it=l.begin(); it!=l.end(); it++) //正向遍历
    cout<<*it<<" ";
  cout<<endl;
  return 0;
}

