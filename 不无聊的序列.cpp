#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> v;
unordered_map<int, int> m,m1; //记录一个位置的数，与前面最近位置数相等的位置 
unordered_map<int, int> m2, m3; //记录一个位置的数，与后面最近位置数相等的位置

bool solve(int start, int end)
{
	if(end - start <= 1 ) return 0;

	//找出[start, end)区间内，唯一存在的数
	int ans=-1;

	int i = start, j = end-1;
	while(i <= j)
	{
		//检查i位置是否成立 
		if( (m[i] == -1 || m[i] < start) && (m2[i] == -1 || m2[i]>= end))
		{
			ans = i;
			break;
		}
		else
		{
			i++;
		}

		//检查j位置是否成立 
		if( (m[j] == -1 || m[j] < start) && (m2[j] == -1 || m2[j] >=end) )
		{
			ans = j;
			break;
		}
		else
		{
			j--;
		}
	}
	
	if( j < i) return 1;
	else
	{
		return solve(start, ans) ||  solve(ans+1, end);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	#endif
	int kase;
	scanf("%d", &kase);
	while(kase-- )
	{
		v.clear();
		m.clear();
		m1.clear();
		
		m2.clear();
		m3.clear();
		int  n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			if(m1.count(a) == 0)
			{
				m[i] = -1;
				m1[a] = i;
			}
			else
			{
				m[i] = m1[a];
				m1[a] = i;
			}
			v.push_back(a);
		}
		
		for(int i = v.size()-1; i>=0; i--)
		{
			if(m3.count(v[i]) == 0)
			{
				m2[i] = -1;
				m3[v[i]] = i;
			}
			else
			{
				m2[i] = m3[v[i]];
				m3[v[i]] = i;
			}
		} 
		
		
		if(solve(0, v.size()))
		{
			puts("boring");
		}
		else
		{
			puts("non-boring");
		}
	}
	return 0;
}
