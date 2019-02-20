#include<cstdio>
#include<cstring>
#include<cctype>
#include<queue>
using namespace std;

const int maxs = 20;
const int maxn = 150;

const int dx[]={1, -1, 0, 0, 0};
const int dy[]={0, 0, -1, 1, 0};

inline int ID(int a, int b, int c){
	return (a<<16) | (b<<8)|c;	
}

int s[3], t[3]; //起始于结束位置
int deg[maxn], G[maxn][5]; // 
 
inline bool conflict(int a, int b, int a2, int b2){
	return a2==b2 || (a2==b && b2==a);
} 

int d[maxn][maxn][maxn]; //距起始位置地位置 

int bfs(){
	queue<int> q;
	memset(d, -1, sizeof(d));
	
	q.push(ID(s[0], s[1], s[2])); // 起始节点
	d[s[0]][s[1]][s[2]] = 0;
	 
	while(!q.empty()){
		int u = q.front(); q.pop();
		int a = (u>>16) & 0xff, b = (u>>8)&0xff, c = u &0xff;
		if(a==t[0] && b ==t[1] && c == t[2]) return d[a][b][c];
		for(int i = 0; i < deg[a]; i++){
			int a2 = G[a][i];
			for(int j = 0; j < deg[b]; j++){
				int b2 = G[b][j];
				if(conflict(a, b, a2, b2)) continue;
				for(int k = 0; k < deg[c]; k++){
					int c2 = G[c][k];
					if(conflict(a, c, a2, c2)) continue;
					if(conflict(b, c, b2, c2)) continue;
					if(d[a2][b2][c2]!=-1) continue;
					
					d[a2][b2][c2] = d[a][b][c]+1;
					q.push(ID(a2, b2, c2));
				}
			}
		}
	}
	return -1;
}

int main(){
#ifdef LOCAL
		freopen("1.in", "r", stdin);
	#endif
	
	int w, h, n;
	while(scanf("%d%d%d\n", &w, &h, &n)==3 &&n){
		char maze[20][20];
		for(int i = 0; i < h; i++){
			fgets(maze[i], 20, stdin);
		}
		
		// 额外空格
		int cnt, x[maxn], y[maxn], id[maxs][maxs]; // cnt记录空格数
		cnt = 0;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(maze[i][j]!= '#'){
					x[cnt] = i;
					y[cnt] = j;
					id[i][j] = cnt;
					if(islower(maze[i][j])){
						s[maze[i][j]-'a'] = cnt;
					}else if(isupper(maze[i][j])){
						t[maze[i][j]-'A'] = cnt;
					}
					cnt++;
				}
				
			}
		} 
		
		// 建图
		for(int i = 0; i < cnt; i++){
			deg[i] = 0;
			for(int dir = 0; dir<5; dir++){
				int nx = x[i]+dx[dir], ny = y[i] + dy[dir];
				if(maze[nx][ny]!='#'){
					G[i][deg[i]++] = id[nx][ny];
				}
			}
		} 
		
		if(n<=2) {
			deg[cnt] = 1;
			G[cnt][0] = cnt;
			s[2] = t[2] = cnt++;
		}
		if(n<=1){
			deg[cnt] = 1;
			G[cnt][0] = cnt;
			s[1] = t[1] = cnt++;
		}
		
		printf("%d\n", bfs());
				
	} 
	
	return 0;
} 

