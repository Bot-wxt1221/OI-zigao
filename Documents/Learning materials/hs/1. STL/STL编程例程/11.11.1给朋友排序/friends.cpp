//����������STL��ʽ
#include<bits/stdc++.h>
using namespace std;

map<string,int>freq;//�ַ���������ӳ�䣬�����յĴ����������飬�±�Ϊ�ַ���

string key(const string &s)//����ȫ����������
{
  return s.substr(0,s.find(" "));//�ҵ�һ���ո�Ȼ��ȡ��ǰ��Ĵ�
}

int cmp(const string &a,const string &b)
{
  return freq[key(a)]>freq[key(b)];
}

int main()
{
  freopen("friends.in","r",stdin);
  freopen("friends.out","w",stdout);
  vector<string> v;//�ɱ䳤���飬����������С
  string s1,s2;
  while(cin>>s1>>s2)
  {
    v.push_back(s1+" "+s2);//��push_back,pop_back��ĩβ����ɾ��Ԫ��
    ++freq[s1];
  }
  stable_sort(v.begin(),v.end(),cmp);//�ȶ����򣬿ɱ�������ǰ��˳��
  for(int i=0; i<(int)v.size(); i++)
    cout<<v[i]<<endl;
  return 0;
}

