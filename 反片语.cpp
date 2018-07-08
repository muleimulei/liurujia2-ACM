#include<cstdio>
#include<string>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#include<algorithm>
#include<map>

#include<vector>
using namespace std;
int main(){
	
	map<string, int> m;
	set<string> s;
	string str;
	vector<string> v;
	while(cin>> str && str!="#"){
		string b = str;
		for(int i = 0; i< str.size(); i++) str[i] = tolower(str[i]);
		sort(str.begin(), str.end());
		
		if(m[str]==0){
			m[str] = 1;
			v.push_back(b);
		}else{
			m[str] ++;
		}
	}
	for(int i = 0; i< v.size(); i++){
		string str = v[i];
		for(int i = 0; i< str.size(); i++) str[i] = tolower(str[i]);
		sort(str.begin(), str.end());
		if(m[str]==1) s.insert(v[i]);
	}
	
	auto beg = s.begin(), end = s.end();
	while(beg!=end){
		cout<<*beg<<endl;
		beg++;
	}
	return 0;
} 
