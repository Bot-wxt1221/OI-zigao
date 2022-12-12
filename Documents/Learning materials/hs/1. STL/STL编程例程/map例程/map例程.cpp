//map例程2
#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int, string> ms;
  ms[1] = "student_one";
  ms[1] = "student_two";        //id相同，则覆盖
  ms[2] = "student_three";
  map<int, string>::iterator iter;
  ms.insert(make_pair(3,"student_four"));//插入新元素
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  cout<<endl;
  iter=ms.lower_bound(1);       //首个大于等于1的元素
  cout<<iter->second<<endl;
  iter=ms.upper_bound(1);       //首个大于1的元素
  cout<<iter->second<<endl;
  iter = ms.find(1);            //查找键值为1的元素位置
  ms.erase(iter);               //删除键值为1的元素
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  ms.erase(ms.begin(),ms.end());//删除全部元素
  cout<<ms.size()<<endl;
  cout<<ms.empty()<<endl;       //empty()判断map是否为空
  return 0;
}

