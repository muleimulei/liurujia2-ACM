#include<cstdio>
#include<cstring>
#define maxn 1000

int buf[maxn][maxn];
int m,n;
int ans[maxn];
int used[maxn];
int t;
bool dfs(int v){
	used[v] = -1;
	for(int i = 1; i<=n;i++){
		if(buf[v][i]){
			if(used[i]==-1) return false; ///存在有向环 
			else if(!used[i] && !dfs(i)) return false;
		}
	}
	
	used[v] = 1;
	ans[--t] = v;
	return true;
}

bool toposort(){
	t = n;
	for(int i = 1; i<=n;i++){
		if(!used[i]){
			if(!dfs(i)) return false;
		}
	}
	return true;
}

int main(){
	while(scanf("%d %d", &n, &m)==2){
		if(m ==0 && n==0) break;
		
		memset(buf, 0, sizeof(buf));
		memset(used, 0, sizeof(used));
		
		for(int i = 0; i<m;i++){
			int a, b;
			scanf("%d %d", &a, &b);
			buf[a][b] = 1;
		}
		
		if(!toposort()) continue;
		
		//printf("%d", ans[0]);
		for(int i = 0; i<n;i++){
			printf("%d%c", ans[i], i+1 == n?'\n':' ');
		}
//		printf("\n");
	}
	return 0; 
} 
