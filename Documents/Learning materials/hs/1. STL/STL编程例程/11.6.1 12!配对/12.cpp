//12!���
#include<bits/stdc++.h>//ʹ��������#include���д#include <set> 
using namespace std;

int main()
{
  freopen("12.in","r",stdin);
  freopen("12.out","w",stdout);
  int N,n,num=0,f12=479001600;
  multiset<unsigned int>s;//���ؼ��ϣ�����ֵ�ظ�
  cin>>N;
  for(int i=1; i<=N; i++)
  {
    cin>>n;
    if(f12%n==0)//���n��f12��Լ��
    {
      multiset<unsigned int>::iterator it=s.find(f12/n);//��n������
      if(it!=s.end())
      {
        ++num;
        s.erase(it);//���ؼ�����ɾ��������
      }
      else
        s.insert(n);//���뵽���ؼ�����
    }
  }
  printf("%d\n",num);
  return 0;
}

