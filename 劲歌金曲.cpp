#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxn = 180*50+5;

int n, max_t;
int t[50+10]; //每首歌曲的时间

struct node{
	int n; // 总歌曲数 
	int time; //歌曲总时间
	
	bool operator < (const node &rhs) const {
		return n < rhs.n || n==rhs.n && time < rhs.time;
	} 
}; 

node dp[maxn];

int main(){
	int T, kase = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++kase);
		scanf("%d%d", &n, &max_t);
		memset(dp, 0, sizeof(dp));
		
		int sum = 0; // 歌曲总时长
		for(int i = 1; i<= n; i++){
			scanf("%d", &t[i]);
			sum += t[i];
		}
		 
		max_t -=1;
		for(int i = 1; i <=n; i++){
			for(int j = max_t; j>=t[i]; j--){
				node tmp;
				tmp.n = dp[j-t[i]].n+1;
				tmp.time = dp[j-t[i]].time+t[i];
				if(dp[j]<tmp){
					dp[j] = tmp;
				}	
			}
		}
		
		printf("%d %d\n", dp[max_t].n+1, dp[max_t].time+678);
	}
	
	
	return 0;
} 
