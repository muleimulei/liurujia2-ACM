/*
	该程序通过
	如果一个容器需要 首尾删除 则优先考虑deque(双端队列) 
*/
#include<cstdio>
#include<list>
#include<vector>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
#include<deque> 
#include<set>

using namespace std;

deque<int> deck, piles[7];
map<vector<int>, int> m;
set<string> s;
int tot, h;
int d;
bool loop = false;


int getpos(int k){
	k++;
	for(int i = 0; i<7;i++){
		int n = (k+i) % 7;
		if(piles[n].size()) return n;
	}
}
void place(int d){
	if(deck.size()){
		int f = deck.front();
		piles[d].push_back(deck.front());
		deck.pop_front();	
	}
}

void judge(int k) {
	deque<int> &v = piles[k];
	if(v.size() >2){
		int f1 = v[0], f2 = v[1], l1 = v[v.size()-1], l2 = v[v.size()-2], l3 = v[v.size()-3];
		if(f1+f2+l1==10 || f1+f2+l1==20 || f1+f2+l1==30 ){
			deck.push_back(f1);
			deck.push_back(f2);
			deck.push_back(l1);
			
			v.pop_front();
			v.pop_front();
			v.pop_back();

			judge(k);
			return;
			
		}else if( f1 + l1 + l2 == 10 || f1 + l1 + l2 == 20 || f1 + l1 + l2 == 30  ) {
			deck.push_back(f1);
			deck.push_back(l2);
			deck.push_back(l1);
			
			v.pop_front();
			v.pop_back();
			v.pop_back();
					
			judge(k);
			return;
			
		}else if(l1+l2+l3==10 || l1+l2+l3==20 || l1+l2+l3==30  ){
			deck.push_back(l3);
			deck.push_back(l2);
			deck.push_back(l1);
			
			v.pop_back(); v.pop_back(); v.pop_back();
			judge(k);
			return;
		}
	}
}

void jiami(string &s){
	s.clear();
	for(int i = 0; i<7; i++){
		if(piles[i].size()){
			deque<int> &v = piles[i];
			for(auto i: v){
				s += (char)i;
			}
		}
		s += "|";
	}
	
	for(auto i: deck){
		s += (char) i;
	}
} 

bool solve(){
	int k = -1;
	while(1){
		if(d==0) return 1;
		if(deck.size()==0) return 0;
		string m;
		jiami(m);
		if(s.count(m)){
			loop  =1;
			return 0;
		}else s.insert(m);
		
		k = getpos(k);
		place(k); // 放置一张牌
		judge(k);
		if(piles[k].size()==0){
			d--;
		}
		tot++;
	}
}

int main(){
	while(1){
		int n;
		scanf("%d", &n);
		if(n==0) break;
		tot = 7; // 总共放牌多少次 
		d = 7; // 总堆数 
		loop = 0;
		s.clear();

		// 清空 
		deck.clear();
		for(int i = 0; i < 7; i++){
			piles[i].clear();
		}
		deck.push_back(n);
		for(int i = 0; i < 51; i++){
			scanf("%d", &n);
			deck.push_back(n);
		}
//		cout<<deck[0]<<"  "<<deck[51]<<endl;
		// init
		for(int i = 0; i<7;i++){
			piles[i].push_back(deck.front());
			deck.pop_front();
		}
		if(solve()){
			printf("Win : %d\n", tot);
		}else{
			if(loop){
				printf("Draw: %d\n", tot);
			}else{
				printf("Loss: %d\n", tot);
			}
		}
 	}
	
	return 0;
} 
