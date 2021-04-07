#include <stdio.h>

#define N 100010

int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	freopen("1.out", "w", stdout);
	#endif
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		int p[N], q[N];
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			p[i] = a;
		}
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			q[i] = a;
		}
		
		int d[N] = {0}; //记录从0号开始 到第k个缺多少油 
		
		int sum = 0;
		//预处理
		for(int i = 1; i < n; i++)
		{
			sum += p[i-1];
			int s  = sum - q[i-1];
			if(s <= 0)
			{
				d[i] = -1 * s;
			}
			sum -= q[i-1];
		}

		bool f = 0;
		int start = 0, k = start;
		
		int sum1 = 0;
		do
		{
			sum1 += p[k];
			
			if(sum1 >= q[k])
			{
				sum1 -= q[k];
				
				k = (k + 1) % n;
				
				if(k == 0) 
				{
					if(sum1>= d[start] )
					{
						f = 1;
						break;
					}
					else
					{
//						start = (start+1)%n;
//						k = start;
//						sum1 = 0;
						break;
					}
				}
			}
			else
			{
				
				start = (k+1)%n ;
				k = start;
				sum1 = 0;
			}
			
		}while(k);
		
		if(f)
		{
			printf("Case %d: Possible from station %d\n", i+1,start+1);
		}
		else
		{
			printf("Case %d: Not possible\n", i+1);
		}
	}
	
	return 0; 
} 
