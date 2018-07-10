#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#define maxn 1000
#include<vector>
using namespace std;

char s[maxn];
bool failed;

struct Node{
	bool have_value; //是否被赋值过
	int v; // 节点值
	int left, right;
	Node():have_value(false), left(0), right(0){
	} // 构造函数 
};

const int root = 1;
int cnt;

Node nodes[maxn];
void create_tree(){
//	nodes[root].left = nodes[root].right = 0;
	cnt = root;
}

int createnode(){
	return ++cnt;
}

void addnode(int n, char *s){
	int len = strlen(s);
	int u = 1;
	for(int i = 0; i< len; i++){
		char c = s[i];
		if(c == 'L'){
			if(nodes[u].left == 0){
				nodes[u].left = createnode();
			}
			u = nodes[u].left;
		}else if(c == 'R'){
			if(nodes[u].right == 0){
				nodes[u].right = createnode();
			}
			u = nodes[u].right;
		} // 忽略其它情况 
	}
	
	if(nodes[u].have_value) failed = true; // 如果已经赋过值
	nodes[u].v = n;
	nodes[u].have_value = true; // 做出标记 
}

bool read_input(){
	failed = false;
	create_tree();
	while(1){
		if(scanf("%s", s)!=1) return false;
		if(strcmp(s, "()")==0) break; 
		int v;
		sscanf(&s[1], "%d", &v);
		
		addnode(v, strchr(s, ',')+1);
	}
	return true;
}

bool bfs(vector<int> &v){
	int u = root;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int i = q.front();
		q.pop();
		if(!nodes[i].have_value){
			failed = true;
			return false;
		}
		v.push_back(nodes[i].v);
		if(nodes[i].left!=0) q.push(nodes[i].left);
		if(nodes[i].right!=0) q.push(nodes[i].right);
	}
	return true;
}

void Preorder(string &s, int root){
	if(root==0) return;
	else{
		s += std::to_string(nodes[root].v) + " ";
//		printf("%s\n", s);
		Preorder(s, nodes[root].left);
		Preorder(s, nodes[root].right);
	}
}

int main(){
	while(read_input()){
//		if(failed){
//			puts("not complete");
//			continue;
//		}
//		vector<int> v;
//		if(bfs(v)){
//			int  i;
//			for(i = 0; i<v.size()-1; i++){
//				printf("%d ", v[i]);
//			}
//			printf("%d\n", v[i]);
//		}else{
//			puts("not complete");
//		}
//	char buf[maxn];
		string v="";
		Preorder(v,root);
		printf("preorder: %s\n", v.c_str());
	}
	return 0;
} 
