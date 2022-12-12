#include <cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
#define MAXN (int(1e6+10))
// #define MAXN (int(1e2+10))
#define MAXM MAXN
#define MAXQ MAXN
#define MAXSUMC (int(1e6+10))
#define MOD 998244353

#define SEQ_TYPE long long
const int SEQ_SIZE=MAXN;
struct NODE{
    SEQ_TYPE add,mul;
    SEQ_TYPE data;
    NODE(){
        add=0;
        mul=1;
        return;
    }
};

struct SEQ{
    NODE tree[SEQ_SIZE<<2];
    void build(int l,int r,int p,SEQ_TYPE *data){
        if(l==r){
            tree[p].data=data[l]%MOD;
            return;
        }
        int mid=l+((r-l)>>1);
        build(l,mid,p<<1,data);
        build(mid+1,r,(p<<1)+1,data);
        tree[p].data=(tree[p<<1].data+tree[(p<<1)+1].data);
        return;
    }

    SEQ_TYPE getsum(int &l,int &r,int s,int t,int p){
        if(l<=s&&t<=r) return tree[p].data%MOD;
        int mid=s+((t-s)>>1);
        SEQ_TYPE sum=0;
        tree[p<<1].data=(tree[p].mul*tree[p<<1].data+tree[p].add*(mid-s+1))%MOD;
        tree[(p<<1)+1].data=(tree[p].mul*tree[(p<<1)+1].data+tree[p].add*(t-mid))%MOD;
        tree[p<<1].mul=(tree[p].mul*tree[p<<1].mul)%MOD;
        tree[(p<<1)+1].mul=(tree[p].mul*tree[(p<<1)+1].mul)%MOD;
        tree[p<<1].add=(tree[p].mul*tree[p<<1].add+tree[p].add)%MOD;
        tree[(p<<1)+1].add=(tree[p].mul*tree[(p<<1)+1].add+tree[p].add)%MOD;
        tree[p].add=0;
        tree[p].mul=1;
        if(l<=mid) sum=getsum(l,r,s,mid,p<<1);
        if(r>mid) sum=(sum+getsum(l,r,mid+1,t,(p<<1)+1))%MOD;
        return sum;
    }

    void updatemul(int l,int r,int s,int t,int &c,int p){
        if(l<=s&&t<=r){
            tree[p].data=(tree[p].data*c)%MOD;
            tree[p].mul=(tree[p].mul*c)%MOD;
            tree[p].add=(tree[p].add*c)%MOD;
            return;
        }
        int mid=s+((t-s)>>1),sum=0;
        tree[p<<1].data=(tree[p].mul*tree[p<<1].data+tree[p].add*(mid-s+1))%MOD;
        tree[(p<<1)+1].data=(tree[p].mul*tree[(p<<1)+1].data+tree[p].add*(t-mid))%MOD;
        tree[p<<1].mul=(tree[p].mul*tree[p<<1].mul)%MOD;
        tree[(p<<1)+1].mul=(tree[p].mul*tree[(p<<1)+1].mul)%MOD;
        tree[p<<1].add=(tree[p].mul*tree[p<<1].add+tree[p].add)%MOD;
        tree[(p<<1)+1].add=(tree[p].mul*tree[(p<<1)+1].add+tree[p].add)%MOD;
        tree[p].add=0;
        tree[p].mul=1;
        if(l<=mid) updatemul(l,r,s,mid,c,p<<1);
        if(r>mid) updatemul(l,r,mid+1,t,c,(p<<1)+1);
        tree[p].data=(tree[p<<1].data+tree[(p<<1)+1].data)%MOD;
        return;
    }

