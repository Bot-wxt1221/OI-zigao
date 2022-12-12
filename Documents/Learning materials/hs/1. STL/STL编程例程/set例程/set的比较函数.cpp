//set的比较函数
#include <bits/stdc++.h>
using namespace std;

struct Comp
{
  bool operator() (const int &a,const int &b)//重载()操作符，照抄即可
  {
    return a>b;      //从大到小排序
    //return a < b;  //从小到大排序
  }
};//需在结构体内定义比较函数

int main()
{
  set<int,Comp> s;//set调用的比较函数为Comp
  for(int i=1; i<=10; ++i)//此处是由小到到赋值
    s.insert(i);
  set<int>::iterator ii;
  for(ii=s.begin(); ii!=s.end(); ii++)//遍历
    cout<<*ii<<' ';
  return 0;
}

