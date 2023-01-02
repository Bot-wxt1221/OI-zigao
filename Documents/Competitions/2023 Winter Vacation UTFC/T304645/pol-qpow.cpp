#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod (998244353ll)
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int q;

struct POL{
    long long items[5100];
    int n;
    POL operator * (const POL another) const{
        register int i,j;
        POL ans;
        ans.n=std::min(n+another.n,q);
        memset(ans.items,0,sizeof(ans.items));
        for(i=0;i<=n;++i)
            for(j=0;j<=std::min(another.n,q-i);++j)
                ans.items[i+j]=(ans.items[i+j]+items[i]*another.items[j]%mod)%mod;
        return ans;
    }

    friend POL operator ^ (POL base,long long exponential){
        POL ans;
        memset(ans.items,0,sizeof(ans.items));
        ans.n=std::min((long long)q,base.n*exponential);
        ans.items[0]=1;

        while(exponential){
            if(exponential&1) ans=ans*base;
            base=base*base;
            exponential>>=1;
        }

        return ans;
    }
}pol;

int main(){
    // freopen("C:\\Users\\Administrator\\Desktop\\OI\\recording10.in","r",stdin);
    register int i;
    int n=read();
    long long m=read();
    q=n-1;
    pol.n=q;

    for(i=0;i<n;++i) ++pol.items[i]=read();

    pol.items[0]=1;

    pol=pol^m;

    for(i=0;i<=q;++i){
        print(pol.items[i]);
        putchar(' ');
    }

    return 0;
}