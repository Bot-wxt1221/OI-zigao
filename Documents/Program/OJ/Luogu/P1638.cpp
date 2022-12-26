#include<cstdio>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int
INPUT_DATA_TYPE read(){register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();while(c<'0'||'9'<c)f=(c=='-'),c=getchar();while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();return f?-x:x;}void print(OUTPUT_DATA_TYPE x){register char s[20];register int i=0;if(x<0){x=-x;putchar('-');}if(x==0){putchar('0');return;}while(x){s[i++]=x%10;x/=10;}while(i){putchar(s[--i]+'0');}return;}

int bucket[2010],arr[1000010];

int main(){
    register int l,r,best_l=0,best_r=0x3f3f3f3f,cnt=0;
    int n=read();
    int m=read();
    for(l=r=0;r<n;++r){
        arr[r]=read();
        if(!bucket[arr[r]]) ++cnt;
        ++bucket[arr[r]];
        while(bucket[arr[l]]>1) --bucket[arr[l++]];
        if(cnt==m&&(r-l)<(best_r-best_l)){
            best_l=l;
            best_r=r;
        }
    }

    print(best_l+1);
    putchar(' ');
    print(best_r+1);

    return 0;
}