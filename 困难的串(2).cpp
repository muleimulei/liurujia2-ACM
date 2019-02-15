#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n, L;

bool check(string s){
	int size = s.size();
	if(size==1) return 1;

	int start = size-2, end = size-1;
	int len = (end-start+1);
	if(s[start]==s[end]) return 0;
	
	while(len < (size/2 + 1) ){
		int p1 = start - len;
		int p2 = start;
		bool fg = 1;
		while(p1>=0&& p1 <start){
			if(s[p1]!=s[p2]){
				fg=0;
			}
			p1++; p2++;
		}
		if(fg) return 0;
		start--;
		len = (end-start+1);
	}
	return 1;
}

void show(string str){
	int h = str.size() / 4;
	int g = str.size() % 4;
	int b;
	if(g){
		b = h+1;
	}else b = h;
	for(int i = 0; i < h; i++){
		printf("%c%c%c%c%c", str[i*4], str[i*4+1], str[i*4+2], str[i*4+3], (i+1)%16? ( i==b-1?'\n':' ' ) :'\n');
	}
	
	if(g) {
		for(int i = str.size()-g; i<str.size(); i++){
			printf("%c", str[i]);
		}
		printf("\n");
	}
	
	printf("%d\n", str.size());
}


void dfs(int &s, string str){
//	printf("%d\n", s);
	if(s == n) {
		show(str);
	}else{
		for(int i = 0; i < L; i++){
			char c = 'A'+i;
			string e = str+c;
			if(check(e)){
				s++;
				if(s <= n){
					dfs(s, e);
				}
			}
			if(s>=n) return;
		}
	}
}

int main(){
//	freopen("1.out", "w", stdout);
	while(scanf("%d%d", &n, &L)!=EOF && n && L){
		string str = "";
		int s = 0;
		dfs(s, str);
	}
	
	return 0;
}
