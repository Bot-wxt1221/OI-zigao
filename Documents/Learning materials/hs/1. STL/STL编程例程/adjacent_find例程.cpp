//adjacent_find例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

bool Equal(int x,int y)//用于判断是否奇偶相同
{
  return (x-y)%2==0?1:0;
}

int main()
{
  list<int>l;
  l.push_back(93);
  l.push_back(5);
  l.push_back(2);
  l.push_back(2);
  l.push_back(33);
  l.push_back(52);
  l.push_back(12);
  //查找邻接相等的元素
  list<int>::iterator i=adjacent_find(l.begin(),l.end());
  if(i!=l.end())
  {
    cout<<"两个相邻的元素相等"<<*i<<' ';
    i++;
    cout<<*i<<endl;
  }
  // 找出首个两个相邻的元素奇偶性相同
  list<int>::iterator ii=adjacent_find(l.begin(),l.end(),Equal);
  if(i!=l.end())
  {
    cout<<"找出首个两个相邻的元素奇偶性相同"<<*ii<<' ';
    ii++;
    cout<<*ii<<endl;
  }
  return 0;
}

