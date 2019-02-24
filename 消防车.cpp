#include<cstdio>
#include<cstring>
#include<stack>
#include<set> 
using namespace std; 

const int maxn = 24;
int G[maxn][maxn], vis[maxn];
int n,dest,m,tot;
int pa[maxn];
int par[maxn];

void output(int e){
	tot++;
	stack<int> s;
	int d = e;
	do{
		s.push(d);
		d = par[d];
	}while(d!=0);
	
	d = s.top(); s.pop();
	printf("%d", d);
	while(!s.empty()){
		d = s.top(); s.pop();
		printf(" %d", d);
	}
	printf("\n");
}

void dfs(int s){
	vis[s] = 1;
	if(s==dest){
		output(s);
		return;
	}
	for(int i  = 0; i < maxn; i++){
		if(!vis[i] && (G[s][i] || G[i][s])){
			par[i] = s;
			dfs(i);
			vis[i] = 0;
		}
	}
}


int findp(int s){
	return pa[s]==s? s: pa[s] = findp(pa[s]);
}

int main(){
	int kase = 0;
	while(scanf("%d", &dest)==1){
		printf("CASE %d:\n", ++kase);
		//½¨±í
		memset(G, 0, sizeof(G));
		for(int i = 0; i < maxn; i++) pa[i] = i;
		memset(vis, 0, sizeof(vis));
		memset(par, 0, sizeof(par));
		tot = 0;
		int s,e;
		while(scanf("%d%d", &s, &e)==2 && (s||e) ){
			G[s][e] = G[e][s] = 1;
			int f1 = findp(s), f2 = findp(e);
			if(f1!=f2){
				pa[f2]=f1;
			}
		}
		if(findp(1)==findp(dest)){
			dfs(1);
		}
		printf("There are %d routes from the firestation to streetcorner %d.\n", tot, dest); 
	}
	return 0;
}
