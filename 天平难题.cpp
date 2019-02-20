#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 7;

double r;
int n;

double sum[1<<maxn]; 
double w[maxn];
struct Tree {
  double L, R; // distance from the root to the leftmost/rightmost point
  Tree(double l=0, double r=0): L(l), R(r){
  }
};
int vis[1<<maxn];

vector<Tree> tree[1<<maxn];

void dfs(int sub){
	if(vis[sub]) return ;
	vis[sub] = 1;
	tree[sub].clear();

	bool has_child = 0;
	for(int left = (sub-1) & sub; left; left = (left-1)&sub ){
		has_child = 1;
		
		int right = sub ^ left;
		
		double d1 = sum[right] / sum[sub];
		double d2 = sum[left] / sum[sub];
		
		dfs(left);
		dfs(right);
		
		for(int i = 0 ; i < tree[left].size(); i++){
			for(int j = 0; j < tree[right].size(); j++){
				Tree d;
				d.L = max( tree[left][i].L + d1, tree[right][j].L-d2);
				d.R = max( tree[right][j].R + d2, tree[left][i].R-d1 );
				
				double u = d.L+d.R;
				if(u < r && !(u>r-0.00001 && u<r+0.00001) ){
					tree[sub].push_back(d);
				}
			}
		}
	}
	if(!has_child) tree[sub].push_back(Tree());
}

int main(){
	#ifdef LOCAL
		freopen("1.in", "r", stdin);
	#endif
	
	int T;
	scanf("%d", &T);
	while(T--){
		memset(vis, 0, sizeof(vis));
		scanf("%lf%d", &r, &n);
		memset(sum, 0, sizeof(sum));
		
		
		for(int i = 0; i < n; i++){
			scanf("%lf", &w[i]);
		}
		
		for(int i = 0; i < (1<<n); i++){
			for(int j = 0; j < n; j++ ){
				if(i & (1<<j)){
					sum[i] += w[j];
				}
			}
		}
		
		int root  = (1 << n) - 1;
		dfs(root);
		
		double m = -1;
		for(int i = 0; i < tree[root].size(); i++){
			m =  max(m, tree[root][i].L + tree[root][i].R);
		}
		if(m==-1) puts("-1");
		else printf("%.16lf\n", m);
	}
	return 0;
}

