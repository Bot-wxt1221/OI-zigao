//堆排序例程
#include <bits/stdc++.h>//使用万能头文件，无需写#include <algorithm> 
using namespace std;

void show(vector<int> h)
{
  for(int i=0; i!=h.size(); i++)
    cout<<h[i]<<" ";
  cout<<endl;
}

int main()
{
  int a[9]= {0,1,2,3,4,8,9,3,5};
  vector<int> V(a,a+9);

  make_heap(V.begin(),V.end());//建堆，默认为Less,即最大元素放在第一个
  //make_heap(V.begin(),V.end(),greater<int>());//建堆,最小元素放在第一个
  show(V);

  V.push_back(7);
  push_heap(V.begin(),V.end());//新添加一个元素在末尾，然后重新调整堆序
  show(V);

  pop_heap(V.begin(),V.end());//把堆顶元素取出来放到末尾，用原来末尾元素去替代
  show(V);
  cout<<V.back()<<endl;
  V.pop_back();
  show(V);

  sort_heap(V.begin(),V.end());//从小到大排序后就不再是一个合法的heap了
  show(V);
  return 0;
}

