//迭代器访问vector
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int j;
  vector<int> v;
  v.reserve(30);                         //调整数据空间大小
  for(int i=0; i<10; i++)
    v.push_back(i);                      //尾端插入新元素
  vector<int>::iterator i;               //定义vector的迭代器i
  for(i=v.begin(); i!=v.end(); i++)      //迭代器遍历
    cout<<*i<<" ";
  cout<<"\n v中的元素个数:"<<v.size()<<'\n';//元素实际个数
  reverse(v.begin(),v.end());            //反转
  for(i=v.begin(); i!=v.end(); i++)      //迭代器遍历
    cout<<*i<<" ";
  v.clear();                             //全部清空元素
  cout<<"\n v是否为空:"<<v.empty()<<'\n'; //判断是否为空
  return 0;
}

