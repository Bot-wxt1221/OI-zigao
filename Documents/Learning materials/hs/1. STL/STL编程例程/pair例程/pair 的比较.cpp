//pair 的比较
#include <bits/stdc++.h>
using namespace std;

int main ()
{
  pair<int,char> A (10,'z');
  pair<int,char> B (90,'a');
  if (A==B)
    cout << "相等\n";
  if (A!=B)
    cout << "不相等\n";
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

