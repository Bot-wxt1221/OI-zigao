//map例程3
#include <bits/stdc++.h>//使用万能头文件，无需写#include <map> 
using namespace std;

int main()
{
  map<int, string> ms;
  ms[1] = "student_one";
  ms[1] = "student_two";//id相同，则忽略
  ms[2] = "student_three";
  pair<map<int,string>::iterator,bool>pa;
  pa=ms.insert(pair<int, string>(2, "student_one"));
  if(!pa.second)//id相同，则插入失败
    cout<<"error"<<endl;
  ms.insert(pair<int, string>(5, "student_two"));
  ms.insert(pair<int, string>(6, "student_three"));
  map<int, string>::iterator iter;
  for(iter = ms.begin(); iter != ms.end(); iter++)
    cout<<iter->first<<" "<<iter->second<<endl;
  //搜索学号为2的记录并打印
  map<int,string>::iterator ii=ms.find(2);
  cout<<"学号为"<<(*ii).first<<' '<<(*ii).second<<endl;
  return 0;
}

