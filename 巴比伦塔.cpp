#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 50;
int block[maxn][3];
int n, d[maxn][maxn];

void getans(int &c, int &w,int idx, int k){
	c = w = -1;
	for(int i = 0; i < 3; i++){
		if(i==k) continue;
		else{
			if(c==-1){
				c = block[idx][i];
			}else{
				w = block[idx][i];
			}
		}
	}
}

int solve(int idx, int k){
	int &ans = d[idx][k];
	if(ans > 0) return ans;
	
	int h,h1;
	h = h1 = block[idx][k];
	
	// 得到第idx个长于宽 
	int c, w;
	getans(c, w,idx, k);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			int c1, w1;
			getans(c1, w1, i, j);
			if( (c1<c && w1<w) || (c1<w && w1<c) ){
				h1 = max(h1, h + solve(i, j)); 
			}
		}
	}
	return ans = h1;
}


int main(){
	#ifdef LOCAL
		freopen("1.in", "r", stdin);	
	#endif
	int kase = 0;
	while(scanf("%d", &n)==1 && n){
		memset(d, 0, sizeof(d));
		for(int i = 0; i< n; i++ ){
			scanf("%d %d %d", &block[i][0], &block[i][1], &block[i][2]);			
		}
		
		int h = -1;
		for(int i = 0; i < n; i++){ // dp[idx][h] 以第idx个，第h维度开始能多高 
			for(int j = 0; j < 3; j++){
				h = max(h, solve(i, j));
			}
		}
		printf("Case %d: maximum height = %d\n", ++kase, h);
	}
	return 0;
} 

