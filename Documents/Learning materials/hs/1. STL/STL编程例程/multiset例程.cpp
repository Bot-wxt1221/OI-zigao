//multiset例程
#include <bits/stdc++.h>
using namespace std;

int main()
{
  multiset<int> m;
  m.insert(11);               //插入数据
  m.insert(21);
  m.insert(10);
  m.insert(12);
  m.insert(12);
  m.insert(11);
  m.insert(11);
  m.insert(11);
  m.insert(9);
  cout<<"11的个数有"<<m.count(11)<<endl;//输出multiset中11的个数
  cout<<"第一个大于等于10的元素为："<<*m.lower_bound(10)<<endl;
  cout<<"第一个大于11的元素为:"<<*m.upper_bound(11)<<endl;
  multiset<int>::iterator it;
  for(it=m.begin(); it!=m.end(); it++)
    cout<<*it<<endl;          //从小到大输出
  cout<<"删除12,有"<<m.erase(12)<<"个"<<endl;//删除等于12的元素
  cout<<"查找9\n";
  multiset<int>::iterator i=m.find(9);//查找v,返回该元素的迭代器位置
  if(i!=m.end())              //找到则输出，否则i为end()迭代器位置
    cout<<*i<<endl;
  pair<multiset<int>::iterator,multiset<int>::iterator>p;
  int v=11;
  //equal_range:有序容器中表示一个值第一次出现与最后一次出现的后一位
  p=m.equal_range(v);         //查找所有相同元素
  cout<<"大于等于"<<v<<"的第一个元素为"<<*p.first<<endl;
  cout<<"大于"<<v<<"的第一个元素为"<<*p.second<<endl;
  cout<<"键值为"<<v<<"的全部元素为";
  for(it=p.first; it!=p.second; it++) //打印重复键值元素11
    cout<<*it<<" ";
  m.clear();                          //清空所有元素
  return 0;
}

