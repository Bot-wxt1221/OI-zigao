#include<cstdio>
#include<algorithm>
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

#define read(X) {(X)=0;_c=getchar_unlocked();while(_c<'0'||'9'<_c)_c=getchar_unlocked();while('0'<=_c&&_c<='9')(X)=((X)<<3)+((X)<<1)+(_c&15),_c=getchar_unlocked();}


struct node{
    int t,id;
    node(){
        id=-1;
    }
    bool operator < (const node another) const{
        if(id!=another.id) return id<another.id;
        return t<another.t;
    }
}arr[100010];

// INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);

int main(){
    register int i,head,x,_i;
    register char _c,s[20];
    int n,d,k;
    read(n);
    read(d);
    read(k);

    for(i=0;i<n;++i){ read(arr[i].t);read(arr[i].id);}

    std::sort(arr,arr+n);

    head=0;
    i=0;
    while(i<n){
        while(arr[i].t-arr[head].t>=d) ++head;
        if(i-head+1>=k){
            print(arr[i].id);
            x=arr[i].id;
            if(x<0){
                x=-x;
                putchar_unlocked('-');
            }
            if(x==0){
                putchar_unlocked('0');
                return;
            }
            while(x){
                s[_i++]=x%10;
                x/=10;
            }
            while(i){
                putchar_unlocked(s[--_i]+'0');
            }
            return;
            putchar_unlocked('\n');
            while(arr[i].id==arr[head].id) ++i;
            head=i;
            continue;
        }
        if(arr[i].id!=arr[i+1].id){
            i=head=i+1;
            continue;
        }
        ++i;
    }

    return 0;
}

// INPUT_DATA_TYPE read(){
//     register INPUT_DATA_TYPE x=0;register char f=0,c=getchar();
//     while(c<'0'||'9'<c)f=(c=='-'),c=getchar();//?=if,:=else
//     while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
//     return f?-x:x;
// }

void print(OUTPUT_DATA_TYPE x){

}