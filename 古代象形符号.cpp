#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

const int maxh = 200+5, maxw = 50*4+5;
int H, W, pic[maxh][maxw], color[maxh][maxw];
char line[maxw];
char bin[256][5];
int cnt;
const char *w = "WAKJSD";


vector<int> cc;
vector< set<int> > neighbor;
int go[][2] = {
	-1, 0,
	0, -1,
	1, 0,
	0, 1
};

void dfs(int x, int y, int c){

	color[x][y] = c;
	for(int i = 0; i < 4; i++){
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if(pic[nx][ny] == pic[x][y] && x>=0 && x<H && y>=0 && y<W && color[nx][ny]==0){
			dfs(nx, ny, c);
		}
	}
}


void check_neighbor(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + go[i][0];
		int ny = y + go[i][1];
		if(pic[x][y]==0 && x>=0 && x<H && y>=0 && y<W && color[nx][ny]!=1){
			neighbor[color[x][y]].insert(color[nx][ny]);
		}
	}
}

void init(){
	strcpy(bin['0'], "0000");
	strcpy(bin['1'], "0001");
	strcpy(bin['2'], "0010");
	strcpy(bin['3'], "0011");
	strcpy(bin['4'], "0100");
	strcpy(bin['5'], "0101");
	strcpy(bin['6'], "0110");
	strcpy(bin['7'], "0111");
	strcpy(bin['8'], "1000");
	strcpy(bin['9'], "1001");
	strcpy(bin['a'], "1010");
	strcpy(bin['b'], "1011");
	strcpy(bin['c'], "1100");
	strcpy(bin['d'], "1101");
	strcpy(bin['e'], "1110");
	strcpy(bin['f'], "1111");
}

void decode(char d, int x, int y){
	char *p = bin[d];
	for(int i = 0; i< strlen(p); i++){
		pic[x][y++] = p[i]-'0';
	}
}

int main(){
	init();
	int kase;
	while(scanf("%d %d", &H, &W)==2 && H &&W){
		memset(pic, 0, sizeof(pic));
		memset(color, 0, sizeof(color));
		cc.clear();
		neighbor.clear();
		
		for(int i = 0; i < H; i++){
			scanf("%s", line);
			for(int j = 0; j<W;j++){
				decode(line[j], i+1, j*4+1);
			}
		}
		
		H += 2;
		W = W * 4 +2;
		cnt = 0;
		for(int i = 0; i<H;i++){
			for(int j = 0; j<W; j++){
				if(!color[i][j]){
					dfs(i, j, ++cnt);
					if(pic[i][j]==1){
						cc.push_back(cnt);
					}
				}
			}
		}
		neighbor.resize(cnt+2);
		
		for(int i = 0; i < H; i++){
			for(int j = 0; j < W; j++){
				if(pic[i][j]){
					check_neighbor(i, j);
				}
			}
		}
		

		string s;
		for(int i = 0; i < cc.size();i++){
			s+= w[neighbor[ cc[i] ].size()];
		}
		
		sort(s.begin(), s.end());
		printf("Case %d: ", ++kase);
		puts(s.c_str());
	}
	return 0;
}
