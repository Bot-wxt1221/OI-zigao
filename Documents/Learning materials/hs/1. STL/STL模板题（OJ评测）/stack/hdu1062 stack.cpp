#include<bits/stdc++.h>
using namespace std;
int main(){
		int n;
		char ch;
		scanf("%d",&n);  getchar();
		while(n--){
			stack<char> s;
			while(true){
				ch = getchar();                   //һ�ζ���һ���ַ�
            	if(ch==' '||ch=='\n'||ch==EOF){
					while(!s.empty()){
						printf("%c",s.top());  //���ջ��
						s.pop();                  //���ջ��
					}
					if(ch=='\n'||ch==EOF)  break;
					printf(" ");
				}
				else   s.push(ch);                //��ջ
			}
			printf("\n");
		}
	return 0;
}
