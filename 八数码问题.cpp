#include<cstdio>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
const int maxn = 3;

string  start,  dest;
map<string, int> m;

int dir[][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};


int findzero(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i]=='0') return i;
	}
}


string change(string s,int x, int y, int x1, int y1){
	s[x*maxn+y] = s[x1*maxn+y1];
	s[x1*maxn+y1] = '0';
	return s;
}

void bfs(){
	queue<string> q;
	q.push(start);
	m[start] = 0;
	
	
	while(!q.empty()){
		string c = q.front(); q.pop();
		if(c == dest) {
			printf("%d\n", m[c]);
			return;
		}else{
			int idx = findzero(c);
			int x = idx/ maxn, y = idx % maxn;
			for(int i = 0; i < 4; i++){
				int x1 = x + dir[i][0], y1 = y + dir[i][1];
				if(x1 >=0 && x1<maxn && y1>=0 && y1 <maxn){
					string b = change(c,x, y, x1, y1);
					if( !m[b] ){
						q.push(b);
						m[b] = m[c]+1;
					}
				}
			}	
			
		}
	}
	
	printf("-1\n");
}


void init(){
	m.clear();
	
	start.clear();
	for(int i = 0; i < maxn*maxn; i++){
		int c;
		scanf("%d", &c);
		start+=to_string(c);
	}
	
	dest.clear();
	for(int i = 0; i < maxn*maxn; i++){
		int c;
		scanf("%d", &c);
		dest+=to_string(c);
	}
}

int main(){
	#ifdef LOCAL
		freopen("1.in","r",stdin);
	#endif
	
	
	init();
	bfs();
	return 0;
}
