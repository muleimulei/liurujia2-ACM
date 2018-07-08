#include<cstdio>
#include<map>
using namespace std;

multimap <int, int> m;

typedef multimap<int, int>::iterator IT;
int main()
{
	int n;
	while(scanf("%d", &n)==1 && n){
		m.clear();
		
		while(n--){
			int a, b;
		
			scanf("%d %d", &a, &b);
			
			pair<IT, IT> range = m.equal_range(b);
			int i = 1;
			while(range.first != range.second){
				if(range.first->first == b && range.first->second==a){
					m.erase(range.first);
					i = 0;
					break;
				}
				range.first++;
			}
			if(i) m.insert(make_pair(a,b));	
			
		}
		if(m.size()==0) puts("YES");
		else puts("NO");
	}
	return 0;
}
