#include<bits/stdc++.h>
using namespace std;
int main(){
    set<string> A, B;                        //���弯��
    string s1, s2;
    int n;
    while(cin >> n && n){
        for(int i=0; i<n; i++) {
            cin >> s1 >> s2;
            A.insert(s1);  A.insert(s2);   //�����˷Ž�����A
            B.insert(s2);                     //ʧ���߷Ž�����B
        }
        if(A.size() - B.size() == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        A.clear(); B.clear();
    }
    return 0;
}
