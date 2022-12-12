//set例程
#include <bits/stdc++.h>
using namespace std;

int main()
{
  set<int> s;
  for(int i=10; i>0; --i)                       //此处由大到小赋值
    s.insert(i);                                //插入元素
  set<int> s2(s);                               //拷贝s生成s2
  s.erase(s.begin());                           //删除操作
  s.erase(6);
  s.insert(5);                                  //不会重复插入
  set<int>::iterator ii;                        //ii为前向迭代器
  for(ii=s.begin(); ii!=s.end(); ii++)          //遍历
    cout<<*ii<<' ';
  cout<<"\n元素个数为"<<s.size();//统计set中元素个数，时间复杂度O(1)
  ii=s.find(10);    //查找元素值，并返回指向该元素的迭代器
  if(ii!=s.end())   //如容器中不存在该元素，返回值等于s.end()
    cout<<"\n查找="<<*ii;
  if(s.count(5))    //返回set中值为5的元素个数，时间复杂度为O(log n)
    cout<<"\n存在元素5";
  s.clear();        //清空所有元素
  cout<<"\n元素是否为空:"<<s.empty();
  return 0;
}

