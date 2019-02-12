#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

typedef set<int> Set;
map<Set, int> IDcache; // 把集合映射成ID
vector<Set> Setcache; // 根据ID取集合

int ID(Set s){
	if(IDcache.count(s)) return IDcache[s];
	Setcache.push_back(s);
	return IDcache[s] = Setcache.size()-1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		IDcache.clear();
		Setcache.clear();
		stack<int> s;
	int n;
	cin>>n;
	while(n--){
		string op;
		cin>>op;
		if(op[0] == 'P') s.push(ID(Set()));
		else if(op[0] == 'D') s.push(s.top());
		else{
			Set x1 = Setcache[s.top()]; s.pop();
			Set x2 = Setcache[s.top()]; s.pop();
			Set x;
			if(op[0] == 'U') set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()) );
			if(op[0] == 'I') set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()) );
			if(op[0] == 'A') {
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout<<Setcache[s.top()].size()<<endl;
	}
	cout<<"***"<<endl;
	}
	return 0;
}
