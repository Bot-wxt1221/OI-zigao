#include<cstdio>
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

#include<cstdio>
#include<cstring>
#define MATRIX_MOD %(100000921ll)
#define MATRIX_DATA_TYPE long long
const int MATRIX_MAX_N=5;const int MATRIX_MAX_M=5;struct MATRIX{int n,m;MATRIX_DATA_TYPE matrix[MATRIX_MAX_N][MATRIX_MAX_M];void operator=(const MATRIX&a){n=a.n;m=a.m;for(register int i=0;i<n;++i)for(register int j=0;j<m;++j)matrix[i][j]=a.matrix[i][j];}MATRIX operator+(const MATRIX&a)const{MATRIX ans;ans.n=n;ans.m=m;for(register int i=0;i<n;++i)for(register int j=0;j<m;++j)ans.matrix[i][j]=(matrix[i][j]+a.matrix[i][j])MATRIX_MOD;return ans;}MATRIX operator*(const MATRIX&a)const{MATRIX ans;ans.n=n;ans.m=a.m;memset(ans.matrix,0,sizeof(ans.matrix));for(register int i=0;i<n;++i)for(register int k=0;k<m;++k)for(register int j=0;j<a.m;++j)ans.matrix[i][j]=(ans.matrix[i][j]+matrix[i][k]*a.matrix[k][j]MATRIX_MOD)MATRIX_MOD;return ans;}friend MATRIX operator^(MATRIX base,MATRIX_DATA_TYPE exponential){MATRIX ans;ans.n=base.n;ans.m=base.n;memset(ans.matrix,0,sizeof(ans.matrix));for(register int i=0;i<base.n;++i)ans.matrix[i][i]=1;while(exponential){if(exponential&1)ans=ans*base;base=base*base;exponential>>=1;}return ans;}void clear(){memset(this,0,sizeof(MATRIX));return;}void print(){for(register int i=0;i<n;++i){for(register int j=0;j<n;++j)printf("%d ",matrix[i][j]MATRIX_MOD);putchar('\n');}return;}};

int main(){
    long long n=read();
    long long a=read();
    long long b=read();
    long long c=read();

    

    return 0;
}