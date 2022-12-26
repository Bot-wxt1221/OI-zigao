#include<stdio.h>
#define INPUT_DATA_TYPE char
#define OUTPUT_DATA_TYPE int
#define _ui unsigned int
#define MAXN (30+10)

int dp[MAXN][MAXN];
char socer[MAXN],root[MAXN][MAXN];

INPUT_DATA_TYPE read();
void print(OUTPUT_DATA_TYPE x);
_ui dfs(char l,char r){
    if(l>r) return 1;
    if(l==r) return socer[l];
    if(dp[l][r]) return dp[l][r];
    _ui max=0,temp;
    char nowroot=-1;
    for(char i=l;i<=r;++i){
        temp=dfs(l,i-1)*dfs(i+1,r)+socer[i];
        if(temp>max){
            max=temp;
            nowroot=i;
        }
    }
    dp[l][r]=max;
    root[l][r]=nowroot;
    return max;
}

void printtree(int l,int r){
    if(l>r) return;
    if(l==r){
        print(l);
        putchar_unlocked(' ');
        return;
    }
    print(root[l][r]);
    putchar_unlocked(' ');
    printtree(l,root[l][r]-1);
    printtree(root[l][r]+1,r);
}

int main(){
    register int n=read();
    for(register int i=1;i<=n;++i)
        socer[i]=read();

    print(dfs(1,n));
    putchar_unlocked('\n');
    printtree(1,n);

    return 0;
}

INPUT_DATA_TYPE read(){
    register INPUT_DATA_TYPE x=0;register char f=0,c=getchar_unlocked();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar_unlocked();//?=if,:=else
    while(c>='0'&&c<='9')x=x*10+(c&15),c=getchar_unlocked();
    return f?-x:x;
}

void print(OUTPUT_DATA_TYPE x){
    register char s[20];
    register char i=0;
    if(x<0){
        x=-x;
        putchar_unlocked('-');
    }
    if(x==0){
        putchar_unlocked('0');
        return;
    }
    while(x){
        s[i++]=x%10;
        x/=10;
    }
    while(i){
        putchar_unlocked(s[--i]+'0');
    }
    return;
}