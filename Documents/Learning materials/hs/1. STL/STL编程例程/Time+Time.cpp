//Time+Time的操作
#include <bits/stdc++.h>
using namespace std;

struct Time
{
  int H,M,S;                          //时，分，秒
  Time operator+ (const Time &b)const //重载运算符"+"
  {
    return Time {H+b.H,M+b.M,S+b.S};  //仅为演示，不考虑进位
  }
} T1= {3,2,4},T2= {5,20,30},T3;

int main()
{
  T3=T1+T2;
  cout<<T3.H<<":"<<T3.M<<":"<<T3.S<<endl;
  return 0;
}

