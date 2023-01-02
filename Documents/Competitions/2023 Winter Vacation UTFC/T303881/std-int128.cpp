#include<cstdio>
#include<algorithm>
#define INPUT_DATA_TYPE __int128
#define OUTPUT_DATA_TYPE __int128
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[40];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

__int128 k1,b1,k2,b2,f_now[10010],f_last[10010],XQ[10010],YQ[10010],XP[10010],YP[10010],V[10010];
int Q[10010];

__int128 B(int i){return -V[i]-XQ[i]*XQ[i]-YQ[i]*YQ[i];}
__int128 K(int i){return XQ[i]<<1;}
__int128 X(int j){return XP[j]+k1*YP[j];}
__int128 Y(int j){return f_last[j]+XP[j]*XP[j]+YP[j]*YP[j]-(b1*YP[j]<<1);}
long double slope(int i,int j){return ((X(i)-X(j))==0)?(1e18):(Y(i)-Y(j))/((X(i)-X(j)));}


int main(){
    // freopen("C:\\Users\\Administrator\\Desktop\\OI\\compare.in","r",stdin);
    register int i,l,head,tail;
    register __int128 ans=0x3f3f3f3f3f3f3f3fll;
    int n=read();
    int m=read();
    k1=read();
    b1=read();
    k2=read();
    b2=read();

    for(i=1;i<=n;++i) XQ[i]=read(),
                      YQ[i]=k1*XQ[i]+b1,
                      XP[i]=read(),
                      YP[i]=k2*XP[i]+b2,
                      V[i]=(XP[i]-XQ[i])*(XP[i]-XQ[i])+(YP[i]-YQ[i])*(YP[i]-YQ[i]),
                      f_last[i]=V[i]+XQ[i]*XQ[i]+YQ[i]*YQ[i];

    for(l=1;l<m;++l){
        head=tail=1;
        Q[head]=l;
        for(i=l+1;i<=n;++i){
            while(head<tail&&slope(Q[head],Q[head+1])<(K(i)*1.0)) ++head;
            f_now[i]=Y(Q[head])-K(i)*X(Q[head])-B(i);
            while(head<tail&&slope(i,Q[tail-1])<slope(Q[tail-1],Q[tail])) --tail;
            Q[++tail]=i;
        }
        for(i=1;i<=n;++i) f_last[i]=f_now[i];
    }

    for(i=m;i<=n;++i) ans=std::min(ans,f_now[i]);

    print(ans);

    return 0;
}