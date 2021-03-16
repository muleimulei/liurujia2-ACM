#include<set>
#include<iostream>
#include <math.h>

using namespace std;

struct Point
{
	double x,y;
	Point(double a, double b):x(a),y(b){
	}
	bool operator <(const Point &p) const
	{
		return this->x < p.x || fabs(this->x - p.x) <= 1e-5 && this->y < p.y;
	}
};

set<Point> s;
int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	#endif
	int n;
	cin>>n;
	while(n--)
	{
		s.clear();
		int y;
		scanf("%d", &y);
		for(int i = 0; i < y; i++)
		{
			int a,b;
			cin>>a>>b;
			s.insert(Point(a,b));
		}
		Point start = *(s.begin()), last = *(--s.end());
		double m = (start.x + last.x)/2;
		
		set<Point>::iterator beg = s.begin(), end = s.end();
		bool flag = 1;
		while(beg != end)
		{
			Point d = *beg;
			if(fabs(d.x - m) > 1e-5 )
			{
				Point k(2 * m - d.x, d.y);
				if(s.count(k) == 0) 
				{
					flag = 0;
					break;
				}
			}
			else
			{
				break;
			}
			beg++;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
