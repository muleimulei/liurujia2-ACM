#include<cstdio>
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
	Node *left, *right;
	Node():have_value(false), left(NULL), right(NULL){
	} // 构造函数 
};
Node* newnode(){
	return new Node();
}


Node *root;
void addnode(int v, char *s){
	int n = strlen(s);
	Node *u = root;
	for(int i =0; i< n;i++){
		char c= s[i];
		if(c == 'L'){
			if(!u->left) u->left = newnode();
			u = u->left;
		}else if(c == 'R'){
			if(!u->right) u->right = newnode();
			u = u->right;
		}
	}
	if(u->have_value) failed = true; // 已经赋过值，表明输入有误 
	u->v = v;
	u->have_value = true; //做出标记 
}

void remove_tree(Node *root){
	if(!root) return;
	remove_tree(root->left);
	remove_tree(root->right);
	delete root;
}

bool read_input(){
	failed = false;
	remove_tree(root);
	root = newnode();
	while(1){
		if(scanf("%s", s)!=1) return 0;
		if(strcmp(s, "()")==0) break;
		int v;
		sscanf(&s[1], "%d", &v); //读入节点值
		addnode(v, strchr(s, ',')+1);
	}
	return true;
}

bool bfs(vector<int> & ans){
	queue<Node *> q;
	ans.clear();
	q.push(root);
	while(!q.empty()){
		Node *u = q.front();
		q.pop();
		if(!u->have_value){
			failed = true;
			return false;
		}
		ans.push_back(u->v);
		if(u->left) q.push(u->left);
		if(u->right) q.push(u->right);
	}
	return true;
}

int main(){
	while(read_input()){
		vector<int> v;
		if(failed){
			puts("not complete");
			continue;
		}
		if(bfs(v)){
			int i;
			for(i =0; i < v.size()-1; i++){
				printf("%d ", v[i]);
			}
			printf("%d\n", v[i]);
		}else{
			puts("not complete"); 
		}
	}
	return 0;
} 
