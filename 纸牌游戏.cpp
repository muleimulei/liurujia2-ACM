#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
const int maxn = 52+10;
vector<string> vv[maxn];
int tot;
bool f,f1;

bool judge(string s1, string s2){
	if(s1[0]==s2[0] || s1[1]==s2[1]) return true;
	return false;
}

int goback(int p, int s){
	int i;
	for(i = 1; p>=0 && i<=s ;i++ ){
		do{
			p--;
		}while(p>=0 &&vv[p].size()==0);
	}
	
	return p;
}

void solve(bool &f){
	int p = 0;
//	while(p<52 && vv[p].size()==0) p++;
	string s1,s2, s3;
	bool ff = 1;
	while(p < 52){
		s1 = s2 = s3 = "";
		bool e = 0;
		int p1 = goback(p,3);
		int p2 = goback(p, 1);
		if(p1>=0 && vv[p1].size()) {
			s1 = vv[p1].back();
		}
		if(p2>=0 && vv[p2].size()){
			s2 = vv[p2].back();
		}
		
		s3 = vv[p].back();
		
		if(s1!="" && judge(s1, s3)){
			e = 1;
			vv[p1].push_back(s3);
			vv[p].pop_back();
			if(vv[p].size()==0) tot--;
			p = p1;
			if(ff){
				f = !f;
				ff = 0;
			}
		}else if(s2!= "" &&judge(s2, s3)){
			vv[p2].push_back(s3);
			vv[p].pop_back();
			if(vv[p].size()==0) tot--;
			p = p2;
			e = 1;
			if(ff){
				f = !f;
				ff = 0;
			}
		}	
		if(!e){
			do{
				p++;
				if(p>=52) break;
			}while(p<52 && vv[p].size()==0);
		}
	}
}


int main(){
	string s;
	while(cin>>s){
		if(s=="#") break;
		for(int i = 0; i<maxn;i++) vv[i].clear();
		for(int i = 0; i < 52; i++){
			vv[i].push_back(s);
			if(i==51) break;
			cin>>s;
		}

		tot = 52;
		f = f1 = 1;
		while(1){
			solve(f1);
			f = !f;
			if(f !=f1) break;
		}
		if(tot==1){
			printf("1 pile remaining:");
		}else{
			printf("%d piles remaining:", tot);
		}
		for(int i = 0; i<52; i++){
			if(vv[i].size()){
				printf(" %d", vv[i].size());
			}
		}
		printf("\n");
	}
	return 0;
}
