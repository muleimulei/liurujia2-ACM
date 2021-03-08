#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>

//水平0 垂直1 
int maze[2][11][11][10];

//判断水平与竖直 
bool judge(int d, int s1, int s2, int w)
{
	if(w == 1)
	{
		if(maze[d][s1][s2][w] == 1) return true;
		else  return 0;
	}
	else
	{
		if(maze[d][s1][s2][w] != -1) 
		{
			if(maze[d][s1][s2][w]==0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if(d==0 && maze[d][s1][s2+w-1][1]==1 && judge(d, s1, s2, w-1) || d==1 && maze[d][s1+w-1][s2][1]==1 && judge(d, s1, s2, w-1)) 
		{
			return 1;
		}else{
			return 0;
		}
	}
}

void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n-1; j++)
		{
			
			for(int w = n - j;  w >=1; w--)
			{
				
				if(judge(0, i, j, w))
				{
					maze[0][i][j][w] = 1;
				}else
				{
					maze[0][i][j][w] = 0;
				}
				
				if(judge(1, j, i, w))
				{
					maze[1][j][i][w] = 1;
				}else
				{
					maze[1][j][i][w] = 0;
				}
			}
		}
	}

}



int main()
{
//	freopen("1.txt", "r", stdin);
	int n, m;
	int kase = 0;
	while(scanf("%d%d", &n, &m)==2)
	{
		memset(maze, -1, sizeof(maze)); // -1未计算  1 有变 0 无边 
		char d;
		int r,k;
		while(m--)
		{
			getchar();
			scanf("%c%d%d", &d, &r, &k);
			if(d == 'H')
			{
				maze[0][r][k][1] = 1;
			}
			else if(d == 'V')
			{
				maze[1][k][r][1] = 1;
			}
		}
		init(n);
		int c[10] = {0};
		for(int i = 1; i < n; i++)
		{
			for(int j = 1; j < n; j++)
			{
				int s1 = i, s2 = j;
				for(int w = std::min(n-i, n-j); w>=1; w--)
				{
//					int e1 = i + w, e2 = j + w;
					
					if(maze[0][i][j][w]==1 && maze[0][i+w][j][w] == 1 && maze[1][i][j][w]==1 && maze[1][i][j+w][w]==1)
					{
						c[w]++;
					}
				}
			}
		}
		if(kase) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", ++kase);
		int has = 0;
		for(int i = 1; i < n; i++)
		{
			if(c[i])
			{
				has = 1;
				printf("%d square (s) of size %d\n",c[i], i);
			}
		}
		if(!has)
		{
			printf("No completed squares can be found.\n");
		}
	}
	
	return 0;
}
