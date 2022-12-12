/*
如果我们考虑将数组看成一条[1, n]的线段, 而每项操作也看成是从[ i[k], j[k] ]的线段, 那么题意就是按照线段的输入顺序, 
将线段[1, n]从左到右依次覆盖, 问题变成求最小的覆盖线段总数.

算法思想: 

        考虑最基本的规划方法, 用Opt[k] 表示覆盖掉[1, k]的线段最少需要的步数, 那么状态转移方程为:

                           Opt[k] = min { Opt[d] + 1    |     j[p] = k && d >= i[p] && d <= j[p] && k > 1 }

         其中i[p], j[p]分别表示线段p的左端点和右端点; 预处理: Opt[1] = 0 .

最后的答案就是Opt[n], 但是考虑时间复杂度是O(m^2), m 最大为500000, 超时无疑.但是这里我们看到了规划的决策集合是一条连续的线段, 
是要在这条线段上面取得最小值, 那么线段树的结构就正好适用.

由于这里最小的单位是一个点, 所以我们采取线段树的第一种变化: 把元线段设置为单位点, 即[k, k], 在规划的时候维护线段树即可.

另外, 线段树结点结构中, 需要加入元素 xmin, 代表最少需要用到的覆盖线段数目可以覆盖到当前结点所代表的线段.

p.s. : 如果题目不要求按照顺序选择线段从左到有覆盖的话，可以对线段进行排序，然后贪心即可.
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int MAXN = 50005;
const int MAXM = 500005;
const int inf = 0x2f7f7f7f;
 
int a[MAXN<<2];
 
void build(int l, int r, int rt) {
    a[rt] = inf;
    if (l == r) return ;
    int m = (l + r) >> 1;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
}
void update(int R, int val, int l, int r, int rt) {
    if (a[rt] > val) a[rt] = val;
    if (l != r) {
        int m = (l + r) >> 1;
        if (R <= m) update(R, val, l, m, rt<<1);
        else update(R, val, m+1, r, rt<<1|1);
    }
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R)
        return a[rt];
    int m = (l + r) >> 1;
    if (R <= m) return query(L, R, l, m, rt<<1);
    else if (L > m) return query(L, R, m+1, r, rt<<1|1);
    else {
        int ret1 = query(L, R, l, m, rt<<1);
        int ret2 = query(L, R, m+1, r, rt<<1|1);
        return (ret1 > ret2) ? ret2 : ret1;
    }
}
 
int main() {
    int n, m, a, b;
    while (scanf("%d %d", &n, &m) == 2) {
        build(1, n, 1);
        update(1, 0, 1, n, 1);
        for (int i=0; i<m; i++) {
            scanf("%d %d", &a, &b);
            if (a < b) {
                int x = query(a, b-1, 1, n, 1);
                update(b, x+1, 1, n, 1);
            }
        }
        printf("%d\n", query(n, n, 1, n, 1));
 
    }
    return 0;
}

