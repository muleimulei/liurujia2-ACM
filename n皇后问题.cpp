#include<cstdio>
#include<cmath>
#include<cstring>
const int maxn = 100;
int  cur[maxn];
int n,tot;
bool judge(int r, int l){
	for(int i = 0; i < r; i++){
		if( cur[i]==l || abs(l - cur[i]) == abs(r - i) ){
			return 0;
		}
	}
	return 1;
}
void dfs(int r){
	if(r==n){
		tot++;
		for(int i = 0; i < n; i++){
			for(int j = 0; j<n; j++){
				if(j == cur[i]){
					printf("1");
				}else{
					printf("0");
				}
			}
			printf("\n");
		}
		printf("\n");
	}else{
		for(int i = 0; i < n; i++){
			cur[r] = i;
			if(judge(r, i)){
				dfs(r+1);
			}
		}
	}
}
int main(){
	scanf("%d", &n);
	memset(cur, -1, sizeof(cur));
	int r = tot = 0;
	dfs(r);
	printf("------%d------\n", tot);
	return 0;
}
