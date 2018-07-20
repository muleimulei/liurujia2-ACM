#include<cstdio>
#include<algorithm>
using namespace std;
int mark[10]={0};


void dfs(int n, int cur, int *a){
	if(cur==n+1){
		for(int i = 1; i <= n;i++){
			printf("%d ", a[i]);
		}
		printf("\n");
	}else{
		for(int i = 1; i<=n; i++){
			if(!mark[i]){
				mark[i] = 1;
				a[cur] = i;
				dfs(n, cur+1, a);
				mark[i] = 0;
			}
		}
	}
}

int main(){
	int n, p[10];
	scanf("%d", &n);
	for(int i = 0; i<n;i++) scanf("%d", &p[i]);
	sort(p, p+n);
	
	do{
		for(int i = 0; i<n;i++) printf("%d ", p[i]);
		printf("\n");
	}while(next_permutation(p, p+n));
}


int main2(){
	int n;
	scanf("%d", &n);
	int num[10];
	dfs(n, 1, num);
	return 0;
} 
