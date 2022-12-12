//sort对结构体排序
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int x,y;
} p[1001];

int Cmp(Node a,Node b)
{
  if (a.x != b.x)
    return a.x < b.x;  //如果a.x不等于b.x，就按x从小到大排
  return a.y < b.y;  //如果x相等按y从小到大排
}

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 1; i <= n; i++)
    cin>>p[i].x>>p[i].y;
  sort(p+1,p+n+1,Cmp);//排序，比较函数为Cmp
  for (int i = 1; i <=n; i++)
    cout<<p[i].x<<" "<<p[i].y<<endl;
  return 0;
}

