# P4247 [清华集训2012]序列操作 题解

首先这道题从各个方面都知道是线段树。

## 0x00 记号与约定

所有的运算符号如 $+$ 、 $=+$ 、 $==$ 等，与c++意义相同。 $\oplus$ 表示异或运算。

所有的下表从1开始。

$tree_{p}$ 表示第 $p$ 个线段树节点。

$tree_{p}.l$ 表示第 $p$ 个线段树节点的左边界，简记作 $l$ ；$tree_{p}.r$ 表示第 $p$ 个线段树节点的右边界，简记作 $r$ 。这个节点的区间为 $\left[l,r\right]$ 。

定义$tree_{p}.size=r-l+1$为区间大小

$tree_{p_{i}} \left(i\in\left[l,r\right]\right)$ 表示第 $p$ 个线段树节点区间第 $i$ 元素的值，简记为 $a{i}$ 。

从一个数组 $s$ 中任意选出 $j$ 个数的序列中的第 $i$ 数记作 $s_{j}^{i}$ 。所有的 $s_{j}^{i}$ 表示每一种组合。

定义 $mid=\left\lfloor\frac{(l+r)}{2}\right\rfloor$ 。

$tree_{p}.lChild$ 为其左子区间 $\left[l,mid\right]$ 。

$tree_{p}.rChild$ 为其右子区间 $\left[l,mid\right]$ 。

## 0x01 区间数据

**区间数据于查询是息息相关的。**

> 3. `Q a b c`表示询问$[a,b]$这一段区间中选择$c$个数相乘的所有方案的和$\mod 19940417$的值。

并且注意到

> $1 \leq c \leq \min(b-a+1,20)$

完全可以把每个区间的每个选 $i$ 个的答案用数组存下来记作 $tree_{p}.c_{i}$ 。

## 0x02 区间标记

**区间标记于修改是息息相关的。**

> 1. `I a b c`表示将$[a,b]$这一段区间的元素集体增加$c$；
> 2. `R a b`表示将$[a,b]$区间内所有元素变成相反数；

所以有两个标记：区间加与区间取反标记。记作 $tree_{p}.tagadd$ 和 $tree_{p}.tagrev$ ，简记为 $tagadd$ 和 $tagrev$ 。

若 $c==tagadd$ 表示区间中每个元素还要加上 $c$ 。

若 $tagrev==0$ 没有修改；若 $tagrev==1$ 则表示区间需要全部取反。

并且规定 $tagrev$ 优先级高于 $tagadd$ 。

## 0x03 标记叠加

如果区间加 $c$ ，则 $tagadd+=c$ 。

如果区间取反，则 $tagrev\oplus=1$ 。

> 时间复杂度 $O(1)$

## 0x04 区间修改

### 区间取反

考虑 $tree_{p}.c_{i}$ 的变化，可知 $tree_{p}.c_{i}*=\left(-1\right)^{i}$ 。也就是 $i$ 为奇数时直接取反。

> 时间复杂度 $O(n)$

### 区间加

若有区间元素为: $a_{1}$  、 $a_{2}$  、 $a_{3}$  、 $a_{i}$ ... $a_{size}$ 。加上 $x$ 则为 $a_{1}+x$  、 $a_{2}+x$  、 $a_{3}+x$  、 $a_{i}+x$ ... $a_{size}+x$ 。

若计算 $c_{j}$ 则原来为所有的 $a^{j}$ 序列的 $\prod_{i=1}^{j} a_{i}^{j}$ 的和。

之后则为所有的 $a^{j}+x$ 序列的 $\prod_{i=1}^{j} a_{i}^{j}+x$ 的和。

我们拿一组出来看：

$\prod_{i=1}^{j} a_{i}^{j}$ 变成了 $\prod_{i=1}^{j} a_{i}^{j}+x$

可见，这玩意展开将是一个很恐怖的多项式。~~要来力！~~但是将 $x$ 看做元，就会好一些。

常数项也就是： $\prod_{i=1}^{j} a_{i}^{j}$ 。可以忽略，将其他的项看做对答案的贡献。

一次项就是：这组 $a^{j}$ 中的所有的 $\left(a^{j}\right)^{j-1}$ 的 $\prod_{i=1}^{j-1} \left(a^{j}\right)_{i}^{j-1}\times x$ 。

二次项就是：这组 $a^{j}$ 中的所有的 $\left(a^{j}\right)^{j-2}$ 的 $\prod_{i=1}^{j-2} \left(a^{j}\right)_{i}^{j-2}\times x^{2}$ 。

