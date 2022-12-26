//includes����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <algorithm> 
using namespace std;

int main()
{
  int a[]= {3,9,17,22,23,24};
  int b[]= {9,22,24,3};
  int lena=sizeof(a)/sizeof(int);
  int lenb=sizeof(b)/sizeof(int);
  if(includes(a,a+lena,b,b+lenb))
    cout<<"B��A���Ӽ���"<<endl;
  else
    cout<<"B����A���Ӽ���"<<endl;
  return 0;
}

