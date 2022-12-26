//multimap����
#include<bits/stdc++.h>//ʹ������ͷ#includeд#include <map> 
using namespace std;

int main()
{
  multimap <string, double> mp;//����map���󣬵�ǰû���κ�Ԫ��
  mp.insert(pair<string, double>("Jack", 300.5));//����Ԫ��
  mp.insert(pair<string, double>("Kity", 200));
  mp.insert(pair<string, double>("Memi", 500));
  mp.insert(pair<string, double>("Jack", 306));//�ظ������ֵ"Jack"

  multimap <string, double>:: iterator it;
  mp.erase("Jack");//ɾ����ֵ����"Jack"��Ԫ��
  for(it=mp.begin(); it != mp.end(); it++)//ǰ��������������multimap
    cout << (*it).first << " " << (*it).second << endl;

  it = mp.find("Nacy");//Ԫ�صĲ���
  if(it != mp.end())    //�ҵ�
    cout << (*it).first << " " << (*it).second << endl;
  else    //û�ҵ�
    cout << "Not find it!" << endl;
  return 0;
}

