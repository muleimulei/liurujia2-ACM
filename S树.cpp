#include<stdio.h>
#include <iostream>
#include<map>
#include <string> 
#include <vector>

using namespace std;
map<string, int> m;

vector<string> v;

int main()
{
	#ifdef LOCAL
		freopen("1.txt", "r", stdin);
	#endif
	int n,kase=0;
	while(cin>>n && n)
	{
		printf("S-Tree #%d:\n", ++kase);
		m.clear();
		v.clear();
		for(int i =0 ; i < n; i++)
		{
			string s;
			cin>>s;
			v.push_back(s);
		}
		string code;
		cin>>code;
		int c;
		cin>>c;
		
		string ans;
		for(int i = 0; i < c; i++)
		{
			string s;
			cin>>s;
			m.clear();
			for(int j = 1; j <= s.size(); j++)
			{
				string k = string("x") + char('0'+j);
				m[k] = s[j-1]-'0'; //得到映射 
				//cout<<k<<endl;
			}
			//计算答案 
			int start = 0, end = code.size();
			for(int i = 0; i < v.size()-1; i++)
			{
				int c = m[v[i]];
				if(c == 0)
				{
					end = end - (end-start)/2;
				}else
				{
					start += (end-start)/2;
				}
			}
			
			if(m[v[v.size()-1]]== 0)
			{
				ans += code[start];
			}else
			{
				ans += code[end-1];
			}
		}
		cout<<ans<<endl<<endl;
	}
	
	return 0;
} 
