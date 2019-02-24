#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 9;
int n, a[maxn];

bool is_sorted(){
	for(int i = 0; i < n-1; i++){
		if(a[i]>= a[i+1]) return 0;
	}
	return 1;
}

int h(){
	int cnt = 0;
	for(int i = 0; i < n-1; i++){
		if(a[i]+1 != a[i+1]) cnt++;
	}
	if(a[n-1]!= n) cnt++;
	return cnt;
}

// dfs
bool dfs(int d, int maxd){
	if(d*3+ h() > maxd*3) return 0;
	if(is_sorted()) return 1;
	
	int b[maxn], olda[maxn];
	memcpy(olda, a, sizeof(a));
	
	for(int i = 0; i < n; i++){ // 确定剪切上限 
		for(int j = i; j < n; j++){ //确定剪切下线 

			// 剪切
			int cnt = 0;
			for(int k = 0; k < n; k++){
				if(k < i || k> j) b[cnt++] = a[k];
			}
			
			// 在第K位置前插入 
			for(int k =0; k <= cnt; k++){
				int cnt2 = 0;
				for(int p = 0; p < k; p++) a[cnt2++] = b[p]; // k之前的数字 
				for(int p = i; p <=j; p++) a[cnt2++] = olda[p]; // 街区的数字 
				for(int p = k; p<cnt; p++) a[cnt2++] = b[p]; // k之后的数字 
				
				if(dfs(d+1, maxd)) return 1;
				memcpy(a, olda, sizeof(olda));
			}
		}
	}
	return 0;
} 



int solve(){
	if(is_sorted()) return 0;
	int max_ans = 5;
	for(int maxd = 1; maxd < max_ans; maxd++)
		if(dfs(0, maxd)) return maxd;
	return max_ans;
}


int main(){
	int kase = 0;
	while(scanf("%d", &n)==1 && n){
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		printf("Case %d: %d\n", ++kase, solve());
	} 
	return 0;
}
