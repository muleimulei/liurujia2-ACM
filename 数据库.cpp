#include<map>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
int n, p;
map<string, int> m;
vector<string> v;

int ID(string s){
	if(m.count(s)) return m[s];
	v.push_back(s);
	return m[s] = v.size() - 1;
}

int name[10000 + 10][10 + 10];
void find(){
	 for(int i = 0; i < p; i++){
			for(int j = i+1; j<p; j++){
				map<pair<int, int>, int> ss;
				for(int k = 0; k<n;k++){
					pair<int, int> l(name[k][i], name[k][j]);
					if(ss.count(l) ==0){
						ss[l] = k;
					}else{
						puts("NO");
						cout<<ss[l] + 1<<" "<<k+1<<endl;
						cout<<i+1<<" "<<j+1<<endl;
						return;
					}
				}
			}
		}
		puts("YES");
}
int main(){
	
	while(cin>>n>>p){
		getchar();
		m.clear();
		v.clear();
		for(int i = 0; i < n; i++){
			string s;
			getline(cin, s);
//			getchar();
			s += ",";
			int j = 0,start = 0, pos = 0;
			while((pos = s.find(',', start))!=string::npos){
				string r = s.substr(start, pos-start);
//				cout<<r<<" "<<s<<endl;
				name[i][j++] = ID(r);
				pos++;
				start =pos;
			}
		}

		find();
	}
	return 0;
}
