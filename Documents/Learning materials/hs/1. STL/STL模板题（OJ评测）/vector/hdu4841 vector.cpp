//ECUST luoyongjun
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <int> table;                          //ģ��Բ��
    int n, m;
    while(cin >> n >> m){
        table.clear();
        for(int i=0; i<2*n; i++)  table.push_back(i);  //��ʼ��
        int pos = 0;                               //��¼��ǰλ��
        for(int i=0; i<n; i++){                  //����n��
            pos = (pos+m-1) % table.size();    //Բ���Ǹ�����ȡ�ദ��
            table.erase(table.begin() + pos); //���߻��ˣ�table������1
        }
        int j = 0;
        for(int i=0; i<2*n; i++){               //��ӡԤ�Ȱ�����λ
            if(!(i%50) && i)  cout<<endl;       //50����ĸһ��
            if(j<table.size() && i==table[j]){ //table���µĶ��Ǻ���
                j++;
                cout<<"G";
            }
            else
                cout<<"B";
        }
        cout<<endl<<endl;                          //��һ������
    }
    return 0;
}
