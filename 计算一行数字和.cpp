#include<cstdio>
#include<sstream>
#include<string>
#include<iostream>
using namespace std;

int main(){
	string buf;
	while(getline(cin, buf)){
		stringstream ss(buf);
		int sum = 0, i;
		while(ss>>i){
			sum += i;
		}
        cout<<sum<<endl;
	}
	return 0;
}
