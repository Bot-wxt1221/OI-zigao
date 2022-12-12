#include <cstdio>
#include <cstring>
#define _max(a,b) ((a)>(b)?(a):(b))
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

char s[100010];
int cnt[10][100010];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    register int T=read(),len,i,j,temp,temp2;
    register long long ans;

    while(T--){
        ans=0;
        len=read();
        gets(s);
        for(i=0;i<len;++i)
            cnt[0][i+1]=cnt[0][i],
            cnt[1][i+1]=cnt[1][i],
            cnt[2][i+1]=cnt[2][i],
            cnt[3][i+1]=cnt[3][i],
            cnt[4][i+1]=cnt[4][i],
            cnt[5][i+1]=cnt[5][i],
            cnt[6][i+1]=cnt[6][i],
            cnt[7][i+1]=cnt[7][i],
            cnt[8][i+1]=cnt[8][i],
            cnt[9][i+1]=cnt[9][i],
            ++cnt[s[i]-'0'][i+1];

        ans=0;
        for(i=1;i<=len;++i)
            for(j=i;j<=len;++j){
                temp=0;
                temp=_max(cnt[0][j]-cnt[0][i-1],temp);
                temp=_max(cnt[1][j]-cnt[1][i-1],temp);
                temp=_max(cnt[2][j]-cnt[2][i-1],temp);
                temp=_max(cnt[3][j]-cnt[3][i-1],temp);
                temp=_max(cnt[4][j]-cnt[4][i-1],temp);
                temp=_max(cnt[5][j]-cnt[5][i-1],temp);
                temp=_max(cnt[6][j]-cnt[6][i-1],temp);
                temp=_max(cnt[7][j]-cnt[7][i-1],temp);
                temp=_max(cnt[8][j]-cnt[8][i-1],temp);
                temp=_max(cnt[9][j]-cnt[9][i-1],temp);
                temp2=(cnt[0][j]-cnt[0][i-1]>0)+
                (cnt[1][j]-cnt[1][i-1]>0)+
                (cnt[2][j]-cnt[2][i-1]>0)+
                (cnt[3][j]-cnt[3][i-1]>0)+
                (cnt[4][j]-cnt[4][i-1]>0)+
                (cnt[5][j]-cnt[5][i-1]>0)+
                (cnt[6][j]-cnt[6][i-1]>0)+
                (cnt[7][j]-cnt[7][i-1]>0)+
                (cnt[8][j]-cnt[8][i-1]>0)+
                (cnt[9][j]-cnt[9][i-1]>0);
                ans+=(temp<=temp2);
            }

        printf("%lld\n",ans);
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