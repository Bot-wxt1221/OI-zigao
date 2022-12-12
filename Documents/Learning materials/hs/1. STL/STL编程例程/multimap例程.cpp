//multimap例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <map> 
using namespace std;

int main()
{
  multimap <string, double> mp;//定义map对象，当前没有任何元素
  mp.insert(pair<string, double>("Jack", 300.5));//插入元素
  mp.insert(pair<string, double>("Kity", 200));
  mp.insert(pair<string, double>("Memi", 500));
  mp.insert(pair<string, double>("Jack", 306));//重复插入键值"Jack"

  multimap <string, double>:: iterator it;
  mp.erase("Jack");//删除键值等于"Jack"的元素
  for(it=mp.begin(); it != mp.end(); it++)//前向迭代器中序遍历multimap
    cout << (*it).first << " " << (*it).second << endl;

  it = mp.find("Nacy");//元素的查找
  if(it != mp.end())    //找到
    cout << (*it).first << " " << (*it).second << endl;
  else    //没找到
    cout << "Not find it!" << endl;
  return 0;
}

