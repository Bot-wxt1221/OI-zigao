//pair �ıȽ�
#include<bits/stdc++.h>
using namespace std;

int main ()
{
  pair<int,char> A (10,'z');
  pair<int,char> B (90,'a');
  if (A==B)
    cout << "���\n";
  if (A!=B)
    cout << "�����\n";
  if (A< B)
    cout << "A<B\n";
  if (A>B)
    cout << "A>B\n";
  if (A<=B)
    cout << "A<=B\n";
  if (A>=B)
    cout << "A>=B\n";
  return 0;
}

