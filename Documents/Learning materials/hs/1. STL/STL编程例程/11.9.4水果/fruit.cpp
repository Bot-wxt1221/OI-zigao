//ˮ��
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <map> 
using namespace std;

int main()
{
  freopen("fruit.in","r",stdin);
  freopen("fruit.out","w",stdout);
  int T,n,count;
  cin>>T;
  while (T--)
  {
    cin>>n;
    char name[100],place[100];
    map<string,map<string,int> > list;//ע��">"֮��Ҫ�ո�
    while(n--)
    {
      cin>>name>>place>>count;
      list[place][name]+=count;//������������࣬������
    }
    map<string,map<string,int> >::iterator it;
    map<string,int>::iterator it1;
    for(it=list.begin(); it!=list.end(); it++)
    {
      cout<<it->first<<endl;
      for (it1=(it->second).begin(); it1!=(it->second).end(); it1++)
      {
        cout<<"   |----";
        cout<<it1->first<<'('<<it1->second<<')'<<endl;
      }
    }
    list.clear();
    if(T!=0)
      cout<<endl;
  }
  return 0;
}

