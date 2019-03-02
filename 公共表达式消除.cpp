#include<cstdio>
#include<cstring>
#include<stack>
#include<string>
#include<map>
#include<cctype>
using namespace std;

const int maxn = 50000;
char buf[maxn], *p;
int done[maxn];
struct node{
	string str;
	int left, right, hash;
	bool operator < (const node &n) const{
		if(hash != n.hash) return hash < n.hash;
		if(left != n.left) return left < n.left;
		return right < n.right;
	}
};

node Nodes[maxn];
int cnt;
map<node, int> m;

int build_tree(){
	int n = ++cnt; // 从1开始 
	node &u = Nodes[n]; // 取出一个节点 
	u.left = u.right = -1;
	u.str = ""; u.hash = 0;

	while(isalpha(*p)){
		u.hash = u.hash * 27 + (*p-'a'+1);
		u.str.push_back(*p);
		p++;
	}

	if(*p == '('){ // (L, R)
		p++; //越过(
		u.left = build_tree();
		p++;
		u.right = build_tree();
		p++;
	}
  
	if(m.count(u)){
		cnt--;
		return m[u];
	}
	return m[u] = n;
}

void print(int root){
	if(done[root]){
		printf("%d", root);
	}else{
		done[root] = 1;
		printf("%s", Nodes[root].str.c_str());
		if(Nodes[root].left!=-1){
			putchar('(');
			print(Nodes[root].left);
			putchar(',');
			print(Nodes[root].right);
			putchar(')');
		}
	}
}

int main(){
	#ifdef LOCAL
	freopen("1.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while(T--){
		memset(done, 0, sizeof(done));
		scanf("%s", buf);
		cnt = 0;
		p = buf;
		m.clear();
		int root = build_tree();
		print(root);
		putchar('\n');
	}

	return 0;
} 
