#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	#ifdef LOCAL
	freopen("1.txt", "r", stdin);
	#endif
	string str;
	while(getline(cin, str))
	{
		stringstream ss(str);
		int n;
		vector<int> v,v1;
		while(ss>>n)
		{
			v.push_back(n);
		}
		v1 = v;
		int s = v.size();
		
		int cnt = 0;   //
		
		vector<int> ans;
		
		
		while(cnt < s-1)
		{
			int pos = 0;
			for(int i = 0; i < v.size()-cnt; i++)
			{
				if(v[i] > v[pos])
				{
					pos = i;
				}
			}
			
			if(pos == s-cnt-1)
			{
				cnt++;
			}
			else
			{
				if(pos==0)
				{
					ans.push_back(cnt+1);
					reverse(v.begin(), v.end()-cnt);
				}
				else
				{
					ans.push_back(s - pos);
					reverse(v.begin(), v.end() - (s - pos-1));
				}
			}
		}

		ans.push_back(0);
		for(int i = 0; i < v1.size(); i++)
		{
			if(i ==0) printf("%d", v1[i]);
			else printf(" %d", v1[i]);
		}
		printf("\n");
		for(int i = 0; i < ans.size(); i++)
		{
			if(i==0) printf("%d", ans[i]);
			else printf(" %d", ans[i]);
		}
		printf("\n");
	}
	return 0;	
} 
