//��ͨƽ����
#include<bits/stdc++.h>
using namespace std;

inline int Read()         //�ؼ���inline�Ѻ���ָ��Ϊ�����ٶȸ������������
{
  int x=0,f=1;
  char ch=getchar();      //ʹ��getchar��scanf��Լ��ʮ��
  for(; ch<'0' || ch>'9'; ch=getchar())
    if(ch=='-')
      f=-1;
  for(; ch>='0' && ch<='9'; ch=getchar())
    x=(x<<3)+(x<<1)+ch-'0';//(x<<3)+(x<<1)�൱��x*10
  return x*f;
}

int main()
{
  freopen("BalanceTree.in","r",stdin);
  freopen("BalanceTree.out","w",stdout);
  int n=Read();            //Read()���ڿ��ٶ�ȡ����
  vector<int> vec;
  vec.reserve(200000);     //Ԥ���ռ�
  int f,x;
  for(int i=1; i<=n; i++)
  {
    f=Read(),x=Read();
    switch(f)
    {
        //upper_bound�ҳ������������׸�����ĳֵ��Ԫ��
      case 1:
        vec.insert(upper_bound(vec.begin(),vec.end(),x),x);
        break;
        //lower_bound�����ҳ������������׸����ڵ���ĳֵ��Ԫ��
      case 2:
        vec.erase(lower_bound(vec.begin(),vec.end(),x));
        break;
      case 3:
        cout<<lower_bound(vec.begin(),vec.end(),x)-vec.begin()+1<<endl;
        break;
      case 4:
        cout<<vec[x-1]<<endl;
        break;
      case 5:
        cout<<*--lower_bound(vec.begin(),vec.end(),x)<<endl;
        break;
      case 6:
        cout<<*upper_bound(vec.begin(),vec.end(),x)<<endl;
        break;
    }
  }
  return 0;
}

