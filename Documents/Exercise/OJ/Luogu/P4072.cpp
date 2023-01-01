#include<cstdio>
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

long long sum[3010],fl[3010],fl_1[3010];
int Q[3010];

long long B(int i){return -sum[i]*sum[i];}
long long K(int i){return sum[i]<<1;}
long long X(int j){return sum[j];}
long long Y(int j){return fl_1[j]+sum[j]*sum[j];}
long double slope(int i,int j){return ((X(i)-X(j))==0)?(1e18):(Y(i)-Y(j))/((X(i)-X(j)));}


int main(){
    register int i,l,head,tail;
    int n=read();
    long long m=read();

    for(i=1;i<=n;++i) sum[i]=read()+sum[i-1],fl_1[i]=sum[i]*sum[i];

    for(l=1;l<m;++l){
        head=tail=1;
        Q[tail]=l;
        for(i=l+1;i<=n;++i){
            while(head<tail&&slope(Q[head],Q[head+1])<(K(i)*1.0)) ++head;
            fl[i]=Y(Q[head])-K(i)*X(Q[head])-B(i);
            while(head<tail&&slope(i,Q[tail])<slope(Q[tail-1],Q[tail])) --tail;
            Q[++tail]=i;
        }
        for(i=1;i<=n;++i) fl_1[i]=fl[i];
    }

    print(-sum[n]*sum[n]+m*fl[n]);

    return 0;
}