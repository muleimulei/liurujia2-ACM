#include<cstdio> 
void read_input(){
	int u, v;
	scanf("%d", n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}

void dfs(int root, int k){ // 递归转化为以root为根的子树，root的父节点为k 
	for(int i = 0; i < G[root].size(); i++ ){ // 节点u的相邻点个数 
		int v = G[root][i]; // 节点root第 i个相邻点 
		if(v != k){ // 判断V是否和父节点相等，如果忽略，将引起无限递归 
			pa[v] = root;
			dfs(v, root);
		}
	}
}

int main (){
	memset(pa, -1, sizeof(par));
	read_input();
	int m;
	scanf("%d", &m);
	dfs(m, -1);
	
	return 0;
}
