//Time+Time�Ĳ���
#include<bits/stdc++.h>
using namespace std;

struct Time
{
  int H,M,S;                          //ʱ���֣���
  Time operator+ (const Time &b)const //���������"+"
  {
    return Time {H+b.H,M+b.M,S+b.S};  //��Ϊ��ʾ�������ǽ�λ
  }
} T1= {3,2,4},T2= {5,20,30},T3;

int main()
{
  T3=T1+T2;
  cout<<T3.H<<":"<<T3.M<<":"<<T3.S<<endl;
  return 0;
}