    void updateadd(int &l,int &r,int s,int t,int &c,int p){
        if(l<=s&&t<=r){
            tree[p].add=(tree[p].add+c)%MOD;
            tree[p].data=(tree[p].data+c*(t-s+1))%MOD;
            return;
        }
        int mid=s+((t-s)>>1),sum=0;
        tree[p<<1].data=(tree[p].mul*tree[p<<1].data+tree[p].add*(mid-s+1))%MOD;
        tree[(p<<1)+1].data=(tree[p].mul*tree[(p<<1)+1].data+tree[p].add*(t-mid))%MOD;
        tree[p<<1].mul=(tree[p].mul*tree[p<<1].mul)%MOD;
        tree[(p<<1)+1].mul=(tree[p].mul*tree[(p<<1)+1].mul)%MOD;
        tree[p<<1].add=(tree[p].mul*tree[p<<1].add+tree[p].add)%MOD;
        tree[(p<<1)+1].add=(tree[p].mul*tree[(p<<1)+1].add+tree[p].add)%MOD;
        tree[p].add=0;
        tree[p].mul=1;
        if(l<=mid) updateadd(l,r,s,mid,c,p<<1);
        if(r>mid) updateadd(l,r,mid+1,t,c,(p<<1)+1);
        tree[p].data=(tree[p<<1].data+tree[(p<<1)+1].data)%MOD;
        return;
    }

    void print(int p,int s,int t){
        if(s==t){
            printf("%d ",tree[p].data);
            return;
        }
        int mid=s+((t-s)>>1),sum=0;
        tree[p<<1].data=(tree[p].mul*tree[p<<1].data+tree[p].add*(mid-s+1))%MOD;
        tree[(p<<1)+1].data=(tree[p].mul*tree[(p<<1)+1].data+tree[p].add*(t-mid))%MOD;
        tree[p<<1].mul=(tree[p].mul*tree[p<<1].mul)%MOD;
        tree[(p<<1)+1].mul=(tree[p].mul*tree[(p<<1)+1].mul)%MOD;
        tree[p<<1].add=(tree[p].mul*tree[p<<1].add+tree[p].add)%MOD;
        tree[(p<<1)+1].add=(tree[p].mul*tree[(p<<1)+1].add+tree[p].add)%MOD;
        tree[p].add=0;
        tree[p].mul=1;
        print(p<<1,s,mid);
        print((p<<1)+1,mid+1,t);
    }
}seq;

struct FNODE{
    int T,P,V,l,r;
    FNODE(){
        T=0;
    }
}f[MAXM];

long long a[MAXN];
int f2f[MAXSUMC],n;

INPUT_DATA_TYPE read();
void print(int x);
void f3(int pos){
    for(register int i=f[pos].l;i<f[pos].r;++i){
        if(f[f2f[i]].T==1){
            seq.updateadd(f[f2f[i]].P,f[f2f[i]].P,1,n,f[f2f[i]].V,1);
        }else if(f[f2f[i]].T==2){
            seq.updatemul(1,n,1,n,f[f2f[i]].V,1);
        }else{
            f3(f2f[i]);
        }
    }
    return;
}

int main(){
    // freopen("call3.in","r",stdin);
    // freopen("call3.out","w",stdout);
    register int tot=0;
    register const int mod=998244353;
    n=read();
    for(register int i=1;i<=n;++i) a[i]=read();
    seq.build(1,n,1,a);
    int m=read();
    for(register int i=1;i<=m;++i){
        f[i].T=read();
        if(f[i].T==1){
            f[i].P=read();
            f[i].V=read();
        }else if(f[i].T==2){
            f[i].V=read();
        }else{
            f[i].l=tot;
            tot+=read();
            f[i].r=tot;
            for(register int j=f[i].l;j<f[i].r;++j)
                f2f[j]=read();
        }
    }

    int Q=read();
    for(register int i=1;i<=Q;++i){
        tot=read();
        if(f[tot].T==1){
            seq.updateadd(f[tot].P,f[tot].P,1,n,f[tot].V,1);
        }else if(f[tot].T==2){
            seq.updatemul(1,n,1,n,f[tot].V,1);
        }else{
            f3(tot);
        }
    }

    seq.print(1,1,n);

    // for(register int i=1;i<=n;++i){
    //     // print(seq.getsum(i,i,1,n,1));
    //     // putchar(' ');
    //     printf("%d ",seq.getsum(i,i,1,n,1));
    // }

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    char s[20];
    register int i=0;
    if(x<0){
        x=-x;
        putchar('-');
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar(s[--i]+'0');
    }
}