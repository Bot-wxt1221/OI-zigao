//最值例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

bool strComp(const char *s1,const char *s2)
{
  return strcmp(s1,s2)<0?1:0;
}

int main()
{
  cout<<min((char*)"green",(char*)"girl",strComp)<<endl;//打印girl
  cout<<min(100,30)<<endl;
  cout<<max(100,30)<<endl;
  list<int> l;
  l.push_back(13);
  l.push_back(6);
  l.push_back(9);
  l.push_back(3);
  l.push_back(20);
  l.push_back(18);
  l.push_back(1);
  cout<<*min_element(l.begin(),l.end())<<endl;//区间最小元素
  cout<<*max_element(l.begin(),l.end())<<endl;//区间最大元素
  //字典序比较大小
  char * s1="house";
  char *s2="book";
  const int len1=sizeof("house")/sizeof(char);
  const int len2=sizeof("book")/sizeof(char);
  bool f=lexicographical_compare(s1,s1+len1,s2,s2+len2);//按字典序比较两序列
  if (f)
    cout<<"house在book前"<<endl;
  else
    cout<<"house在book后"<<endl;
  return 0;
}

