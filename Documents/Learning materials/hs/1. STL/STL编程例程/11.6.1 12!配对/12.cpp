//12!配对
#include <bits/stdc++.h>//使用了万能头文件，故无需写#include <set> 
using namespace std;

int main()
{
  freopen("12.in","r",stdin);
  freopen("12.out","w",stdout);
  int N,n,num=0,f12=479001600;
  multiset<unsigned int>s;//多重集合，允许值重复
  cin>>N;
  for(int i=1; i<=N; i++)
  {
    cin>>n;
    if(f12%n==0)//如果n是f12的约数
    {
      multiset<unsigned int>::iterator it=s.find(f12/n);//找n的因子
      if(it!=s.end())
      {
        ++num;
        s.erase(it);//多重集合中删除该因子
      }
      else
        s.insert(n);//插入到多重集合中
    }
  }
  printf("%d\n",num);
  return 0;
}

