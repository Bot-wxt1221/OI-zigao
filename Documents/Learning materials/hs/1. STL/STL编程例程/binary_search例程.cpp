//binary_search����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

int main()
{
  int a[]= {3,9,17,22,23,24};
  const int len=sizeof(a)/sizeof(int);
  if(binary_search(a,a+len,24))
    cout<<"�������24"<<endl; //����Ǵ����
  else
    cout<<"���鲻����24"<<endl;
  return 0;
}

