// Millionaire
// GCJ 2008 APAC local onsites C

#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXR = 1 << 15 + 2;
int N, M, X;
double P, dp[2][MAXR];

int main() {
    freopen("C-large-practice.in", "r", stdin);
    freopen("C-answer.out", "w", stdout);
    scanf("%d", &N);
    int i, k, j, l, r;
    for (k = 1; k <= N; k++) {
        scanf("%d%lf%d", &M, &P, &X);
        r = 1 << M;
        double *prv = dp[0], *nxt = dp[1];
        memset(prv, 0, sizeof(double) * (r + 1));
        prv[r] = 1.0;
        for (i = 0; i < M; i++) {
            for (j = 0; j <= r; j++) {
                int Lim = std::min(j, r - j);
                nxt[j] = 0.0;
                for (l = 0; l <= Lim; l++) nxt[j] = std::max(nxt[j], P * prv[j + l] + (1 - P) * prv[j - l]);
            }
            std::swap(prv, nxt);
        }
        i = (long long)X * r / 1000000;
        printf("Case #%d: %.6lf\n", k, prv[i]);
    }
    fclose(stdin);
    fclose(stdout);¡¡¡¡ return 0;
}
