//电话列表
#include <bits/stdc++.h>
using namespace std;
vector <string> v;
char ch[10];

int Check(int n)
{
  for (int i=0; i<n-1; i++)
    if (v[i+1].find(v[i])==0)//find返回某字串在另个字串中首次出现位置
      return 0;
  return 1;
}

int main()
{
  freopen("telephone.in","r",stdin);
  freopen("telephone.out","w",stdout);
  int n;
  scanf("%d",&n);
  while (~scanf("%d",&n))   //scanf读取数据失败返回-1，取反为0
  {
    v.clear();
    for (int i=0; i<n; i++)
    {
      scanf("%s",&ch);      //scanf比cin速度快，读入字符串不会超时
      v.push_back(string(ch));
    }
    sort(v.begin(),v.end()); //对vector从小到大排序
    printf("%s\n",Check(n)==0?"NO":"YES");
  }
  return 0;
}

