#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 1000

int num[maxn];
int isp[maxn];
int vis[maxn];
int n;

int is_prime(int n){
	int q = (int)sqrt(n)+1;
	for(int i = 2; i < q;i++){
		if(n % i==0) return 0;
	}
	return 1;
} 

void dfs(int v){
	if(v == n){
		if(!isp[num[n-1]+num[0]]) return;
		printf("%d", num[0]);
		for(int i = 1; i< n; i++){
			printf(" %d", num[i]);
		}
		printf("\n");
	}
	else {
		for(int i = 2; i<= n;i++){
		 	if(vis[i]==0 && isp[num[v-1]+i]){
		 		vis[i] = 1;
		 		num[v] = i;
		 		dfs(v+1);
		 		vis[i] = 0;
			}
		} 
	}
}
int main(){
	int kase = 0;
	while(scanf("%d", &n)!=EOF){
		memset(num, 0, sizeof(num));
		memset(isp, 0, sizeof(isp));
		memset(vis, 0, sizeof(vis));
		if(kase) printf("\n");
		for(int i = 1; i<= 2 * n; i++) isp[i] = is_prime(i);
		printf("Case %d:\n", ++kase);
		num[0] = 1;
		vis[1] = 1;
		dfs(1);	

	} 
	return 0;
}
