//Ư��������
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <map> 
using namespace std;

map<int,int>m;

int main()
{
  freopen("pretty.in","r",stdin);
  freopen("pretty.out","w",stdout);
  int n,i=0,p=0;
  while(1)
  {
    i++;
    if(i%3==0 || i%5==0)
    {
      ++p;
      if(p>100000)
        break;
      m[p]=i;
    }
  }
  while(cin>>n)
    cout<<m[n]<<endl;
  return 0;
}

