/*
	把所有边排序，记第i小的边为e[i] (1<=i<m)
	初始化MST为空
	初始化连通分量，让每一个点自成一个独立的联通分量
	for(int i = 0; i < m; i++)
		if(e[i].u和e[i].v不在同一个连通分量){
			把边e[i]加入MST 
			合并e[i].u与e[i].v所在的联通分量 
		}
*/

int cmp(const int i, const int j) return w[i] < w[j];  // 间接排序函数 
int find(int x) { return p[x]==x? x: p[x] = find(x); } // 并查集的find 

int kruskal(){
	int ans = 0;
	for(int i = 0; i < n; i++) p[i] = i; // 初始化并查集
	for(int i = 0; i < m; i++) r[i] = i; // 初始化边序号 
	
	sort(r, r+m, cmp); // 给边排序
	for(int i = 0; i < m; i++){
		int e = r[i];
		int x = find(u[e]), y = find(v[e]); // 找出当前边两个端点所在的集合编号 
		if(x!=y) {
			ans += w[i];
			p[x] = y; // 如果在不同集合，合并 
		}
	}
	return ans;
}