三次项就是：这组 $a^{j}$ 中的所有的 $\left(a^{j}\right)^{j-3}$ 的 $\prod_{i=1}^{j-3} \left(a^{j}\right)_{i}^{j-3}\times x^{3}$ 。

等等。

贡献就是：

这组 $a^{j}$ 中的所有的 $\left(a^{j}\right)^{k}$ 的 $$\sum_{k=0}^{j-1}\prod_{i=1}^{k} \left(a^{j}\right)_{i}^{k}\times x^{j-k}$$

> 注意：此处的 $\left(a^{j}\right)^{j-k}$ 表示，从 $a$ 数组中选 $j$ 个数的一个组合中再选 ${j-k}$ 个数。

回到整体：

整体贡献就是：

所有 $a^{j}$ 中的所有的 $\left(a^{j}\right)^{k}$ 的 $$\sum_{k=0}^{j-1}\prod_{i=1}^{k} \left(a^{j}\right)_{i}^{k}\times x^{j-k}$$

也就是 $$\sum_{k=0}^{j-1}\prod_{i=1}^{k} a_{i}^{k}\times x^{j-k} \times w_{j}^{i}$$

之所以再乘上 $w_{j}^{i}$ ，是因为在不同的 $a^{j}$ 可能有相同的 $a_{i}^{k}$ ，被计算。现在需要知道 $a_{i}^{k}$ 被计算了多少次，也就是一个长度为 $k$ 的序列，会被多少个长度为 $j$ 的序列包含，也就是选了固定的 $k$ 后，还要从大区间中选 $j$ 个，一目了然了 $C_{size}^{j-k}$ 。剩下的 $\prod_{i=1}^{j-k} a_{i}^{k}$ 就是原来的 $tree_{p}.c_{k}$ 。这样倒着递推所有的 $tree_{p}.c_{k}$ 就行了！

对 $tree_{p}.c_{j}$ 于最终贡献计算公式：

$$\sum_{k=0}^{j-1}tree_{p}.c_{k}\times x^{j-k} \times C_{size}^{j-k}$$

> 预处理出 $x^{k}$ 时间复杂度 $O(20^{2})$
> 注意：此处 $C_{n}^{m}$ 表示组合数

## 0x05 区间合并

到了最后，已经很好做了。考虑 $tree_{p}.c_{i}$ 可以从哪里来，其实就是两个子区，一个选 $k$ 个，一个选 $i-k$ 个来的。

形式化一下：

$$tree_{p}.c_{i}=\sum_{k=0}^{tree_{p}.lChild.size}tree_{p}.lChild.c_{k}\times tree_{p}.rChild.c_{i-k}$$

> 时间复杂度 $O(20^{2})$

## 0x06 代码

