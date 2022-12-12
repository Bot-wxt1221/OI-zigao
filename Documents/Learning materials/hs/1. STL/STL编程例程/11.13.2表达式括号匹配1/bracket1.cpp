//±Ì¥Ô Ω¿®∫≈∆•≈‰1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("bracket1.in","r",stdin);
  freopen("bracket1.out","w",stdout);
  string s;
  stack <char> st;
  cin>>s;
  for(int i=0; i<s.size(); i++)
  {
    if(s[i]=='['||s[i]=='(')
      st.push(s[i]);
    if(s[i]==']')
      if(st.top()=='[')
        st.pop();
      else
        printf("Wrong\n"),exit(0);
    if(s[i]==')')
      if(st.top()=='(')
        st.pop();
      else
        printf("Wrong\n"),exit(0);
  }
  printf("%s\n",st.empty()?"OK":"Wrong");
  return 0;
}
