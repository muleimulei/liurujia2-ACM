#include<cstdio>
#include<queue>
#include<map>
using namespace std;
 
int main(){
	int n, kase = 0;
	while(scanf("%d", &n)==1 && n){
		printf("Scenario #%d\n", ++kase);
		map<int, int> team;
		
		for(int i = 0; i< n; i++){
			int x;
			scanf("%d", &x);
			while(x--) {
				int num;
				scanf("%d", &num);
				team[num] = i;
			}
		}
		
		queue<int> q; //队号的队列
		queue<int> qu[1000+10];
		
		while(1){
			int x;
			char cmd[100];
			scanf("%s", cmd);
			if(cmd[0] == 'S') break;
			else if(cmd[0] == 'D'){
				int w = q.front();
				printf("%d\n", qu[w].front());
				qu[w].pop();
				if(qu[w].empty()) q.pop();
			}else if(cmd[0] == 'E') {
				scanf("%d", &x);
				int t = team[x];
				if(qu[t].empty()) q.push(t);
				qu[t].push(x);
			}
			
		}
		printf("\n");
	}
	return 0;
}
