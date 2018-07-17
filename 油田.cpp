#include<cstdio>
#include<cstring>
#define maxn 1000+10

char oil[maxn][maxn];
int idx[maxn][maxn];
int m, n;

int go[][2]={
	-1, -1,
	-1, 0,
	-1, 1,
	0, -1,
	0, 1,
	1,-1,
	1, 0,
	1, 1
};

void dfs(int x, int y){
	for(int i = 0; i < 8; i++){
		int x1 = x + go[i][0];
		int y1 = y + go[i][1];
		
		if(x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
		
		if(idx[x1][y1] == 0 && oil[x1][y1]=='@'){
			idx[x1][y1] = 1;
			dfs(x1, y1);
		}
	}
}

int main(){
	
	while(scanf("%d %d", &m, &n)!=EOF && m &&n){
		memset(idx, 0, sizeof(idx));
		
		for(int i = 0; i < m; i++){
			scanf("%s", oil[i]);
		}
		
		int num = 0;
		for(int i = 0; i< m ;i++){
			for(int j = 0; j < n; j++){
				char c = oil[i][j];
				if(c=='@' && idx[i][j]==0){
					dfs(i, j);
					num++;
				}
			}
		}
		printf("%d\n", num);
	}
	return 0;
}
