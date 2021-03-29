#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm> 
#include <vector>
#include <math.h>
using namespace std;

struct Point
{
	int x,y,r;
	Point(int a, int b, int c):x(a),y(b),r(c){
	}
	double angle;
	
	bool operator < (const Point p) const
	{
		return this->angle < p.angle;
	}
};

vector<Point> v; //用于存储所有的点 


//右手定则，（向量差乘）判断b是否在a的正向， 
bool isleft(Point a, Point b)
{
	return a.x * b.y - b.x * a.y >= 0; 
}

int main()
{
#ifdef LOCAL
	freopen("1.txt", "r", stdin);
#endif
	int n;
	while(scanf("%d", &n)==1 && n)
	{
		v.clear();
		for(int i = 0; i < n; i++)
		{
			int x,y,r;
			scanf("%d%d%d", &x, &y, &r);
			v.push_back(Point(x,y,r));
		}
		
		int ans = 0;
		for(int i = 0; i < v.size(); i++) //遍历所有基准点 
		{
			vector<Point> v1; //用于存储除基准点外其它点相对于基准点的点，主要计算极角 
			for(int j = 0; j < v.size(); j++)
			{
				if(i == j) continue; //过滤掉基准点
				Point p(v[j].x - v[i].x, v[j].y - v[i].y, v[j].r);
				if(p.r == 0) //基于 基准点 做对称，（左边黑点 + 右边百点 == 左边黑点 + 对称到左边的点），这样只需要根据每个基准点，计算每个基准点一般的点数，求其最大值，就是答案 
				{
					p.x = -1 * p.x;
					p.y = -1 * p.y;
				}
				p.angle = atan2(p.y, p.x); //atan2 的取值范围【-pi, pi】, 
				v1.push_back(p);
			}
			sort(v1.begin(), v1.end());
			
			int L = 0, R = 0, cnt = 2; // cnt == 2，基准线上的两点 
			
			int k = v1.size();
			//逆时针遍历 
			while(L < k)
			{
				if(L == R)
				{
					R = (R+1)%k;
				}
				while(L != R && isleft(v1[L], v1[R])) 
				{
					R = (R+1)%k;
					cnt++;
				}
				ans = max(ans, cnt);
				L++; 
				cnt--; //将L加一，那么个数减一，再次根据新点计算点个数 
			}
		}
		
		printf("%d\n", ans);
	}
}
/*
3
0 0 0
0 1 0
2 2 1
4
0 0 0
0 4 0
4 0 0
1 2 1
7
-1 0 0
1 2 1
2 3 0
2 1 1
0 3 1
1 4 0
-1 2 0
0
*/
