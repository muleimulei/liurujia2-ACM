#include <stdio.h>
#include <set>
#include <string.h>
using namespace std;

int dir[][2] = 
{
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, -1},
	{0, 1},
	{1, -1},
	{1, 0},
	{1, 1}
};

char buf[10][10];
char user;

int store[10][10][10];

struct Point
{
	int x,y;
	Point(int a, int b)
	{
		this->x  = a;
		this->y = b;
	}
	bool operator < (const Point &p) const
	{
		return this->x < p.x || (this->x == p.x && this->y < p.y ) ;
	}
};
set<Point> sp;

bool judge(int x, int y, int k, char user)
{
	int nx = x+dir[k][0], ny = y + dir[k][1];
	if(nx < 0 || nx >=8 || ny < 0 || ny >=8 || buf[nx][ny] != '-')
	{
		return 0;
	}

	int p = -1 * dir[k][0], l = -1 * dir[k][1];
	
	int flag = 0;
	
	int rx = x, ry = y;
	for(;;)
	{
		rx += p, ry +=l;
		if(rx  < 0 || rx >=8 || ry < 0 || ry >= 8 || buf[rx][ry]=='-')
		{
			break;
		}
		if(buf[rx][ry] == user)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		int i = 0;
		for(; i < 10; i++)
		{
			if(store[nx][ny][i] == -1) break;
		}
		store[nx][ny][i] = k;
		sp.insert(Point(nx,ny));
		return 1;
	}
	else return 0;
}

int move(char user, bool show)
{
	sp.clear();
	memset(store, -1, sizeof(store));
		int mo = 0;
		char op;
		if(user=='W') op= 'B';
		else op='W';
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(buf[i][j] == op)
				{
					for(int k = 0; k < 8; k++)
					{
						if(judge(i, j, k, user))
						{
							mo++;
						}
					}
				}
			}
		}
		if(mo == 0)
		{
			if(show) printf("No legal move.\n");
		}else{
		//	printf("move %d\n", mo);
			
			if(!show) return mo;
			
			set<Point>::iterator beg = sp.begin(), end = sp.end();
			printf("(%d,%d)", (*beg).x+1, (*beg).y+1);
			beg++;
			while(beg != end)
			{
				printf(" (%d,%d)", (*beg).x+1, (*beg).y+1);
				beg++;
			}
			printf("\n");
		}
		
		return mo;
}

void doit(char &user, char *cmd)
{
	if(cmd[0]=='L')
	{
		move(user, true);
	}
	else if(cmd[0] == 'M')
	{
		int x = cmd[1] - '1', y = cmd[2] - '1';
		int m = move(user, false);
		if(m == 0)
		{
			//printf("未找到1\n");
			user = (user=='W')?'B':'W';
			move(user, false);
		}
		
		if(sp.count(Point(x,y)) == 0) //不会发生 
		{
			printf("未找到2\n");
		}
		
		buf[x][y]=user;
		//set<Point>::iterator beg = sp.begin(), end = sp.end();
		for(int i = 0; i < 8; i++)
		{
			if(store[x][y][i]!=-1)
			{
				int r = store[x][y][i];
				int dx = dir[r][0] * -1, dy = dir[r][1] * -1;
				
				int nx = x, ny = y;
				while(buf[nx + dx][ny + dy] !=user)
				{
					nx += dx;
					ny += dy;
					buf[nx][ny] = user;
				}
			}
		}
		
		int white = 0, black = 0;
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				if(buf[i][j] == 'W')
				{
					white ++;
				}
				if(buf[i][j] == 'B')
				{
					black++;
				}
			}
		}
		
		
		printf("Black - %2d White - %2d\n", black, white);
		
		user = (user=='W')?'B':'W';
		
	}
}



int main()
{
	#ifdef LOCAL
		freopen("1.txt", "r", stdin);
		freopen("1.out", "w",stdout);
	#endif
	int  n;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		memset(buf, 0, sizeof(buf));
		memset(store, -1, sizeof(store));
		sp.clear();
		for(int i = 0; i < 8; i++)
		{
			fgets(buf[i], 10, stdin);
			//printf("%s\n", buf[i]);
		}
		
		user = getchar(); getchar();
		char *cmd;
		do{
			char b[5] = {0};
			scanf("%s", b);
			cmd = b;
			if(cmd[0]=='Q')
			{
				for(int i = 0; i < 8; i++)
				{
					for(int j = 0; j < 8; j++)
					{
						printf("%c", buf[i][j]);
					}
					printf("\n");
				}
				getchar();
				break;
			}
			doit(user, cmd);
			
			
		}while(1);
		if(n) printf("\n");
	}
	
	return 0;
}
