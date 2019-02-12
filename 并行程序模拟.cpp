#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include<cctype>
#include<cstring>
const int maxn = 10000;
using namespace std;

int num, Q;
int w[5];
int var[30] = {0}, pos[maxn]={0};


int judge(string &s){
	if(s.find("=")!=string::npos) return 0;
	if(s.find("print")!=string::npos) return 1;
	if(s.find("unlock")!=string::npos) return 3;
	if(s.find("lock")!=string::npos) return 2;
	if(s.find("end")!=string::npos) return 4;
}
int getnumber(string &s){
	int pos = s.find_last_of(" ");
	return stoi(s.substr(pos+1));
}

int main(){
	while(cin>>num>>w[0]>>w[1]>>w[2]>>w[3]>>w[4]>>Q){
		getchar();
		memset(var, 0, sizeof(var));
		memset(pos,0,sizeof(pos));
		
		vector<string> cmd[maxn];
		deque<int> ready, stop;

		bool flag = false;
		
		for(int i = 1; i<=num; i++){
			while(1){
				string s;
				getline(cin ,s);
				cmd[i].push_back(s);
				if(s == "end"){
					break;
				}
			}
			ready.push_back(i);
		}
		
		while(!ready.empty()){
			bool over = false;
			int d = ready.front();

			ready.pop_front();
			int time = Q;
			while(time>0){
				string s =  cmd[d][pos[d]];
				int id =  judge(s);
//				cout<<s<<endl;
//				int time = Q;
//				if(time>0){

					if(id == 0){
						var[s[0]-'a'] = getnumber(s);

					}else if(id == 1){
						cout<<d<<": "<<var[s[s.size()-1] - 'a']<<endl;
						
					}else if(id == 2){
						if(flag){
							stop.push_back(d);
							over = true;
							break;
						}else{
							flag = true;
						}
					}else if(id == 3){
						flag = false;
						if(!stop.empty()){
							int g = stop.front();stop.pop_front();
							ready.push_front(g);
						}
					}else if(id == 4){
						over = true;
						break;
					}
//				}else break;
				time -= w[id];
				pos[d]++;
			}
			if(!over){
				ready.push_back(d);
			}
		}
	}
	
	return 0;
}
