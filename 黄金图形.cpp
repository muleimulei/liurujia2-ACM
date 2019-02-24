#include<cstdio>
#include<cstring>
#include<vector>
#include<map> 
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;
const int maxn = 60;

// 记录障碍物坐标与个数 
int x[maxn], y[maxn], bnum, len;

int sum[22];

vector<string> v;

const char dirs[] = "nesw";

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct node{
	int x, y;
	int dir;
	node (int x = 0, int y = 0, int  dir = 0): x(x),y(y),dir(dir){
	}
	bool operator < (const node &d)const{
		return x < d.x || (x==d.x && y<d.y);
	}
};
map<node, int> m;

bool check(int oldx, int oldy ,int newx, int newy){
	for(int i = 0; i < bnum; i++){
		if(x[i] == oldx && x[i] == newx){
			if( newy == y[i] ) return 1;
			if(( y[i] - oldy ) * ( y[i] - newy ) < 0 ){
				return 1;
			}
		}
		if(y[i] == oldy && newy == y[i]){
			if(newx== x[i]) return 1;
			if((x[i]-oldx)*(x[i] - newx)<0) return 1;
		}
	}
	return 0;
}


bool walk(node &d, int dir ,int s, node &dest){
		int x = d.x + dx[dir] * s;
		int y = d.y + dy[dir] * s;
		
		if(check(d.x, d.y, x, y)){
			return 0;
		}else{
			dest.dir = dir;
			dest.x = x;
			dest.y = y;
			return 1;
		}
}

void dfs(node d, int dir, int s, string str){ // d当前位置，dir方向，s步数 
	node dest;
	bool flag = walk(d, dir , s, dest);
	if(!flag || m[dest]) return;
	if(abs(dest.x) + abs(dest.y) > sum[len] - sum[s]) return;
	
	if(flag && s== len){
		if(dest.x == 0 && dest.y == 0){
			v.push_back(str);
		}
		return;
	}
	if(flag){
		m[dest] = 1;
		dfs(dest, (dir+1) % 4, s+1, str+dirs[(dir+1) % 4]);
		dfs(dest, (dir+3) % 4, s+1, str+dirs[(dir+3) % 4]);
		m[dest] = 0;
	}
}

int main(){
	#ifdef LOCAL
		freopen("1.in", "r",stdin);
	#endif
	
	int T;
	scanf("%d", &T);
	while(T--){
		v.clear();
		m.clear();
		memset(sum, 0,sizeof(0));
		for(int i = 1; i <= 20; i++) sum[i] = (sum[i-1]+i); 
		scanf("%d", &len);
		scanf("%d", &bnum);
		for(int i = 0; i<bnum; i++){
			scanf("%d %d", &x[i], &y[i]);
		}
		
		string str = "";
		for(int i = 0; i < 4; i++){
			dfs(node(0, 0, i), i, 1, str+dirs[i]);
		}
		
		sort(v.begin(), v.end());
		for(int i = 0; i< v.size(); i++){
			puts(v[i].c_str());
		}
		printf("Found %d golygon(s).\n\n", v.size());
	}
	return 0; 
} 
