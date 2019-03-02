#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;
const int maxq = 8;
int n; // 点数 
int x[maxn], y[maxn], cost[maxq]; // 记录每个点的坐标和套餐代价
vector<int> subn[maxq]; // 优惠

int pa[maxn];
int find(int x) {
	return pa[x]==x? x: pa[x] = find(pa[x]);
}


struct Edge{
	int u, v, d;
	Edge(int u, int v, int d): u(u), v(v), d(d){
	}
	bool operator < (const Edge & rhs) const{
		return d < rhs.d; 
	}
};




int MST(int n, vector<Edge> &e, vector<Edge> &need ){
	if(n==1) return 0;
	int size = e.size(), ans = 0;
	need.clear();
	for(int i = 0; i< e.size(); i++){
		int u = find(e[i].u), v = find(e[i].v), d = e[i].d;
		if(u!=v){
			pa[u] = v;
			ans += d;
			need.push_back(e[i]);
			n--;
			if(n==1) break;
		}
	}
	return ans;
}


int main(){
	int T; // 样例个数 
	scanf("%d", &T);
	while(T--){
		int q; // 套餐个数 
		scanf("%d%d", &n, &q);
		for(int i = 0; i < q; i++){
			int cnt;
			scanf("%d%d", &cnt, &cost[i]);
			subn[i].clear();
			while(cnt--){
				int u;
				scanf("%d", &u);
				subn[i].push_back(u-1); // 第i个套餐所包含的点数 
			}
		}
		
		for(int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
		
		vector<Edge> e, need;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				int c = (x[i] - x[j])*(x[i] - x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				e.push_back(Edge(i, j, c));
			}
		}
		
		for(int i = 0; i < n; i++) pa[i] = i;
		sort(e.begin(), e.end());
		int ans = MST(n, e, need); // 克鲁斯卡尔 
		for(int mask = 0; mask < (1<<q); mask++){
			// 连接套餐的所有节点 
			int c = 0, cnt = n;
			for(int i = 0; i < n; i++) pa[i] = i;
			for(int j = 0; j < q; j++){
				if(mask & (1<<j)){
					c += cost[j];
					for(int i = 1; i < subn[j].size(); j++){
						int u = find(subn[j][0]), v = find(subn[j][i]);
						if(u!=v){
							pa[u] = v;
							cnt--;
						}
					}
				}
			}
			vector<Edge> dummy;
			ans = min(ans, c + MST(cnt, need, dummy));
		}
		printf("%d\n", ans);
	}
	return 0;
}

