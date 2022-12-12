#include <cstdio>
#include <cstring>
#include <algorithm>
// #define file

int e[5000+2][5000+2];
int edges[5000+2][2];
int dfs_best[5000+2];
int dfs_now[5000+2];
int del_u,del_v,cnt,n,m;
char flag,flag_best;

int read();
void dfs(int u,int p){
	++cnt;
//	if(cnt>n) return;
	if(del_u){
		if(((!flag_best)&&u>dfs_best[cnt])||cnt>n){
			flag=1;
			return;
		}
		if(u<dfs_best[cnt]&&(!flag_best)) flag_best=1;
		dfs_now[cnt]=u;
		for(int i=1;i<=e[u][0];++i){
			if((!((del_u==u&&del_v==e[u][i])||(del_v==u&&del_u==e[u][i])))&&(e[u][i]!=p)){
				dfs(e[u][i],u);
				if(flag) return;
			}
		}
	}else{
		dfs_best[cnt]=u;
		for(int i=1;i<=e[u][0];++i){
			if(e[u][i]!=p) dfs(e[u][i],u);
		}
	}

	return;
}

int main(){
	#ifdef file
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	#endif
	
	register int i,u,v;
	 n=read();
	 m=read();
	
	for(i=1;i<=m;++i){
		u=read();
		v=read();
		
		e[u][++e[u][0]]=v;
		e[v][++e[v][0]]=u;
		edges[i][0]=u;
		edges[i][1]=v;
	}
	
	for(i=1;i<=n;++i) std::sort(e[i]+1,e[i]+1+e[i][0]);
	
	if(n==m){
		memset(dfs_best,0x3f,sizeof(dfs_best));
		dfs_best[cnt]=u;
		for(i=1;i<=m;++i){
			cnt=flag=flag_best=0;
			del_u=edges[i][0];
			del_v=edges[i][1];
			dfs(1,1);
			if(!flag&&cnt==n){
				for(u=1;u<=n;++u) dfs_best[u]=dfs_now[u];
			}else{
				for(u=1;u<=cnt;++u) dfs_now[u]=0;
			}
		}
	}else{
		dfs(1,1);
	}
	
	for(i=1;i<=n;++i) printf("%d ",dfs_best[i]);
	
	

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
}

int read(){
    register int x=0;register char f=0,c=getchar();
    while(c<'0'||c>'9')f=(c=='-'),c=getchar();//?=if,:=else
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c&15),c=getchar();
    return f?-x:x;
}
