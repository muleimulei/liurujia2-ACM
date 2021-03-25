#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n)==1 && n)
	{
		long long ans = 0;
		vector<int> v;
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			v.push_back(a);
		}
		
		long long m = 0;
		for(int i = 0; i < n; i++)
		{
			m += v[i];
			ans += abs(m);
		}
		printf("%lld\n", ans);
	}
	return 0; 
}
