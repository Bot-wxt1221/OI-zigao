//������
#include<bits/stdc++.h>
using namespace std;
int s[10000],n,i;
int f=0;

int main()
{
  freopen("Happy.in","r",stdin);
  freopen("Happy.out","w",stdout);
  scanf("%d",&n);
  for(i=0; i<n; i++)
    scanf("%d", &s[i]);
  for(i=0; i<n; ++i)
    s[i]=fabs(s[i]-s[i+1]);//�滻Ϊ�����������Ĳ�
  sort(s,s+n);//����
  for(i=1; i<n; i++)
    if(s[i-1]!=i)
    {
      f=1;
      break;
    }
  f?printf("NO\n"):printf("YES\n");
  return 0;
}
