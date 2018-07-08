#include<cstdio>
#include<map>
#include<cstring>
#include<stack>
#include<cctype>
#include<iostream>

using namespace std;
map<char, pair<int, int> > m;
stack<char> s;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		string s;
		cin>>s;
		int a, b;
		cin>>a>>b;
		m[s[0]] = make_pair(a,b);
//		printf("%c %d %d", s[0], a, b);
	}
	
	string exp;
	char b = 'a';
	while(cin>>exp){
		int ans = 0;
		while(!s.empty()) s.pop();
		int ok = 1;
		for(int i = 0; i < exp.size(); i++){
			if(isalpha(exp[i])){
				s.push(exp[i]);
			}
			if(exp[i] == ')'){
				pair<int, int> n1,n2;
				char c1 = s.top(); s.pop();
				char c2 = s.top(); s.pop();
				
				n1 = m[c1];
				n2 = m[c2];
				
				if(n1.first != n2.second) {
					ok = 0;
					break;
				}
				ans += n1.second * n2.first * n2.second;
				s.push(b);
				m[b] =  make_pair(n2.first, n1.second);
				b++;
			}
		}
		if(ok){
			printf("%d\n", ans);
		}else{
			puts("error");
		}
	}
	return 0;
}
