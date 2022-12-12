#include <cstdio>
int main(){
    char c,a,outc=0;
    int num=0,numa=0,now=0,f=1;

    c=getchar();
    while(true){
        if(c=='-'||c=='+'||c=='='||c==EOF){
            if(a==1){
                if(now==0){
                    numa+=f;
                }else{
                    numa+=f*now;
                }
            }else{
                num+=now*f;
            }
            a=0;
            now=0;
            f=(c=='-'?-1:1);
            if(c=='='){
                num=-num;
                numa=-numa;
            }
            if(c==EOF) break;
        }else if(c>='0'&&c<='9'){
            now=(now<<3)+(now<<1)+(c&15);
        }else if(c>='a'&&c<='z'){
            a=1;
            if(outc==0) outc=c;
        }
        c=getchar();
    }

    float out=0-(num*1.0/(numa*1.0));
    printf("%c=%.3f",outc,out);

    return 0;
}