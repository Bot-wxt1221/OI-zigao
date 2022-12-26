//ͳ�Ƶ�����
#include<bits/stdc++.h>
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
      if(s.length())//���ַ�����Ϊ��
        word.insert(s);//���ӵ���
      s.clear();//���� s=""
    }
    else if(c=='\n' || c=='\r')//������ĩ
    {
      if(s.length())
        word.insert(s);
      printf("%d\n",word.size());//������ϣ�������
      word.clear();//���set
      s.clear();//���� s=""
    }
    else
      s+=c;//���ǿո����ĩ���ۼӵ��ַ���s
  }
  return 0;
}

