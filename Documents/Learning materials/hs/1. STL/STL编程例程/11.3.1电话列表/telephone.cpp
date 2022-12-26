//�绰�б�
#include<bits/stdc++.h>
using namespace std;
vector <string> v;
char ch[10];

int Check(int n)
{
  for (int i=0; i<n-1; i++)
    if (v[i+1].find(v[i])==0)//find����ĳ�ִ��������ִ����״γ���λ��
      return 0;
  return 1;
}

int main()
{
  freopen("telephone.in","r",stdin);
  freopen("telephone.out","w",stdout);
  int n;
  scanf("%d",&n);
  while (~scanf("%d",&n))   //scanf��ȡ����ʧ�ܷ���-1��ȡ��Ϊ0
  {
    v.clear();
    for (int i=0; i<n; i++)
    {
      scanf("%s",&ch);      //scanf��cin�ٶȿ죬�����ַ������ᳬʱ
      v.push_back(string(ch));
    }
    sort(v.begin(),v.end()); //��vector��С��������
    printf("%s\n",Check(n)==0?"NO":"YES");
  }
  return 0;
}

