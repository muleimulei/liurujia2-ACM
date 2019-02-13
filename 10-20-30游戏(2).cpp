#include<deque>
#include<cstdio>
#include<list>
#include<string>
#include<set>
using namespace std;

const int maxn = 52;
deque<int> cards, piles[7];
list<deque<int> *> l;
set<string> alls;


// 10-20-30
void check(deque<int> &q){
	int size = q.size();
	if(size < 3) return;
	if( (q[0] + q[1] + q.back()) % 10==0 ){
		cards.push_back(q[0]);
		cards.push_back(q[1]);
		cards.push_back(q.back());
		
		q.pop_front(); q.pop_front(); q.pop_back();
		check(q);
		return ;
	}
	
	if( (q[0] + q[size-1] + q[size-2]) % 10 ==0){
		cards.push_back(q[0]);
		cards.push_back(q[size-2]);
		cards.push_back(q[size-1]);
		
		q.pop_front();
		q.pop_back();
		q.pop_back();
		
		check(q);
		return;
	}
	
	
	if( (q[size-3] + q[size-2]+q[size-1])%10==0 ){
		cards.push_back(q[size-3]);
		cards.push_back(q[size-2]);
		cards.push_back(q[size-1]);
		
		q.pop_back(); q.pop_back(); q.pop_back();
		
		check(q);
		return;
	}
	
	
}


// 对整体状态进行编码 
void encode(string &s){
	s.clear();
	for(auto &p: l){
		deque<int> &pp = *p;
		for(auto i: pp){
			s += (char)i;
		}
		s+="|";
	} 
	for(auto i: cards) s+=(char)i;
}

bool solve(int t){
	if(l.size()==0) {
		printf("Win : %d\n", t);
		return 0;
	}
	if(cards.empty()){
		printf("Loss: %d\n", t);
		return 0;
	}
	
	string s;
	encode(s);
	
	if(alls.count(s)){
		printf("Draw: %d\n", t);
		return 0;
	}
	else alls.insert(s);
	
	int c = cards.front();
	cards.pop_front();
	l.push_back(l.front());
	l.pop_front();
	
	deque<int> &p = *(l.back());
	p.push_back(c);
	
	check(p);
	if(p.empty()) l.pop_back();
	
	return 1;
}


int main(){

	while(1){
		cards.clear();
		l.clear();
		alls.clear();
		
		for(int i = 0; i < 52; i++){
			int x;
			scanf("%d", &x);
			if(x==0) return 0;
			cards.push_back(x);
		}
		
		// 初始化
		for(int i = 0; i < 7; i++){
			deque<int> &p = piles[i];
			p.clear();
			p.push_back(cards.front());
			cards.pop_front();
			l.push_back(&p);
		} 
		
		int t = 7;
		while(1){
			if(!solve(t++)){
				break;
			}
		}
	}
	return 0;
}
