#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int maxn = 100000+5;
const int INF = 1000000000;

struct edge{
	int d,c;
	edge(int d = 0, int c = 0):d(d),c(c){
	}
};

vector<edge> G[maxn];
int n;
int d[maxn], vis[maxn];

void addedge(int u, int v, int c){
	G[u].push_back(edge(v, c));
	G[v].push_back(edge(u, c));
}

void rev_bfs(){
	memset(vis, 0, sizeof(vis));
	memset(d, 0, sizeof(d));
	
	int m = n;
	d[m] = 0;
	queue<int > q;
	q.push(m);
	vis[m] = 1;
	
	while(!q.empty()){
		int l = q.front();
		q.pop();
		
		for(int i = 0; i<G[l].size(); i++){
			edge e = G[l][i];
			if(vis[e.d]==0){
				vis[e.d] = 1;
				q.push(e.d);
				d[e.d] = d[l]+1;
			}
		}
	}
//	printf("  %d\n", d[1]);
}
vector<int> ans;

void bfs(){
	memset(vis, 0, sizeof(vis));
	ans.clear();
	
	vector<int> q;
	q.push_back(1);
	vis[1] = 1;
	
//	printf("  %d\n", d[1]);
	for(int i =0; i< d[1]; i++){
		int min_color = INF;
		
		
		for( int j =0; j< q.size();j++){
			int k = q[j];
			for(int m = 0; m<G[k].size(); m++){
				edge e = G[k][m];
				if(d[k] == d[e.d]+1){
					min_color = min(min_color, e.c);
				}
			}
		}
//		printf("min_color %d \n", min_color);
		ans.push_back(min_color);
		
		// 找到下一个节点
		vector<int > next;
		for( int j =0; j< q.size();j++){
			int k = q[j];
			for(int m = 0; m<G[k].size(); m++){
				edge e = G[k][m];
				if(d[k] == d[e.d]+1 && min_color== e.c && !vis[e.d] ){
					vis[e.d] = 1;
					next.push_back(e.d);
//					printf("  %d  \n", e.d);
				}
			}
		}
//		printf("  %d  \n", q.size());
		q = next;
	}
	
	printf("%d\n", ans.size());
	printf("%d", ans[0]);
	for(int i = 1; i<ans.size(); i++) printf(" %d", ans[i]);
	printf("\n");
}


int main(){
	int m;
	int u, v,c;
	while(scanf("%d %d", &n, &m)==2){
		for(int i=1; i<=n; i++) G[i].clear();
		while(m--){
			scanf("%d %d %d", &u, &v, &c);
			addedge(u,v,c);
			addedge(v, u, c);
		}
		rev_bfs();
		bfs();
	}
	return 0;
}
