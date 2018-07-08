#include<cstdio>
#include<string>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
using namespace std;

int main(){
	set<string> s;
	string str;
	while(cin>>str){
		for(int i = 0; i< str.size(); i++){
			if(isalpha(str[i])){
				str[i] = tolower(str[i]);
			}else{
				str[i] = ' ';
			}
		}
		stringstream ss(str);
		while(ss>>str) s.insert(str);
//		ss>>str;
//		s.insert(str);
	}
	set<string>::iterator beg = s.begin(), end = s.end();
	while(beg!=end){
		cout<<*beg<<endl;
		beg++;
	}
	return 0;
}
