//统计单词数
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("CountWord.in","r",stdin);
  freopen("CountWord.out","w",stdout);
  set<string>word;
  string s="";
  char c;
  while(scanf("%c",&c) && c!='#')
  {
    if(c==' ')
    {
      if(s.length())//当字符串不为空
        word.insert(s);//添加单词
      s.clear();//或者 s=""
    }
    else if(c=='\n' || c=='\r')//读到行末
    {
      if(s.length())
        word.insert(s);
      printf("%d\n",word.size());//计算完毕，输出结果
      word.clear();//清空set
      s.clear();//或者 s=""
    }
    else
      s+=c;//不是空格或行末就累加到字符串s
  }
  return 0;
}

