#include<cstdio>
#include<cctype> 
#include<cstring>
#include<map>
#include<queue>
using namespace std;
const int maxn = 18;

int h,w,n;
char G[maxn][maxn];

int s[3], e[3];

bool mark[maxn*maxn];  // ¼ÇÂ¼¿ÕµØ
short d[maxn*maxn][maxn*maxn][maxn*maxn];

vector<short> vv[maxn*maxn], ve;

int go[][2]={
	0, 0,
	-1, 0,
	1, 0,
	0, -1,
	0, 1
}; 

bool chongtu(int n1, int n2, int x, int y){
	return n1==n2 || ( n1==y && n2==x);
}

int bfs(){
	vector<int> v1, v2;
	for(int i = 0; i < n; i++){
		v1.push_back(s[i]);
		v2.push_back(e[i]);
	}
	d[v1[0]][v1[1]][v1[2]] = 0; // ³õÊ¼×´Ì¬ 
	queue<vector<int> > q;
	q.push(v1);

	while(!q.empty()){
		vector<int> b = q.front(); q.pop();
		if(b==v2){
			return d[v2[0]][v2[1]][v2[2]];
		}else{
			int y1 = b[0], y2 = b[1], y3 = b[2];
			// ×´Ì¬Ç¨ÒÆ 
			for(int i = 0; i < vv[y1].size(); i++){
				int new1 = vv[y1][i];
				
				for(int j = 0; j < vv[y2].size(); j++){
					int new2 = vv[y2][j];
					
					if(chongtu(new1, new2, y1, y2)) continue;
					for(int k = 0; k < vv[y3].size(); k++){
						int new3 = vv[y3][k];
						
						if(chongtu(new1, new3, y1, y3)) continue;
						if(chongtu(new2, new3, y2, y3)) continue;

						if(d[new1][new2][new3]!=-1) continue;
						d[new1][new2][new3] = d[y1][y2][y3]+1;

						q.push({new1, new2, new3});
					}
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
	while(scanf("%d%d%d", &w, &h, &n)!=EOF&&n){
		getchar();
		memset(mark, 0, sizeof(mark));
		memset(d, -1, sizeof(d));
		ve.clear();
		for(int i = 0; i < h; i++){
			fgets(G[i], maxn, stdin);
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++ ){
				int id = i * w + j;
				if(G[i][j]!='#'){
					ve.push_back(id);
					if(islower(G[i][j])){
						s[ G[i][j]-'a' ] = id;
					}else if(isupper( G[i][j] )){
						e[ G[i][j]-'A' ] = id;
					}
				}
			}
		}

		for(int i = 0; i < ve.size(); i++){
			vv[ve[i]].clear();
			int x = ve[i]/ w, y = ve[i] % w;

			for(int k = 0; k < 5; k++){
				int nx = x + go[k][0], ny = y + go[k][1];
				if(G[nx][ny]!='#'){
					vv[ve[i]].push_back(nx * w + ny);
				}
			}
		}
		
		if(n<=2){
			s[n] = e[n] = 0;
			vv[0].clear();
			vv[0].push_back(0);
			n++;
		}
		if(n<=1){
			s[n] = e[n] = 1;
			vv[1].clear();
			vv[1].push_back(1);
			n++;
		}
		printf("%d\n", bfs());
	}
	return 0;
}
