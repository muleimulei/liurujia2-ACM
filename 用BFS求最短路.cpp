#include<cstring>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

const int maxn = 10000;
int dis[maxn][maxn];
int pic[maxn][maxn];
int visited[maxn][maxn];
int m, n;

int go[][2] ={
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};

void show(){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n;j++){
			printf("%d ", dis[i][j]);
		}
		printf("\n");
	}
}

void bfs(int x, int y){
	visited[x][y] = 1;
	dis[x][y] = 0;
	std::queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		if(pic[p.first][p.second] == 3){
			show();
			return;
		}else{
			for(int i = 0; i< 4; i++){
				int nx = p.first + go[i][0];
				int ny = p.second + go[i][1];
				if(nx<0 || nx>= m || ny<0 || ny>= n || pic[nx][ny] ==0 || visited[nx][ny]) continue;
				dis[nx][ny] = dis[p.first][p.second] + 1;
				q.push(make_pair(nx, ny));
				visited[nx][ny] = 1;
			}
		}
	}
}

int main(){
	
	while(scanf("%d %d", &m, &n)==2){
		memset(pic,0, sizeof(pic));
		memset(visited, 0, sizeof(visited));
		memset(dis, 0, sizeof(dis));

		for(int i = 0; i< m;i++){
			for(int j = 0; j<n; j++){
				scanf("%d", &pic[i][j]);
			}
		}
		bfs(0, 0);
	}
	return 0;
}
