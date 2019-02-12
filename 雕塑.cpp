
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 980;
bool G[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];

int go[][3] = {
	-1, 0, 0,
	1, 0, 0,
	0, -1, 0,
	0, 1, 0,
	0, 0, -1,
	0, 0, 1
};

LL n1, n2; // n1表面积，n2体积
int minx, miny, minz, wx,wy,wz;
int xw,yw,zw;

void dfs(int x, int y, int z){
//	if(G[x][y][z]==0 && vis[x][y][z]==0){
		n2++;
		vis[x][y][z] = 1;
//	}
	for(int i = 0; i<6; i++){
		int s1 = x+go[i][0], s2 = y+go[i][1], s3 = z+go[i][2];
		if(vis[s1][s2][s3]==1 ||s1<minx || s2<miny || s3<minz || s1 >= xw || s2>= yw || s3>= zw) continue; //越界
		if(G[s1][s2][s3]==1 && G[x][y][z]==0){
			n1++;
			continue;
		}
		dfs(s1,s2,s3);
	}
}

void floodfill(){
	if(vis[minx][miny][minz]==0 && G[minx][miny][minz]==0){
		dfs(minx, miny, minz);
	}
}

void solve(){
	// floodfill 空气;
	floodfill();
	LL v = (LL)wx * wy * wz  - n2;
	printf("%lld %lld\n", n1, v);
}

int main(){
	#ifdef LOCAL
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif
	
	int T;
	scanf("%d", &T);
	while(T--){
		memset(G, 0, sizeof(G));
		memset(vis, 0, sizeof(vis));
		n1 = n2 = 0;
		minx = miny = minz = maxn;
		wx = wy = wz = 0;
		xw = yw = zw = 0;
		
		
		int e;
		scanf("%d", &e);
		while(e--){
			int x0, y0, z0, x,y,z;
			scanf("%d%d%d%d%d%d", &x0, &y0, &z0, &x, &y, &z);
			
			minx = min(minx, x0);
			miny = min(miny, y0);
			minz = min(minz, z0);

			wx = max(wx, x+x0);
			wy = max(wy, y+y0);
			wz = max(wz, z+z0);
			
			for(int i = 0; i < x; i++){
				for(int j = 0; j < y; j++){
					for(int k = 0; k < z; k++){
						G[x0+i][y0+j][z0+k] = 1;
					}
				}
			}
		}
		wx = wx - minx;
		wy = wy - miny;
		wz = wz - minz;
		
		minx--;miny--;minz--;
		wx+=2; wy+=2; wz += 2;
		
		xw = minx + wx;
		yw = miny + wy;
		zw = minz + wz;
		solve();
	}
	return 0;
}
