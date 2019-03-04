#include<cstdio>
#include<cstring>
#include<algorithm>
//using namespace std;
const int maxn = 100;
#define INF 1<<30
int G[maxn][maxn];
int next[maxn][maxn];
int d[maxn][maxn];
int m, n;

int solve(int r, int c){
	if(c==n) return d[r][c];
	int ans = d[r][c];
	if(ans!= INF) return ans;
	
	// 下一列的行数，挑最小的 
	int rows[] = {r-1, r, r+1};
	if(r-1 <1) rows[0] = m;
	if(r+1 >m) rows[2] = 1;
	
	std::sort(rows, rows+3);
	
	int fakeans;
	fakeans = G[r][c]; //位置没有计算过 
	ans = INF;
	int h  = rows[0];
	
	for(int i = 0; i < 3; i++){
		int sum = fakeans + solve(rows[i], c+1);
		if(sum < ans){
			ans = sum;
			h = rows[i];
		}
	}

	d[r][c] = ans;
	next[r][c] = h;
	return ans;
}

int main(){
	#ifdef LOCAL
		freopen("1.in", "r", stdin);
	#endif
	while(scanf("%d%d", &m, &n)==2){
		// 初始化 
		memset(next, 0, sizeof(next));
		for(int i = 1; i <= m; i++){
			for(int j = 1; j<= n; j++){
				scanf("%d", &G[i][j]);
				d[i][j] = INF;
				if(j== n){
					d[i][j] = G[i][j];
				}
			}
		}
		
		// dp处理
		for(int i = 1; i <= m; i++){
			d[i][1] = solve(i, 1);
		}
		
		// 挑选出d[i][1]最小值 
		int pos = 1, max = d[1][1];
		for(int i = 2; i<=m; i++){
			if(d[i][1] < max){
				max = d[i][1];
				pos = i;
			}
		}

		// 进行输出 
		printf("%d", pos);
		int p = pos;
		for(int i = 1; i <=n-1; i++){
			printf(" %d", next[p][i]);
			p = next[p][i];
		}
		printf("\n%d\n", d[pos][1]);
	}
	return 0; 
} 
