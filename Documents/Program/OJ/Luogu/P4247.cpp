#include<cstring>
#include<iostream>
#include<fstream>
namespace Fast_I{char*_Buf,*_Start_ptr,*_End_ptr;std::streambuf*inbuf;unsigned int Size;bool _Ok;struct Fast_Istream{operator bool(){return _Ok;}Fast_Istream(std::streambuf*,unsigned int);Fast_Istream(unsigned int);Fast_Istream(const char*,unsigned int);Fast_Istream&operator>>(char&);Fast_Istream&operator>>(char*);Fast_Istream&operator>>(bool&);Fast_Istream&operator>>(short&);Fast_Istream&operator>>(int&);Fast_Istream&operator>>(long&);Fast_Istream&operator>>(long long&);Fast_Istream&operator>>(unsigned short&);Fast_Istream&operator>>(unsigned int&);Fast_Istream&operator>>(unsigned long&);Fast_Istream&operator>>(unsigned long long&);Fast_Istream&operator>>(float&);Fast_Istream&operator>>(double&);Fast_Istream&operator>>(long double&);Fast_Istream&operator>>(std::string&);template<typename Typex>void operator()(Typex&_Val){*this>>_Val;}template<typename Typex,typename...More>void operator()(Typex&,More&...);std::streambuf*rdbuf(){return inbuf;}void rdbuf(std::streambuf*_inbuf){inbuf=_inbuf;}void rdbuf(const char*);void pop();char peek();};}namespace Fast_O{std::string buf;std::streambuf*outbuf;struct Fast_Ostream{Fast_Ostream(std::streambuf*,unsigned int);Fast_Ostream(std::streambuf*out){outbuf=out;}Fast_Ostream(const char*,unsigned int);Fast_Ostream(unsigned int);void flush();~Fast_Ostream();void endl(){buf.push_back('\n');}template<typename Typex>void endl(const Typex&_Val);template<typename Typex,typename...More>void endl(const Typex&,const More&...);template<typename Typex>void operator()(const Typex&_Val);template<typename Typex,typename...More>void operator()(const Typex&,const More&...);Fast_Ostream&operator<<(char);Fast_Ostream&operator<<(const char*);Fast_Ostream&operator<<(const std::string&);Fast_Ostream&operator<<(bool);Fast_Ostream&operator<<(short);Fast_Ostream&operator<<(int);Fast_Ostream&operator<<(long);Fast_Ostream&operator<<(long long);Fast_Ostream&operator<<(unsigned short);Fast_Ostream&operator<<(unsigned int);Fast_Ostream&operator<<(unsigned long);Fast_Ostream&operator<<(unsigned long long);std::streambuf*rdbuf(){return outbuf;}void rdbuf(std::streambuf*_outbuf){outbuf=_outbuf;}void rdbuf(const char*);};}namespace Fast_IO{Fast_I::Fast_Istream fin(std::cin.rdbuf(),1048576);Fast_O::Fast_Ostream fout(std::cout.rdbuf());}
#define cin Fast_IO::fin
#define cout Fast_IO::fout
namespace Fast_I{Fast_Istream::Fast_Istream(std::streambuf*in,unsigned int Sz){_Ok=1;Fast_I::Size=Sz;inbuf=in;_Start_ptr=_End_ptr=_Buf=new char[Sz];}Fast_Istream::Fast_Istream(const char*in,unsigned int Sz){_Ok=1;Fast_I::Size=Sz;rdbuf(in);_Start_ptr=_End_ptr=_Buf=new char[Sz];}Fast_Istream::Fast_Istream(unsigned int Sz){_Ok=1;Fast_I::Size=Sz;_Start_ptr=_End_ptr=_Buf=new char[Sz];}void Fast_Istream::rdbuf(const char*File){static std::ifstream __In__(File);rdbuf(__In__.rdbuf());}void Get_Char(char&_Val){if(_Start_ptr==_End_ptr){_Start_ptr=_Buf;_End_ptr=_Buf+inbuf->sgetn(_Buf,Size);}if(_Start_ptr==_End_ptr){_Val=-1;_Ok=0;}else{_Val=*_Start_ptr++;}}Fast_Istream&Fast_Istream::operator>>(char&_Val){if(_Ok){Get_Char(_Val);while(_Val==32||_Val==10||_Val==13||_Val==8||_Val==9||_Val==7||_Val==12||_Val==11){Get_Char(_Val);}}return*this;}Fast_Istream&Fast_Istream::operator>>(char*_Val){if(_Ok){Get_Char(*_Val);while(*_Val==32||*_Val==10||*_Val==13||*_Val==8||*_Val==9||*_Val==7||*_Val==12||*_Val==11){Get_Char(*_Val);}while(*_Val!=32&&*_Val!=10&&*_Val&&*_Val!=-1&&*_Val!=9&&*_Val!=11&&*_Val!=12){Get_Char(*++_Val);}*_Val=0;--_Start_ptr;}return*this;}Fast_Istream&Fast_Istream::operator>>(std::string&_Val){if(_Ok){char c;Get_Char(c);while(c==32||c==10||c==13||c==8||c==9||c==7||c==12||c==11){Get_Char(c);}for(_Val.clear();c!=32&&c!=10&&c&&c!=-1&&c!=9&&c!=11&&c!=12;Get_Char(c)){_Val.push_back(c);}--_Start_ptr;}return*this;}template<typename Typex>void Get_Int(Typex&_Val){if(_Ok){char ch;bool _F=0;for(Get_Char(ch);(ch<48||ch>57)&&ch!=-1;Get_Char(ch)){_F=ch==45;}for(_Val=0;ch>47&&ch<58&&ch!=-1;Get_Char(ch)){_Val=_Val*10+(ch^48);}if(_F){_Val=~_Val+1;}--_Start_ptr;}}template<typename Typex>void Get_Unsigned(Typex&_Val){if(_Ok){char ch;Get_Char(ch);while((ch<48||ch>57)&&ch!=-1){Get_Char(ch);}for(_Val=0;ch>47&&ch<58&&ch!=-1;Get_Char(ch)){_Val=_Val*10+(ch^48);}--_Start_ptr;}}template<typename Typex>void Get_Double(Typex&_Val){if(_Ok){char ch;bool _F=0;for(Get_Char(ch);(ch<48||ch>57)&&ch!=-1;Get_Char(ch)){_F=ch==45;}for(_Val=0;ch>47&&ch<58&&ch!=-1;Get_Char(ch)){_Val=_Val*10+(ch^48);}if(ch==46){unsigned long long _Pow=1;for(Get_Char(ch);ch>47&&ch<58&&ch!=-1;Get_Char(ch)){_Val+=Typex((ch^48)*1.0/(_Pow*=10));}}if(_F){_Val=-_Val;}--_Start_ptr;}}Fast_Istream&Fast_Istream::operator>>(bool&_Val){if(_Ok){char ch;Get_Char(ch);while(ch==32||ch==10||ch==13||ch==8||ch==9||ch==7||ch==12||ch==11){Get_Char(ch);}while(ch!=32&&ch!=10&&ch&&ch!=-1&&ch!=9&&ch!=11&&ch!=12){_Val|=ch!=48;Get_Char(ch);}--_Start_ptr;}return*this;}Fast_Istream&Fast_Istream::operator>>(short&_Val){Get_Int(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(int&_Val){Get_Int(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(long&_Val){Get_Int(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(long long&_Val){Get_Int(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(unsigned short&_Val){Get_Unsigned(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(unsigned int&_Val){Get_Unsigned(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(unsigned long&_Val){Get_Unsigned(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(unsigned long long&_Val){Get_Unsigned(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(float&_Val){Get_Double(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(double&_Val){Get_Double(_Val);return*this;}Fast_Istream&Fast_Istream::operator>>(long double&_Val){Get_Double(_Val);return*this;}template<typename Typex,typename...More>void Fast_Istream::operator()(Typex&_Val,More&..._More){*this>>_Val;operator()(_More...);}void Fast_Istream::pop(){char ch;Get_Char(ch);}char Fast_Istream::peek(){if(_Start_ptr==_End_ptr){_Start_ptr=_Buf;_End_ptr=_Buf+inbuf->sgetn(_Buf,Size);}if(_Start_ptr==_End_ptr){_Ok=0;return-1;}else{return*_Start_ptr;}}}namespace Fast_O{Fast_Ostream::Fast_Ostream(std::streambuf*out,unsigned int Size){buf.reserve(Size);outbuf=out;}Fast_Ostream::Fast_Ostream(const char*File,unsigned int Size){buf.reserve(Size);rdbuf(File);}void Fast_Ostream::rdbuf(const char*File){static std::ofstream __Out__(File);rdbuf(__Out__.rdbuf());}Fast_Ostream::Fast_Ostream(unsigned int Size){buf.reserve(Size);}void Fast_Ostream::flush(){outbuf->sputn(buf.data(),buf.size());buf.clear();}Fast_Ostream::~Fast_Ostream(){flush();}Fast_Ostream&Fast_Ostream::operator<<(char _Val){buf.push_back(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(const char*_Val){while(*_Val){buf.push_back(*_Val++);}return*this;}Fast_Ostream&Fast_Ostream::operator<<(const std::string&_Val){for(auto&&i:_Val){buf.push_back(i);}return*this;}template<typename Typex>void Put_Unsigned(Typex _Val){char*_Stack=(char*)malloc(sizeof(Typex)*3);unsigned S_top=0;while(_Val){_Stack[++S_top]=(_Val%10)^48;_Val/=10;}if(!S_top){buf.push_back('0');}while(S_top){buf.push_back(_Stack[S_top--]);}free(_Stack);}void Put_Int(long long _Val){if(_Val<0){buf.push_back('-');Put_Unsigned(~_Val+1);}else{Put_Unsigned(_Val);}}Fast_Ostream&Fast_Ostream::operator<<(bool _Val){buf.push_back(_Val?'1':'0');return*this;}Fast_Ostream&Fast_Ostream::operator<<(short _Val){Put_Int(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(int _Val){Put_Int(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(long _Val){Put_Int(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(long long _Val){Put_Int(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(unsigned short _Val){Put_Unsigned(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(unsigned int _Val){Put_Unsigned(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(unsigned long _Val){Put_Unsigned(_Val);return*this;}Fast_Ostream&Fast_Ostream::operator<<(unsigned long long _Val){Put_Unsigned(_Val);return*this;}template<typename Typex>void Fast_Ostream::endl(const Typex&_Val){*this<<_Val<<'\n';}template<typename Typex,typename...More>void Fast_Ostream::endl(const Typex&_Val,const More&..._More){*this<<_Val;endl(_More...);}template<typename Typex>void Fast_Ostream::operator()(const Typex&_Val){*this<<_Val;}template<typename Typex,typename...More>void Fast_Ostream::operator()(const Typex&_Val,const More&..._More){*this<<_Val;operator()(_More...);}}
const int mod=19940417;
#define _mid int mid=((l+r)>>1)
#define _lChild (q<<1)
#define _rChild ((q<<1)|1)
#define _lThings (_lChild),(l),(mid)
#define _rThings (_rChild),((mid)+1),(r)
#define _maxC min(20,tree[q].size)
#define INPUT_DATA_TYPE int
#define OUTPUT_DATA_TYPE long long

struct node{
    long long c[21],tagadd;
    int size;
    char tagrev;
    node(){
        tagadd=tagrev=size=0;
        c[0]=c[1]=c[2]=c[3]=c[4]=c[5]=c[6]=c[7]=c[8]=c[9]=c[10]=c[11]=c[12]=c[13]=c[14]=c[15]=c[16]=c[17]=c[18]=c[19]=c[20]=0;
    }
}tree[200001],temp__;

int Cnm[50010][21];

inline int max(int a,int b){
    return a>b?a:b;
}
inline int min(int a,int b){
    return a<b?a:b;
}

struct SEQ{
    long long temp[21];

    inline void updata(int q){
        register int i,j;
        tree[q].c[0]=tree[q].c[1]=tree[q].c[2]=tree[q].c[3]=tree[q].c[4]=tree[q].c[5]=tree[q].c[6]=tree[q].c[7]=tree[q].c[8]=tree[q].c[9]=tree[q].c[10]=tree[q].c[11]=tree[q].c[12]=tree[q].c[13]=tree[q].c[14]=tree[q].c[15]=tree[q].c[16]=tree[q].c[17]=tree[q].c[18]=tree[q].c[19]=tree[q].c[20]=0;
        for(i=0;i<=min(20,tree[_lChild].size);++i)
            for(j=0;i+j<=20&&j<=tree[_rChild].size;++j)
                tree[q].c[i+j]=(tree[q].c[i+j]+tree[_lChild].c[i]*tree[_rChild].c[j])%mod;
        return;
    }

    void add(int q,int c){
        if(!q||!c) return;
        register int i,j;
        temp[0]=1;
        for(i=1;i<=_maxC;++i) temp[i]=temp[i-1]*c%mod;
        for(i=_maxC;i;--i)
            for(j=0;j<i;++j)
                tree[q].c[i]=(tree[q].c[i]+tree[q].c[j]*temp[i-j]%mod*Cnm[tree[q].size-j][i-j])%mod;
        tree[q].tagadd=(tree[q].tagadd+c)%mod;
        return;
    }

    void rev(int q){
        if(!q) return;
        register int i;
        for(i=1;i<=_maxC;++i) tree[q].c[i]=((i&1)?mod-tree[q].c[i]:tree[q].c[i]);
        tree[q].tagadd=mod-tree[q].tagadd;
        tree[q].tagrev^=1;
        return;
    }

    node merge(node q,node w){
        node e;
        register int i,j;
        e.size=q.size+w.size;
        for(i=0;i<=min(20,q.size);++i)
            for(j=0;i+j<=20&&j<=w.size;++j)
                e.c[i+j]=(e.c[i+j]+q.c[i]*w.c[j])%mod;
        return e;
    }

    void push_down(int q){
        if(tree[q].tagrev){
            rev(_lChild);
            rev(_rChild);
            tree[q].tagrev=0;
        }
        if(tree[q].tagadd){
            add(_lChild,tree[q].tagadd);
            add(_rChild,tree[q].tagadd);
            tree[q].tagadd=0;
        }
        return;
    }

    void build(int q,int l,int r,int *a){
        tree[q].size=r-l+1;
        if(l==r){
            tree[q].c[0]=1;
            tree[q].c[1]=(a[l]%mod+mod)%mod;
            return;
        }
        _mid;
        build(_lThings,a);
        build(_rThings,a);
        updata(q);
        return;
    }

    void r_add(int q,int l,int r,int s,int t,int c){
        if(s<=l&&r<=t){
            add(q,c);
            return;
        }
        push_down(q);
        _mid;
        if(s<=mid) r_add(_lThings,s,t,c);
        if(mid<t) r_add(_rThings,s,t,c);
        updata(q);
        return;
    }

    void r_rev(int q,int l,int r,int s,int t){
        if(s<=l&&r<=t){
            rev(q);
            return;
        }
        push_down(q);
        _mid;
        if(s<=mid) r_rev(_lThings,s,t);
        if(mid<t) r_rev(_rThings,s,t);
        updata(q);
        return;
    }

    node query(int q,int l,int r,int s,int t){
        if(s<=l&&r<=t) return tree[q];
        push_down(q);
        _mid;
        if(t<=mid) return query(_lThings,s,t);
        if(mid<s) return query(_rThings,s,t);
        else return merge(query(_lThings,s,t),query(_rThings,s,t));
    }
}seq;

int a[50010];

int n,m;


int main(){
    register int i,j,k,l,r,c;
    register char op;
    cin(n,m);
    tree[0].c[0]=1;
    Cnm[0][0]=1;
    for(i=1;i<=n;++i){
        cin(a[i]);
        Cnm[i][0]=1;
        for(j=1;j<=20&&j<=i;++j) Cnm[i][j]=(Cnm[i-1][j]+Cnm[i-1][j-1])%mod;
    }
    seq.build(1,1,n,a);
    for(i=1;i<=m;++i){
        loop:cin(op);
        while(op!='I'&&op!='Q'&&op!='R')goto loop;
        cin(l,r);
        if(op=='I'){
            cin(c);
            c=(c%mod+mod)%mod;
            seq.r_add(1,1,n,l,r,c);
        }else if(op=='R'){
            seq.r_rev(1,1,n,l,r);
        }else{
            cin(c);
            cout.endl(((seq.query(1,1,n,l,r)).c[c]%mod+mod)%mod);
        }
    }

    return 0;
}