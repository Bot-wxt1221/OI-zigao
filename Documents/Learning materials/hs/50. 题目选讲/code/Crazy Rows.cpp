//����
int N;
int M[MAX_N][MAX_N];  //����

int  a[MAX_N]; //a[i]��ʾ�� i �������ֵ� 1 ��λ��

void solve(){
	int res = 0;
	for (int i = 0; i < N; i++){
		a[i] = -1;  //����� i �в��� 1 �Ļ����͵��� -1��
		for (int j = 0; j < N; j++){
			if (M[i][j] == 1) a[i] = j;
		} 		 
	}
	for (int i = 0; i < N; i++){
		int pos = -1;   //Ҫ�ƶ����� i �е��� 
		for (int j = i; j < N; j++){
			if(a[j] <= i){
				pos = j;
				break;
			}
		} 
		
		//��ɽ���
		for (int j = pos; j > i; j--){
			swap(a[j],a[j-1]);
			res++;
		} 
	}
	printf("%d\n",res);
} 
 
