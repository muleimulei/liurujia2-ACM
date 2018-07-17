
#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 150;
 
int m, n;
int from, to;
vector<int> G[maxn];
vector<int> ans;
int used[maxn];
 
void init() {
	ans.clear();
	memset(used, 0, sizeof(used));
	for (int i = 0; i < maxn; i++) G[i].clear();
}
 
bool dfs(int v) {
	used[v] = -1;
	for (int i = 0; i < G[v].size(); i++) {
		int u = G[v][i];
		if (-1 == used[u]) return false;
		if (0 == used[u] && !dfs(u)) return false;
	}
	used[v] = 1;
	ans.push_back(v);
	return true;
}
 
bool toposort() {
	for (int i = 1; i <= n; i++) {
		if (!used[i]) 
			if (!dfs(i)) return false;
	}
	return true;
}
 
int main() {
	while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
		init();
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &from, &to);
			G[from].push_back(to);
		}
		
		if (!toposort()) continue;
		
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			printf("%d%c", ans[i], i + 1 == ans.size() ? '\n' : ' ');
		}
	}
	return 0;
}
