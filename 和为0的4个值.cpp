#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	#endif
	int kase;
	scanf("%d", &kase);
	while(kase--)
	{
		vector<long long> v[4];
		//unordered_map<long long, long long> hash1, hash2;
		
		vector<long long> v1;
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				long long a;
				scanf("%lld", &a);
				v[j].push_back(a);
			}
		}
		
		for(int i = 0;i < v[0].size(); i++)
		{
			for(int j = 0; j < v[1].size(); j++)
			{
				long long ans = v[0][i] + v[1][j];
				
				v1.push_back(ans);
			}
		}
		sort(v1.begin(), v1.end());
		
		
		
		long long ans = 0;
		
		
		for(int i = 0; i < v[2].size(); i++)
		{
			for(int j = 0; j < v[3].size(); j++)
			{
				ans += (upper_bound(v1.begin(), v1.end(), -v[2][i] - v[3][j]) - lower_bound(v1.begin(), v1.end(), -v[2][i] - v[3][j]) );
			}
		}

//		for(int i = 0; i < v1.size(); i++)
//		{
//			for(int j = 0; j < v2.size(); j++)
//			{
//				long long r = v1[i] + v2[j];
//				if( r == 0)
//				{
//					ans += (hash1[v1[i]] * hash2[v2[j]]);
//				}else if(r > 0)
//				{
//					break;
//				}
//			}
//		}
		printf("%lld\n", ans);
		if(kase) printf("\n");
	}
	return 0;
}
/*
1
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
*/
