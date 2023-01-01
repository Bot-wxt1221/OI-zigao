#include<cstdio>
#include<cstring>
using namespace std;
long long n,a[3],mul[3][3],res[3][3],tmp[3][3],tp[3];
void mul_1()
{
    memset(tmp,0,sizeof(tmp));
    for(register int i=1;i<=2;i+=1)
        for(register int j=1;j<=2;j+=1)
            for(register int k=1;k<=2;k+=1)
                tmp[i][j]=(tmp[i][j]+res[i][k]*mul[k][j])%1000000007;
    for(register int i=1;i<=2;i+=1)
        for(register int j=1;j<=2;j+=1)
            res[i][j]=tmp[i][j];
}
void mul_2()
{
    memset(tmp,0,sizeof(tmp));
    for(register int i=1;i<=2;i+=1)
        for(register int j=1;j<=2;j+=1)
            for(register int k=1;k<=2;k+=1)
                tmp[i][j]=(tmp[i][j]+mul[i][k]*mul[k][j])%1000000007;
    for(register int i=1;i<=2;i+=1)
        for(register int j=1;j<=2;j+=1)
            mul[i][j]=tmp[i][j];
}
void solve()
{
    for(register int i=1;i<=2;i+=1)
        for(register int j=1;j<=2;j+=1)
            tp[i]=(tp[i]+res[i][j]*a[j])%1000000007;
    printf("%lld\n",tp[1]);
}
int main()
{
    scanf("%lld",&n);
    if(n<=2)printf("1\n");
    else
    {
        a[1]=a[2]=1;
        for(register int i=1;i<=2;i+=1)
            res[i][i]=1;
        for(register int i=1;i<=2;i+=1)
            for(register int j=1;j<=2;j+=1)
                mul[i][j]=1;
        mul[2][2]=0;
        n-=2;
        while(n)
        {
            if(n&1)mul_1();
            n>>=1;
            mul_2();
        }
        solve();
    }
    return 0;
}