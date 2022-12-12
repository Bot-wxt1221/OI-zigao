//普通平衡树
#include <bits/stdc++.h>
using namespace std;

inline int Read()         //关键字inline把函数指定为运行速度更快的内联函数
{
  int x=0,f=1;
  char ch=getchar();      //使用getchar比scanf大约快十倍
  for(; ch<'0' || ch>'9'; ch=getchar())
    if(ch=='-')
      f=-1;
  for(; ch>='0' && ch<='9'; ch=getchar())
    x=(x<<3)+(x<<1)+ch-'0';//(x<<3)+(x<<1)相当于x*10
  return x*f;
}

int main()
{
  freopen("BalanceTree.in","r",stdin);
  freopen("BalanceTree.out","w",stdout);
  int n=Read();            //Read()用于快速读取整数
  vector<int> vec;
  vec.reserve(200000);     //预留空间
  int f,x;
  for(int i=1; i<=n; i++)
  {
    f=Read(),x=Read();
    switch(f)
    {
        //upper_bound找出有序数列中首个大于某值的元素
      case 1:
        vec.insert(upper_bound(vec.begin(),vec.end(),x),x);
        break;
        //lower_bound用于找出有序数列中首个大于等于某值的元素
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

