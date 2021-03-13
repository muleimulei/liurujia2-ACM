#include<stdio.h>
#include<queue>
#include <string.h>
using namespace std;
#define N 30

int maze[N][N];
int m,n,k;
int mark[N][N][N]; //标记在某个点，经过了几个障碍物，用于减少重复查找，否则会超时 


int dir[][2] = 
{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

struct Point
{
	int x,y,o; //记录 
	int d; //步长 
	Point(int a, int b, int c, int d):x(a),y(b),o(c),d(d){
	}	
};

int BFS()
{
	queue<Point> q;
	q.push(Point(0, 0, 0, 0));
	mark[0][0][0] = 1;
	while(!q.empty())
	{
		Point s = q.front(); q.pop();
		if(s.x == m-1 && s.y == n-1)
		{
			return s.d;
		}
		
		for(int i = 0; i < 4; i++)
		{
			int nx = s.x + dir[i][0], ny = s.y + dir[i][1];
			
			if(nx <0 || nx >=m || ny < 0 || ny >=n) continue; //如果已越界 
			
			if(maze[nx][ny] == 1) //如果为障碍物 
			{
				if(s.o + 1 > k) continue; //如果超出连续障碍物数 
				if(mark[nx][ny][s.o + 1] == 1) continue; //如果在该点处，通过的连续障碍物数 状态之前已经 加入队列，则减枝该状态，避免重复查找 
				else {
					q.push(Point(nx, ny, s.o+1, s.d+1));
					mark[nx][ny][s.o+1] = 1;
				}
			}
			else
			{
				if(mark[nx][ny][0] == 1) continue; //同上 
				q.push(Point(nx, ny, 0, s.d+1));
				mark[nx][ny][0] = 1;
			}
		}
	}
	return -1;
}

int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	#endif
	int kase;
	scanf("%d", &kase);
	while(kase--)
	{
		scanf("%d%d%d", &m, &n, &k);
		memset(mark, 0, sizeof(mark));
		for(int i = 0;i < m; i++)
		{
			for(int j = 0; j < n;j ++)
			{
				scanf("%d", &maze[i][j]);
			}
		}
		
		printf("%d\n", BFS());
	}
	return 0;
}
