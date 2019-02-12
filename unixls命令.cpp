#include<string>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int maxcol = 60;

void print(string s,int size, char c){
	cout<<s;
	for(int i = 0; i<size - s.size(); i++){
		cout<<c;
	}
}
int main(){
	int n;
	while(cin>>n ){
		vector<string> v;
		int maxname = 0;
		while(n--){
			string name;
			cin>>name;
			v.push_back(name);
			maxname = max(maxname, (int)name.size());
		}
		sort(v.begin(), v.end());
	// 计算行数与列数
	int cols = (maxcol - maxname)/ (maxname+2) +1;
	int rows = (v.size() - 1) / cols + 1;

	print("", 60, '-');
	cout<<"\n";

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int idx = rows * j  + i;
			if(idx < v.size()) print(v[idx], j == cols - 1 ?maxname: maxname + 2,' ');
		}
		cout<<"\n";
	}
	}
	return 0;
}
