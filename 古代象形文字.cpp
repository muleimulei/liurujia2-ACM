#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#define maxn 1000+10
int h, w;
char maze[maxn][maxn];
int idx[maxn][maxn];

char buf[100][100];


int pp[100], num=0;

void init(){
	num = 0;
	memset(idx,0, sizeof(idx));
	memset(pp, 0, sizeof(pp));
	for(int i = 0; i < 8 * w +2; i++){
		maze[0][i] = '0';
		maze[h+1][i] = '0';
	}
	for(int i = 0; i <h +2; i++){
		maze[i][0] = '0';
		maze[i][8*w+1] = '0';
	}
}
int s[16][4]=
{
    {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {0, 0, 1, 1},
    {0, 1, 0, 0}, {0, 1, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1},
    {1, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 1},
    {1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}
};//十六进制对应的二进制

void addtomaze(int x, int j, char *buf){
	int h = x+1,l1 = j * 8+1, num = 8;
	for(int i = 0; i < 2; i++){
		char c = buf[i];
		int j;
		if(isdigit(c)){
			j = c - '0';
		}else{
			j = c - 'a' + 10;
		}
		int *p = s[j];
		for(int l =0; l<4;l++ ){
			maze[h][l1++] = p[l]+'0';
		}
	}
}

void dfswall(int x, int y){
	if(x<0 || x >= h +2 || y <0 || y>= w*8+2) return;
	if(maze[x][y]=='0' && idx[x][y] == 0){
		idx[x][y] = 2;
	}
	dfswall(x-1, y);
	dfswall(x+1, y);
	dfswall(x, y-1);
	dfswall(x, y+1);
}

void dfswhite(int x, int y){
	if(x<0 || x >= h +2 || y <0 || y>= w*8+2) return;
	if(maze[x][y] == '0' && idx[x][y]==0){
		idx[x][y] = 1;
	}
	dfswhite(x-1, y);
	dfswhite(x+1, y);
	dfswhite(x, y-1);
	dfswhite(x, y+1);
}

void dfsblack(int x, int y){
	if(x<0 || x >= h +2 || y <0 || y>= w*8+2) return;
	if(maze[x][y] == '1' && idx[x][y]==0){
		idx[x][y] = 3;
	}
	if(maze[x][y] == '0' && idx[x][y] == 0){
		dfswhite(x, y);
		pp[num]+=1;
	}
	
	dfsblack(x-1, y);
	dfsblack(x+1, y);
	dfsblack(x, y-1);
	dfsblack(x, y+1);
} 

void show(){
	for(int i = 0; i < h+2; i++){
		for(int j = 0; j < 8*w+2; j++){
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int kase = 0;
	while(scanf("%d %d", &h, &w)!=EOF && h && w){
		char buf[10];
		init();
		
		for(int i = 0; i < h; i++){
			for(int j = 0; j< w;j++){
				scanf("%s", buf);
				addtomaze(i, j,buf);
			}
		}
//		show();
		
		// 找到所有的外部白色,将其标记为2 
		dfswall(0, 0); 
		
		for(int i = 1; i<= h; i++){
			for(int j = 1; j <= 8*w; j++){
				if(maze[i][j]=='1' && idx[i][j]==0){
					dfsblack(i, j); // 找到所有的黑色
					num++;
				}
			}
		}
		char s[100];
		memset(s, 0, sizeof(s));
		int b = 0;
		for(int i = 0; i<num;i++){
			int k = pp[i];
			switch (k)
				{
				case 1: s[b++] = 'A';break;
				case 3: s[b++] = 'J';break;
				case 5: s[b++] = 'D';break;
				case 4: s[b++] = 'S';break;
				case 0: s[b++] = 'W';break;
				case 2: s[b++] = 'K';break;
				}
		}
		std::sort(s,s+b);
		printf("Case %d: %s\n", ++kase, s);
	}
	
	return 0;
} 
