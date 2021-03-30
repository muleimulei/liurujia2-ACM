#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map> 
using namespace std;
vector<int> v;

int solve(int start, int end)
{
	if(end - start == 1) return 1;
	
	int m = start + (end - start) / 2;
	int L = solve(start, m), R = solve(m, end);
	
	int p = max(L, R);
//	int p = -1;
	
	map<int,int> s1, s2; //用于判重
	
	int r, n1 = 0, n2 = 0;
	for(r = m-1; r>=start; r--)
	{
		if(s1.count(v[r]) == 0)
		{
			s1[v[r]] = r;
			n1++;
		}else break;
	}
	
	for(r = m; r < end; r++)
	{
		if(s2.count(v[r]) == 0)
		{
			s2[v[r]] = r;
			n2++;
		}else break;
	}
	
	
	int k = m+n2;
//	
//	if(start == 0 && end == v.size())
//	{
//		printf("hello\n");
//	}
	
	for(r = m-1; r >= m - n1; r--)
	{
		
		if(s2.count(v[r]) == 0)
		{
			p = max(p, k - r);
		}else
		{
			int pos = s2[v[r]];
			if(pos< k)
			{
				k = pos;
				p = max(p, k - r);
			}else
			{
				p = max(p, k-r);
			}
		}
	}
	
	return p;
}

int main()
{
#ifdef LOCAL
	freopen("1.txt", "r", stdin);
//	freopen("1.out", "w", stdout);
#endif
	int kase;
	scanf("%d", &kase);
	while(kase--)
	{
		int n;
		scanf("%d", &n);
		if(n==0) 
		{
			printf("0\n");continue; 
		}
		v.clear();
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}
		
		printf("%d\n", solve(0, v.size()));
	}
	return 0; 
}

/*
特殊样例
 1
25

25
21
15
8
22
27
13
11
6
24
23
1

25
20
7
28
13
1
15
17


*/
