#include<cstdio>
#include<cstring>
#include<queue>
struct node{
	int x, y, b;
	node(int x = 0, int y = 0, int b = 0): x(x),y(y),b(b){
	}
};

bool operator == (node &a, node &b){
	return a.x == b.x && a.y == b.y;
}

int go[][2] = {
	1, -2,
	2, -1,
	2, 1,
	1, 2,
	-1, 2,
	-2, 1,
	-2, -1,
	-1, -2
};

char start[10], end[10];
bool mark[10][10];
node s,e;
std::queue<node> q;



void solve(){
	q.push(s);
	mark[s.x][s.y] = 1;
	while(!q.empty()){
		node n = q.front(); q.pop();
		if(n==e){
			printf("To get from %s to %s takes %d knight moves.\n", start, end, n.b );
			return;
		}else{
			for(int i = 0; i < 8; i++){
				int x = n.x + go[i][0],y = n.y + go[i][1];
				if(x<0 || x>7 || y<0 || y>7 || mark[x][y]) continue;
				node v(x, y, n.b+1);
				mark[x][y] = 1;
				q.push(v);
			}
		}
	}
}

int main(){
	while(scanf("%s", start)!=EOF){
		scanf("%s", end);
		while(!q.empty()){
			q.pop();
		}
		memset(mark, 0, sizeof(mark));
		s = node( 8 - (start[1] - '0' ), start[0]-'a', 0);
		e = node( 8 - (end[1] - '0' ), end[0]-'a' , 0);
		solve();
	}
	
	return 0;
}
