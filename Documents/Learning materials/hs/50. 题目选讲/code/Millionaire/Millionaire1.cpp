//这里由于第i+1只和第i阶段有关联，因此直接使用一维数组保存中间结果
int M,X;
double P;
double dp[2][(1 << MAX_N) + 1];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n = 1 << M;
    double *pre = dp[0],*nxt = dp[1];
    memset(pre,0,sizeof(double) * (n + 1));
    pre[n] = 1.0;
    for(int r = 0;r < M;r++)
    {
        for(int i = 0;i <= n;i++)
        {
            int jub = min(i,n - i);
            double t = 0.0;
            for(int j = 0;j <= jub;j++)
                t = max(t,pre[i + j] * P + pre[i - j] * (1 - P));
            nxt[i] = t;
        }
        swap(pre,nxt);
    }
    int i = (LL)X * n / 1000000;
    printf("%.6f\n",pre[i]);
    return 0;

}
