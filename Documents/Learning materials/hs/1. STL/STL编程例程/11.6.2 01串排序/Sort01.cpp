//01串排序
#include <bits/stdc++.h>
using namespace std;

struct Comp
{
  bool operator()(const string &s1,const string &s2)const
  {
    if(s1.length()!=s2.length())//先按长度排序
      return s1.length()<s2.length();
    int c1=count(s1.begin(),s1.end(),'1');
    int c2=count(s2.begin(),s2.end(),'1');
    return c1!=c2?c1<c2:s1<s2;//按1的个数排序，若相同按ASCII码排序
  }
};

int main()
{
  freopen("Sort01.in","r",stdin);
  freopen("Sort01.out","w",stdout);
  multiset<string,Comp>ms;
  int n;
  cin>>n;
  string s;
  for(int i=1; i<=n; i++)
  {
    cin>>s;
    ms.insert(s) ;
  }
  for(multiset<string,Comp>::iterator it=ms.begin(); it!=ms.end(); it++)
    cout<<*it<<endl;
  return 0;
}

