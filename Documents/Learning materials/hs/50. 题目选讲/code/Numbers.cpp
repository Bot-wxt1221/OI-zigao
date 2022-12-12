const int MOD = 1000;

typedef vector<int> vec;
typedef vector<vec> mat;

//º∆À„ A*B
mat mul(mat &A, mat &B) {
	mat C(A.size(), vec(B[0].size()));
	for (int i = 0; i < A.size(); i++) {
		for (int k = 0; k < B.size(); k++) {
			for (int j = 0; j < B[0].size(); j++) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}
	return C;
} 

//º∆À„ A^n
mat pow(mat A, int n) {
	mat B(A.size(), vec(A.size()));
	for (int i = 0; i < A.size(); i++) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
} 

// ‰»Î 
int n;

void solve() {
	mat A(2, vec(2, 0));
	A[0][0] = 3;  A[0][1] = 5;
	A[1][0] = 1;  A[1][1] = 3;
	A = pow(A, n);
	printf("%03d\n", (A[0][0] * 2 + MOD - 1) % MOD);
}

