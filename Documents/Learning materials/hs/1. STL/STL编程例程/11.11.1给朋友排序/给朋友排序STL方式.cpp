//给朋友排序STL方式
#include <bits/stdc++.h>
using namespace std;

map<string,int>freq;//字符串到整数映射，保存姓的次数，如数组，下标为字符串

string Key(const string &s)//输入全名，返回姓
{
  return s.substr(0,s.find(" "));//找第一个空格，然后取它前面的串
}

int Cmp(const string &a,const string &b)
{
  return freq[Key(a)]>freq[Key(b)];
}

int main()
{
  freopen("friends.in","r",stdin);
  freopen("friends.out","w",stdout);
  vector<string> v;//可变长数组，无须声明大小
  string s1,s2;
  while(cin>>s1>>s2)
  {
    v.push_back(s1+" "+s2);//用push_back,pop_back往末尾添加删除元素
    ++freq[s1];
  }
  stable_sort(v.begin(),v.end(),Cmp);//稳定排序，可保持排序前的顺序
  for(int i=0; i<(int)v.size(); i++)
    cout<<v[i]<<endl;
  return 0;
}

