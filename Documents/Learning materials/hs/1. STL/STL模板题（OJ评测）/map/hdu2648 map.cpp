#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, p;
    map<string, int> shop;
    while(cin>>n) {
        string s;
        for(int i=1; i<=n; i++) cin>>s; //�����̵����֡�ʵ�����ò��Ŵ���
        cin >> m;
        while(m--) {
            for(int i=1; i<=n; i++) {
                cin >> p >> s;
                shop[s] += p;               //��map����ֱ�Ӳ����̵꣬���ϼ۸�
            }
            int rank = 1;
            map<string,int>::iterator it;           //������
            for(it=shop.begin(); it != shop.end(); it++)
                if((*it).second > shop["memory"])   //�Ƚϼ۸�
						rank++;
            cout<<rank<<endl;
        }
        shop.clear();
    }
    return 0;
}
