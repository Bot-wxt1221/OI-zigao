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