#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <ctype.h>
#include <algorithm>
using namespace std;

map<long long, long long> m;

int cnt, start;
string str;
void dfs(int depth)
{
	if(str[start] == '[')
	{
		start++;
		dfs(depth + 1); //×ó×ÓÊ÷ 
		start++;
		dfs(depth + 1); //ÓÒ×ÓÊ÷ 
		start++;
		return;
	}
	
	long long num = 0;
	while(start < str.size() && isdigit(str[start]))
	{
		num = num * 10 + (str[start] - '0');
		start++; 
	} 
	cnt++;
	m[num << (depth)]++;
}

int main()
{
	#ifdef LOCAL
		freopen("1.txt", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	while(n--)
	{
		m.clear();
		cnt = 0;
		cin>>str;
		start = 0;
		dfs(0);
		
		map<long long, long long>::iterator beg = m.begin(), end = m.end();
		long long t = -1;
		while(beg != end)
		{
			t = max(t, (*beg).second);
			beg++;
		}
		printf("%lld\n", cnt - t);
	}
	return 0;	
}
