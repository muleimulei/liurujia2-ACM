#include<queue>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
const int maxt = 100 + 10;

int main(){
	int t, kase = 0;
	while(scanf("%d", &t) == 1 && t){
		printf("Scenario #%d\n", ++kase);
		// 记录所有人的团队编号
		map<int, int> team;

		for(int i = 0; i<t;i++){
			int s,x;
			cin>>s;
			while(s--){
				scanf("%d", &x);
				team[x] = i;
			}
		}

		// 模拟
		queue<int> q, q2[maxt];
		while(1){
			int x;
			char cmd[10];
			scanf("%s", cmd);
			if(cmd[0] == 'S') break;
			if(cmd[0] == 'D'){
				int c = q.front();
				printf("%d\n", q2[c].front());
				q2[c].pop();
				if(q2[c].size() == 0){
					q.pop(); // 团队全体出队列
				}
			}else if(cmd[0] == 'E'){
				scanf("%d", x);
				int t = team[x];
				if(q2[t].empty()) q.push(t);
				q2[t].push(x);
			}
		}
		
		printf("\n");
	}
	return 0;
}
