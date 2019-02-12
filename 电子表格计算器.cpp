#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
const int INF = 0x3fffffff;

const int maxn = 30;

int m, n, t;

map<string, string> G;
map<string, int> ans;
map<string, int> c;

bool isnum(const string &s){
	for(int i = 0; i < s.size(); i++){
		if((s[i]>='A' && s[i]<='Z') ) return false;
	}
	return true;
}

bool solve(int &sum, string pos);

string getpos(int i, int j){
	return string("") + (char)('A'+i) + to_string(j);
}

bool cc(int &sum, string pos){
	if(c[pos]==1) return false;
	else{
		if(c[pos]==2){
			sum = ans[pos];
			return true;
		}else if(c[pos]==0){
			int m = 0;
			if(solve(m, pos)){
				ans[pos] = m;
				c[pos] = 2; 
				sum = m;
				t--;
				return true;
			}else return false;
		}
	}
}


bool solve(int &sum, string pos){
	c[pos] = 1;
	string val = G[pos], s;
	
	string h = val.substr(0, 2);
		int d;
		if(cc(d, h)){
			sum += d;
		}else{
			return false;
		}
	int i = 2, j = i+1;
	
	while(j<val.size()){
		while(j<val.size() && (val[j]!='-' && val[j]!='+')) {
			j++;
		}
		if(val[i]=='+'){
			s = val.substr(i+1, j-i-1);
			if(isnum(s)){
				sum += atoi(s.c_str());
			}else {
				int t ;
				if(cc(t, s)){
					sum += t;
				}else{
					return false;
				}
			}
		}else if(val[i]=='-'){
			s = val.substr(i+1, j-i-1);
			if(isnum(s)){
				sum -= atoi(s.c_str());
			}else {
				int t;
				if(cc(t, s)){
					sum -= t;
				}else{
					return false;
				}
			}
		}
		i = j;
		j++;
	}
	
	return true;
}


int main(){
//	int kase = 0;
	while(cin>>m>>n && m && n){
//		if(kase) printf("\n");
//		kase++;
//		
		G.clear();
		c.clear(); // 0--未遍历，1--递归中， 2--递归完成 
		ans.clear();
		t = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n;j++){
				string s;
				cin>>s;
				string pos = getpos(i, j);
				G[pos] = s;
//				cout<<pos<<"   "<<s<<endl;
//				vG[s] = pos;
				if(isnum(s)){
					ans[pos] = atoi(s.c_str());
					c[pos] = 2;
				}else{
					ans[pos] = INF;
					t++;
					c[pos] = 0;
				}
//				cout<<c[pos]<<endl;
			}
		}
		
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				string pos = getpos(i, j);
				string val = G[pos];
				int sum = 0;
//				c.clear();
				if(c[pos]==0){
					if(solve(sum, pos) ){
						c[pos] = 2;
						ans[pos] = sum;
						t--;
					}
				}
			}
		}
		
		if(t){
			for(int i = 0; i<m; i++){
				for(int j = 0; j<n; j++){
					string pos = getpos(i, j);
					if(ans[pos]==INF){
						printf("%s: %s\n", pos.c_str(), G[pos].c_str());
					}
				}
			}
		}else{
			
			printf(" ");
			for(int i = 0; i<n; i++){
				printf("%6d", i);
			}
			printf("\n");
			
			
			for(int i = 0; i < m; i++){
				printf("%c", 'A'+i);
				for(int j = 0; j<n; j++){
					printf("%6d", ans[getpos(i, j)]);
				}
				printf("\n");
			}
		}
		
		printf("\n");
	}
	return 0;
}
