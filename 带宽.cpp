/*
	不知道错哪里了 
*/ 
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<iostream>
using namespace std;

string str;
const int maxn = 10;
int G[maxn][maxn], n;
map<char, int> mm;
vector<char> vv;
int maxwid;
int vis[10];
int ans[10], A[10];

void dfs (int cur, int bw){
	if(cur == n){
		maxwid = bw;
		memcpy(ans, A, sizeof(int)*n);
	}else{
		for(int i = 0; i < n; i++){
			if(!vis[i]){
				//理想性剪枝
				int m = 0; // 
				for(int j = 0; j< n; j++){
					if(G[A[j]][i] && !vis[j]) m++; 
				}
				if(m>=maxwid) break;
				
				// 最优性剪枝
				int ok = 1;
				for(int j = 0; j < cur; j++){
					if(G[A[j]][i]){
						int b = cur - j;
						if(b >= maxwid) {
							ok = 0;
							break;
						}
						if(b>bw){ // 记录当前序列最大带宽 
							bw = b;
						}
					}
				}
				// 如果比最优带宽大 
				if(ok){
					A[cur] = i;
					vis[i] = 1;
//					printf("----before %d---\n", bw);
					dfs(cur+1, bw);
//					printf("----after %d---\n", bw);
					vis[i] = 0;
				}else break;
				// cur位置已经比maxwid大，之后更大，所以结束 
			}
		} 
	}
}

void init(){
	vv.clear();
	mm.clear();
	memset(vis, 0, sizeof(vis));
	
	for(char i = 'A'; i <= 'Z'; i++){
		if(str.find(i)!=string::npos){
			vv.push_back(i);
			mm[i] = vv.size()-1;
		}
	}
	memset(G, 0, sizeof(G)); // 将图清空 
	str+=';';
	int s = 0, pos;
	
	while((pos = str.find(';', s))!= string::npos){
		char c = str[s];
		for(int i = s+2; i < pos; i++){
			char v = str[i];
			G[mm[v]][mm[c]] = G[mm[c]][mm[v]] = 1;
		}
		s = pos+1;
	}
	maxwid = 8;
	n  = vv.size();
}

int main(){
	while(cin>>str && str!="#"){
		init(); // 初始化
		
		dfs(0, 0); //回溯 
		
		for(int i = 0; i<n;i++){
			printf("%c ", vv[ans[i]] );
		}
		printf("-> %d\n", maxwid);
	}
	return 0;
} 

