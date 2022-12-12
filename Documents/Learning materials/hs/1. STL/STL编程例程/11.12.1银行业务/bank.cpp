//银行业务
#include <bits/stdc++.h>//使用万能头文件，无需写#include <map> 
using namespace std;

multimap<int, int>G;
multimap<int ,int>::iterator it;

int main()
{
//  freopen("bank.in","r",stdin);
//  freopen("bank.ans","w",stdout);
  int Request;
  while (1)
  {
    scanf("%d", &Request);
    if (Request == 1)
    {
      int k, p;
      scanf("%d%d", &k, &p);
      G.insert(make_pair(p, k));//插入客户，multimap自动按p的值排序
    }
    if (Request == 3)
    {
      it = G.begin();
      if (it == G.end())
        printf("0\n");
      else
      {
        printf("%d\n", it -> second);//输出最低优先级客户
        G.erase(it);
      }
    }
    if (Request == 2)
    {
      it = G.end();
      if (G.begin() == it)
        printf("0\n");
      else
      {
        --it;
        printf("%d\n", it -> second);//输出最高优先级客户
        G.erase(it);
      }
    }
    if (Request == 0)
      break;
  }
  return 0;
}

