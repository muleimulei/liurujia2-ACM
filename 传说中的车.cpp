#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


struct pos
{
	int xl, yl;
	int xr, yr;
	
	pos(int a, int b, int c, int d):xl(a),yl(b),xr(c),yr(d){
	}
};

struct dis
{
	int no;
	int s,e;
	dis(int no, int a, int b):no(no),s(a),e(b){
	}
};

struct ans
{
	int no;
	int p;
	ans(int a, int b):no(a), p(b){
	}
};



bool cmp(const dis a, const dis b)
{
	return a.e < b.e || a.e == b.e && a.s < b.s;
}




bool cmp2(const ans a, const ans b)
{
	return a.no < b.no;
}



int main()
{
	#ifdef LOCAL
		freopen("1.txt", "r", stdin);
	#endif
	int n;
	while(scanf("%d", &n)==1 && n)
	{
	//	vector<pos> v; //原始数据 
		
		vector<dis> v1; //记录列跨度 
		vector<dis> v2; //记录行跨度 
		
		
		int col[5010] = {0}; ////标记哪列位置被占了  
		int row[5010] = {0}; //标记哪行被占 
		
		vector<ans> A1;
		vector<ans> A2;
		
		
		for(int i = 0; i < n; i++)
		{
			int a,b,c,d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
		//	v.push_back(pos(a,b,c,d));
			v2.push_back(dis(i, a, c));
			v1.push_back(dis(i, b,d));
		}
		
		sort(v1.begin(), v1.end(), cmp); //排序 
		
		bool flag = 1;
		
		for(int i = 0; i < n; i++)
		{
			dis k = v1[i];
			int j;
			for(j = k.s; j <=k.e; j++)
			{
				if(col[j] == 0) break;
			}
			if(j > k.e)
			{
				flag = 0;
				break;
			}
			else
			{
				col[j] = 1;
				A1.push_back(ans(k.no, j));
			}
		}
	
		if(flag)
		{
			sort(A1.begin(), A1.end(), cmp2);
			
			sort(v2.begin(), v2.end(), cmp);
			
			for(int i = 0; i < n; i++)
			{
				dis k = v2[i];
				int j = 0;
				for(j = k.s; j <= k.e; j++)
				{
					if(row[j] == 0) break;
				}
				if(j > k.e)
				{
					flag = 0;
					break;
				}
				else
				{
					row[j] = 1;
					A2.push_back(ans(k.no, j));
				}
			}
			if(flag)
			{
				sort(A2.begin(), A2.end(), cmp2);
				for(int i = 0; i < n; i++)
				{
					printf("%d %d\n", A2[i].p, A1[i].p);
				}
			}
			else
			{
				puts("IMPOSSIBLE");
			}
		}
		else
		{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}
