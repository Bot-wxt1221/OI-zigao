//sort�Խṹ������
#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int x,y;
} p[1001];

int Cmp(Node a,Node b)
{
  if (a.x != b.x)
    return a.x < b.x;  //���a.x������b.x���Ͱ�x��С������
  return a.y < b.y;  //���x��Ȱ�y��С������
}

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 1; i <= n; i++)
    cin>>p[i].x>>p[i].y;
  sort(p+1,p+n+1,Cmp);//���򣬱ȽϺ���ΪCmp
  for (int i = 1; i <=n; i++)
    cout<<p[i].x<<" "<<p[i].y<<endl;
  return 0;
}

