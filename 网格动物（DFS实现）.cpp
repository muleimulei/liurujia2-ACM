#include <cstdio>
#include<set>
#include<algorithm>
using namespace std;

struct Cell{
	int x, y;
	Cell(int x = 0, int y = 0):x(x),y(y){
	}
	bool operator < (const Cell & s) const{
		return x < s.x || (x == s.x && y<s.y);
	}
}; 

const int maxn = 10;
typedef set<Cell> Pic;
set<Pic> allPic[maxn+1];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int ans[maxn+1][maxn+1][maxn+1];


inline Pic normalize(const Pic &c){
	Pic p;
	int dx = c.begin()->x, dy = c.begin()->y;
	for(Pic::const_iterator d = c.begin(); d!=c.end(); d++){
		dx = min(dx, d->x);
		dy = min(dy, d->y);	
	}
	for(Pic::const_iterator d = c.begin(); d!=c.end(); d++){
		p.insert(Cell(d->x - dx, d->y - dy));
	}
	return p;
} 

inline Pic rotate(const Pic &c){
	Pic p0;
 	for(Pic::const_iterator d = c.begin(); d!=c.end(); d++){
 		p0.insert(Cell( d->y, -d->x));	
	}
	return normalize(p0);
}

inline Pic flip(const Pic &c){
	Pic p0;
	for(Pic::const_iterator d = c.begin(); d!=c.end(); d++){
		p0.insert(Cell(d->x, -d->y));
	}
	return normalize(p0);
}

bool judge(int c, Pic p0){
	p0 = normalize(p0);
	
	for(int i = 0; i< 4; i++){
		if(allPic[c].count(p0)) return 0;
		p0 = rotate(p0);
	}
	
	p0 = flip(p0);
	for(int i = 0; i<4; i++){
		if(allPic[c].count(p0)) return 0;
		p0 = rotate(p0);
	}
//	return 1;
	allPic[c].insert(p0);
	return 1;
}

void show(Pic &c){
	for(Pic::const_iterator v = c.begin(); v!=c.end(); v++){
		printf("%d %d\n", v->x, v->y);
	}
	printf("%d++++\n", c.size());
}

void dfs(int c, Pic p){
	if(c > maxn) return;
	if(!judge(c, p)) return; // 之前遍历过，则退出 
	Pic p0 = p;

	for(Pic::const_iterator d = p.begin(); d!=p.end(); d++){
		for(int i = 0; i<4; i++){
			Cell f(d->x + dx[i], d->y+dy[i]);
			if(!p0.count(f)){
				p0.insert(f);
				
				dfs(c+1, p0); //递归进入下一层 
				p0 = p;
			}
		}
	}
}

void generate(){
	// 从第一层进行DFS遍历 
	Pic p;
	p.insert(Cell(0, 0));
	dfs(1, p);
	
//	printf("Hello\n");
	// 打表 
	for(int n = 1; n<=maxn; n++){
		for(int w = 1; w<=maxn; w++){
			for(int h = 1; h<=maxn; h++){
				int cnt = 0;
				for(set<Pic>::const_iterator s = allPic[n].begin(); s!=allPic[n].end(); s++){ // 遍历每一层的个数 
					int maxX = 0, maxY = 0;
					for(Pic::const_iterator v = s->begin(); v!=s->end() ; v++){
						maxX = max(maxX, v->x );
						maxY = max(maxY, v->y);
					}
					if(min(maxX, maxY) < min(w, h) && max(maxX, maxY) < max(w, h) ){
						cnt++;
					}
				}
				ans[n][w][h] = cnt;
			}
		}
	}
}

int main(){
	#ifdef LOCAL
	freopen("1.in", "r", stdin);
	#endif
	generate();
	int n, w, h;
	while(scanf("%d %d %d", &n, &w, &h)==3){
		printf("%d\n", ans[n][w][h]);
	}
	return 0;
}
