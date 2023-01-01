#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE __int128
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[400];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}
__int128 a[1000010],b[1000010];
int main(){
    register int i;
     __int128 t1=0,t2=0,n;
    n=read();

    for(i=0;i<n;++i) a[i]=read();
    for(i=0;i<n;++i) b[i]=read();

    for(i=0;i<n-1;++i){
        t1+=a[i],t2+=a[i]*a[i];
    }

    if(a[i]>b[i])t1+=a[i],t2+=a[i]*a[i];
    else t1+=b[i],t2+=b[i]*b[i];

    print(-t1*t1+n*t2);

    return 0;
}