/*
	消除所有点的标号
	设d[0] = 0, 其它d[i] = INF
	循环n次{
		在所有未标号节点中，选出d值最小的节点x
		给节点X标记
		对于从x出发的所有边(x,y),更新d[y] = min(d[y], d[x]+w(x, y)) 
	}
*/ 

/*
假设起点是节点0，它到节点i的路径长度为d[i]。未标号的节点为v[i] = 0,已标号的节点为v[i]=1,用w[x][y]=INF表示边不存在
memset(v, 0, sizeof(v));
for(int i = 0; i < n; i++) d[i] = (i==0? 0: INF);

for(int i = 0; i < n; i++){
	int x = 0, m = INF;
	for(int y = 0; y < n; y++) if(!v[y] && d[y]<=m) m = d[x==y];
	v[x] = 1;
	for(int y = 0; y < n; y++) d[y] = min(d[y], d[x] + w[x][y]);
}
*/


struct Edge{
	int from, to, dist;
	Edge(int u, int v, int d): from(u), to(v), dist(d){
	}
};
struct HeapNode{
	int d, u;
	bool operator < (const HeapNode &rhs) const{
		return d>rhs.d;
	}
};

struct Dijkstra{
	int n, m; // 节点数和边数
	vector<Edge> edges; // 存储所有的边 
	vector<int> G[maxn]; // 第i个节点连接的边 
	bool done[maxn]; // 是否已永久标号
	int d[maxn]; // s到各个点的距离
	int p[maxn]; // 最短路中的上一条弧
	
	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	
	void addEdge(int from, int to, int dist){
		edges.push_back(Edge(from, to, dist));
		m = edges.size();
		G[from].push_back(m-1);
	}

	void dijkstra(int s){
		priority_queue<HeapNode> Q;
		for(int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		Q.push(HeapNode(d[s], s));
		while(!Q.empty()){
			HeapNode x = Q.top(); Q.pop();
			if(done[x.u]) continue;
			done[x.u] = 1;
			for(int i = 0; i < G[x.u].size(); i++){
				Edge &e = edges[G[x.u][i]];
				if(d[x.u] + e.dist < d[e.to]){
					d[e.to] = e.dist+d[x.u];
					p[e.to] = G[x.u][i];
					Q.push(HeapNode(d[e.to], e.to));
				}
			}
		}
	}
};
