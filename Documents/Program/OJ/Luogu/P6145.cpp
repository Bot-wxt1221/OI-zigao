#include <cstdio>
#define read(X) {(X)=0;_c=getchar_unlocked();while(_c<'0'||'9'<_c)_c=getchar_unlocked();while('0'<=_c&&_c<='9')(X)=((X)<<3)+((X)<<1)+(_c&15),_c=getchar_unlocked();}
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE int

struct node{
    int to,next,w;
}e[100010];

int s[100010],head[100010],d[100010],q[100010];

int main(){
    register int i,a,b,x,j=1;
    register char _f,_c,out[20];;
    int n,m,c;
    read(n);
    read(m);
    read(c);

    for(i=1;i<=n;++i){read(s[i]);}
    for(i=0;i<c;++i){
        read(a);
        read(b);
        e[j].next=head[a];
        e[j].to=b;
        read(e[j].w);
        head[a]=j;
        ++d[b];
        ++j;
    }

    a=b=0;

    for(i=1;i<=n;++i)
        if(!d[i]) q[b++]=i;

    while(a<b){
        x=q[a++];
        for(i=head[x];i;i=e[i].next){
            j=e[i].to;
            --d[j];
            s[j]=s[j]>(s[x]+e[i].w)?s[j]:(s[x]+e[i].w);
            if(!d[j]) q[b++]=j;
        }
    }

    for(i=1;i<=n;++i){
        out[20];
        j=0;
        if(s[i]==0){
            putchar_unlocked('0');
            continue;
        }
        while(s[i]){
            out[j++]=s[i]%10;
            s[i]/=10;
        }
        while(j){
            putchar_unlocked(out[--j]+'0');
        }
        putchar_unlocked('\n');
    }

    return 0;
}