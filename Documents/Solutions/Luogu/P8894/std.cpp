#include <cstdio>
#include <algorithm>
#define INPUT_DATA_TYPE long long
#define OUTPUT_DATA_TYPE long long

struct node{
    int l,r;
}arr[5010];

long long ansleq[5010];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    register int i,j,min=0,max=0;
    register long long temp,ans=0;
    int n=read();

    for(i=0;i<n;++i){
        arr[i].l=read();
        arr[i].r=read();
        min=std::max(min,arr[i].l);//精确控制上下界
        max=std::max(max,arr[i].r);
    }

    for(i=min;i<=max;++i){
        temp=1;
        for(j=0;j<n;++j)
            temp=temp*(std::min(i,arr[j].r)-arr[j].l+1)%998244353;
        ansleq[i]=temp;
    }

    for(i=min;i<=max;++i) ans=(ans+(((ansleq[i]-ansleq[i-1]))*i%998244353)+998244353)%998244353;//注意ansleq[i]-ansleq[i-1]可能为负数

    print(ans);

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