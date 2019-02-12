#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<sstream>
#include<vector>

using namespace std;
map<string, int> IDcache;
vector<string> cache;
const int maxn = 1000000;
vector<int> depend[maxn], depend2[maxn];
int status[maxn];
vector<int> installed;


int ID(string s){
	if(IDcache.count(s)) return IDcache[s];
	cache.push_back(s);
	return IDcache[s] = cache.size()-1;
}

void install(int item, bool top){
	if(!status[item]){
		for(int i = 0; i < depend[item].size(); i++){ // °²×°ÒÀÀµ 
			install(depend[item][i], 0);
		}
		cout<<"   Installing "<<cache[item]<<endl;
		status[item] = top ? 1:2;
		installed.push_back(item);
	}
}

bool needed(int item){
	for(int i = 0; i<depend2[item].size(); i++){
		if(status[depend2[item][i]]) return true;
	}
	return false;
}

void remove(int item, int top){
	if((top || status[item]==2) && !needed(item)) {
		status[item] = 0;
		installed.erase(find(installed.begin(), installed.end(), item));
		cout<<"   Removing "<<cache[item]<<"\n";
		for(int i = 0; i< depend[item].size(); i++){
			remove(depend[item][i], 0);
		}
	}
}

void list(){
	for(int i = 0; i < installed.size(); i++){
		cout<<"   "<<cache[installed[i]]<<"\n";
	}
}

int main(){
	#ifdef LOCAL
		freopen("1.in", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	string line;
	while(getline(cin, line)){
		cout<<line<<endl;
		if(line == "END") break;
		stringstream ss(line);
		string s;
		ss>>s;
		
		string d;
		ss>>d;
		int i = ID(d);
		if(s == "DEPEND"){
			while(ss>>d){
				depend[i].push_back(ID(d));
				depend2[ID(d)].push_back(i);
			}
		}else if(s == "INSTALL"){
			if(status[i]){
				cout<<"   "<<d<<" is already installed."<<endl;
			}
			else install(i, true);
		}else if(s == "REMOVE"){
			if(!status[i]) cout<<"   "<<d<<" is not installed.\n";
			else if (needed(i)) {
				cout<<"   "<<d<<" is still needed.\n";
			}else{
				remove(i, true);
			}
		}else if(s == "LIST"){
			list();
		}
	}
	return 0;
}

