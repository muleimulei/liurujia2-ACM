#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn]; // 每个pile[i] 是一个vector


//找木块a所在的pile和height，以引用的形式返回给调用者 
void find_block(int a, int &p, int &h){
	for(p = 0; p< n; p++){
		for(h = 0; h < pile[p].size(); h++){
			if(pile[p][h] == a) return;
		}
	}
}

// 把第P堆高度为h的木块全部归位
void  clear_above(int p, int h){
	for(int i = h+1; i < pile[p].size(); i++){
		int l = pile[p][i];
		pile[l].push_back(l);
	}
	pile[p].resize(h+1);
}

// 把第p堆高度为h及其上方的木块整体移动到p2堆的顶部
 
void pile_onto(int pa, int ha, int pb){
	for(int i = ha; i< pile[pa].size(); i++){
		pile[pb].push_back(pile[pa][i]);
	}
	pile[pa].resize(ha);
}

void print(){
	for(int i =0; i< n;i++){
		printf("%d:", i);
		for(int j = 0; j < pile[i].size(); j++){
			printf(" %d", pile[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int a,b;
	cin>>n;
	string s1, s2;
	for(int i = 0; i< n; i++) pile[i].push_back(i);
	while(cin>>s1>>a>>s2>>b){
		if(s1=="quit") break;
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);
		
		if(pa == pb) continue; // 非法指令
		if(s2== "onto") clear_above(pb, hb);
		if(s2 == "move") clear_above(pa, hb);
		pile_onto(pa, ha, pb); 
	}
	print();
	return 0;
}