```cpp
#include<cstdio>
#include<cstring>
const int mod=19940417;
#define _mid int mid=((l+r)>>1)
#define _lChild (p<<1)
#define _rChild ((p<<1)|1)
#define _lThings (_lChild),(l),(mid)
#define _rThings (_rChild),((mid)+1),(r)
#define _maxC min(20,tree[p].size)
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE long long

struct node{
    long long c[21],tagadd;
    int size;
    char tagrev;
    node(){
        tagadd=tagrev=size=0;
        c[0]=c[1]=c[2]=c[3]=c[4]=c[5]=c[6]=c[7]=c[8]=c[9]=c[10]=c[11]=c[12]=c[13]=c[14]=c[15]=c[16]=c[17]=c[18]=c[19]=c[20]=0;
    }
}tree[200001],temp__;

int Cnm[50010][21];

inline int max(int a,int b){
    return a>b?a:b;
}
inline int min(int a,int b){
    return a<b?a:b;
}

struct SEQ{
    long long temp[21];

    inline void updata(int p){//将两个子区间合并到大区间，更新大区间
        register int i,j;
        tree[p].c[0]=tree[p].c[1]=tree[p].c[2]=tree[p].c[3]=tree[p].c[4]=tree[p].c[5]=tree[p].c[6]=tree[p].c[7]=tree[p].c[8]=tree[p].c[9]=tree[p].c[10]=tree[p].c[11]=tree[p].c[12]=tree[p].c[13]=tree[p].c[14]=tree[p].c[15]=tree[p].c[16]=tree[p].c[17]=tree[p].c[18]=tree[p].c[19]=tree[p].c[20]=0;
        for(i=0;i<=min(20,tree[_lChild].size);++i)
            for(j=0;i+j<=20&&j<=tree[_rChild].size;++j)
                tree[p].c[i+j]=(tree[p].c[i+j]+tree[_lChild].c[i]*tree[_rChild].c[j])%mod;//左子区间取 i 个，右子区间取 j 个
        return;
    }

    void add(int p,int x){//单个区间节点加法
        if(!p||!x) return;
        register int j,k;
        temp[0]=1;
        for(j=1;j<=_maxC;++j) temp[j]=temp[j-1]*x%mod;
        for(j=_maxC;j;--j)
            for(k=0;k<j;++k)
                tree[p].c[j]=(tree[p].c[j]+tree[p].c[k]*temp[j-k]%mod*Cnm[tree[p].size-k][j-k])%mod;//按照公式执行
        tree[p].tagadd=(tree[p].tagadd+x)%mod;
        return;
    }

    void rev(int p){//单个区间节点取反
        if(!p) return;
        register int i;
        for(i=1;i<=_maxC;++i) tree[p].c[i]=((i&1)?mod-tree[p].c[i]:tree[p].c[i]);//奇数取反，偶数不变
        tree[p].tagadd=mod-tree[p].tagadd;
        tree[p].tagrev^=1;
        return;
    }

    node merge(node p,node w){//合并两个节点，与更新区间类似
        node e;
        register int i,j;
        e.size=p.size+w.size;
        for(i=0;i<=min(20,p.size);++i)
            for(j=0;i+j<=20&&j<=w.size;++j)
                e.c[i+j]=(e.c[i+j]+p.c[i]*w.c[j])%mod;//从两个区间中选出 i 个和 j 个
        return e;
    }

    void push_down(int p){//下放懒标记
        if(tree[p].tagrev){//优先级:先处理取反
            rev(_lChild);
            rev(_rChild);
            tree[p].tagrev=0;
        }
        if(tree[p].tagadd){
            add(_lChild,tree[p].tagadd);
            add(_rChild,tree[p].tagadd);
            tree[p].tagadd=0;
        }
        return;
    }

    void build(int p,int l,int r,int *a){//建立线段树
        tree[p].size=r-l+1;
        if(l==r){
            tree[p].c[0]=1;
            tree[p].c[1]=(a[l]%mod+mod)%mod;
            return;
        }
        _mid;
        build(_lThings,a);
        build(_rThings,a);
        updata(p);
        return;
    }

    void r_add(int p,int l,int r,int s,int t,int x){//区间加法
        if(s<=l&&r<=t){
            add(p,x);
            return;
        }
        push_down(p);
        _mid;
        if(s<=mid) r_add(_lThings,s,t,x);
        if(mid<t) r_add(_rThings,s,t,x);
        updata(p);
        return;
    }

    void r_rev(int p,int l,int r,int s,int t){//区间取反
        if(s<=l&&r<=t){
            rev(p);
            return;
        }
        push_down(p);
        _mid;
        if(s<=mid) r_rev(_lThings,s,t);
        if(mid<t) r_rev(_rThings,s,t);
        updata(p);
        return;
    }

    node query(int p,int l,int r,int s,int t){//区间查询
        if(s<=l&&r<=t) return tree[p];
        push_down(p);
        _mid;
        if(t<=mid) return query(_lThings,s,t);
        if(mid<s) return query(_rThings,s,t);
        else return merge(query(_lThings,s,t),query(_rThings,s,t));
    }
}seq;

int a[50010];

int n,m;

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    register int i,j,k,l,r,x;
    register char op;
    n=read();
    m=read();
    //init
    tree[0].c[0]=1;
    Cnm[0][0]=1;
    for(i=1;i<=n;++i){
        a[i]=read();
        Cnm[i][0]=1;
        for(j=1;j<=20&&j<=i;++j) Cnm[i][j]=(Cnm[i-1][j]+Cnm[i-1][j-1])%mod;//杨辉三角处理组合数
    }
    seq.build(1,1,n,a);
    for(i=1;i<=m;++i){
        loop:op=getchar();
        while(op!='I'&&op!='Q'&&op!='R')goto loop;
        l=read();
        r=read();
        if(op=='I'){
            x=read();
            x=(x%mod+mod)%mod;
            seq.r_add(1,1,n,l,r,x);
        }else if(op=='R'){
            seq.r_rev(1,1,n,l,r);
        }else{
            x=read();
            print(((seq.query(1,1,n,l,r)).c[x]%mod+mod)%mod);
            putchar('\n');
        }
    }

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
    while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x==0){
        putchar('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
    return;
}
```

终于写完了，完结撒花！！！！本文可能有点抽象，有什么不懂可以问我，我会很乐意的！