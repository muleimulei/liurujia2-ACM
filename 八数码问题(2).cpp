#include<cstdio>
#include<cstring>

typedef int State[9]; // 定义 “状态”类型 
const int maxstate = 1000000;
State st[maxstate], goal; // 状态数组，所有状态都保存在这里

int dist[maxstate]; // 距离数组
// 如果需要打印方案，可以加一个“父亲编号”数组 int fa[maxstate]

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

//BFS 返回目标状态在st数组下标

const int hashsize = 1000003;
int head[hashsize], next[maxstate];

void init_lookup_table(){
	memset(head, 0, sizeof(head));
}

int hash(State &s){
	int v = 0;
	for(int i = 0; i < 9; i++) v = v*10+s[i]; // 把9个数字组合成9位数 
	return v % hashsize; //确保hash函数值是不超过hash表的大小的非负整数 
}

int try_to_insert(int s){
	int h = hash(st[s]);
	int u = head[h]; // 从表头开始查找链表
	while(u){
		if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
		u = next[u];
	}
	next[s] = head[h];
	head[h] = s;
	return 1;
}


int bfs(){
	init_lookup_table(); // 初始化查找表 
	int front = 1, rear = 2; //不使用下标0，因为0被视为
	while(front < rear){
		State &s = st[front]; //用引用简化代码
		if(memcmp(s, goal, sizeof(s))==0) return front; // 找到目标状态，成功返回
		int z;
		for(z = 0; z < 9; z++) if(!s[z]) break;
		int x = z / 3, y = z % 3; // 获取行列编号
		for(int d = 0; d < 4; d++){
			int newx = x + dx[d], newy = y + dy[d];
			if(newx>=0 && newx < 3 && newy>=0 && newy<3) {
				State &t = st[rear];
				memcpy(&t, &s, sizeof(t));
				t[3 * newx + newy] = s[z];
				t[z] = s[3 * newx + newy];
				dist[rear] = dist[front] +1;
				if(try_to_insert(rear)) {
					rear++;
				}
			}
		} 
		front++;
	} 
	return 0;
} 


int main(){
	
	#ifdef LOCAL
		freopen("1.in","r",stdin);
	#endif
	
	for(int i = 0; i<9; i++) scanf("%d", &st[1][i]); // 起始状态
	for(int i = 0; i<9; i++) scanf("%d", &goal[i]); // 目标状态
	
	int ans = bfs();
	if(ans>0) printf("%d\n", dist[ans]);
	else printf("-1\n");
	
	return 0;
}
