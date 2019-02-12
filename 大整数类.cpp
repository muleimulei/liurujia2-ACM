#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long LL;

struct BigInteger{
	static const int BASE = 100000000;
	static const int WIDTH = 8;
	vector<LL> s;
	bool flag;
	BigInteger (long long num = 0) {
		if(num<0){
			flag = false;
			*this = -num;
		}else{
			flag = true;
			*this = num;
		}
 	}
	BigInteger (string s){
		*this = s;
	}
	BigInteger operator  = (long long num){ // 赋值运算符
		if(num<0){
			flag = false;
			num *=-1;
		}else{
			flag = true;
		}
		s.clear();
		do{
			s.push_back(num % BASE);
			num /= BASE;
		}while(num > 0);
		return *this;
	}
	BigInteger operator = (string &str){
		if(str[0]=='-'){
			flag = false;
			str = str.substr(1, str.size()-1);
		}else{
			flag = true;
		}
//		cout<<str;
		s.clear();
		int x, len = ( str.size() - 1 ) / WIDTH + 1; // 计算需要几个8位
		for(int i = 0; i < len; i++){
			int end = str.size() - i * WIDTH;
			int start = max(0, end - WIDTH);
			sscanf(str.substr(start, end-start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return *this;
	}
	BigInteger & operator += (BigInteger &x){
		return *this = *this + x;
	}
	BigInteger operator - (BigInteger &c){
		if(*this == c) return BigInteger(0);
		BigInteger ans;
		//ans.s.clear();
		if(flag * c.flag == 0){
			if(flag==false && c.flag == true){
				this->flag = true;
				ans = *this + c;
				ans.flag = false;
				return ans;
			}else if(c.flag == false && flag == true){
				c.flag = true;
				ans.flag = true;
				ans = *this + c;
				return ans;
			}else if(c.flag == false && flag == false){
				c.flag = true;
				this->flag = true;
				return c - *this;
			}
		}else{
			if(flag == 1 && c.flag==1){
				if( c < *this){
					ans.s.clear();
					for(int i = 0, m = 0;i<s.size() ; i++){
						
						LL f = 0, g = 0, r;
						if(i < s.size()) f = s[i];
						if(i < c.s.size()) g = c.s[i];
						if(f < g){
							r = pow(10, BASE) + f - g - m;
							m = 1;
						}else{
							r = f - g;
							m = 0;
						}
						ans.s.push_back(r);
					}
					return ans;
				}else{
					ans = c - *this;
					ans.flag = false;
					return ans;
				}
			}
		}
	}
	bool operator == (BigInteger c){
		return flag == c.flag && c.s == s;
	}
	BigInteger operator + (BigInteger &t){
		if(flag * t.flag == 0){
			if(flag==false && t.flag == true){
				this->flag = true;
				return t-*this;
			}else if(flag == true && t.flag == false){
				t.flag = true;
				return *this - t;
			}else {
				BigInteger c;
				this->flag = true;
				t.flag = true;
				c = *this + t;
				c.flag = false;
				return c;
			}
		}
		
		BigInteger c;
		c.s.clear();
		for(int i = 0, g = 0; ; i++){
			if(g==0 && i >= s.size() && i>= t.s.size()) break;
			LL x = g;
			if(i<s.size()) x+=s[i];
			if(i<t.s.size()) x+=t.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
//		c.flag = t.flag;
		return c;
	}

	BigInteger operator * (const BigInteger &t){
		vector<BigInteger> v;
		for(int i = 0; i < t.s.size(); i++){
			LL g = 0, x = t.s[i];
			BigInteger w;
			w.s.clear();
			for(int j = 0; j < s.size(); j++){
				LL d = x * s[j] + g;
				w.s.push_back(d % BASE);
				g = d / BASE;
			}
			if(g!=0) w.s.push_back(g);
			for(int f = 0; f<v.size(); f++){
				w.s.insert(w.s.begin(), 0);
			}
			v.push_back(w);
		}
		BigInteger ans;
		for(int i = 0; i<v.size(); i++){
			ans  = ans +  v[i];
		}
		if(t.flag * flag == 1) ans.flag = true;
		else ans.flag = false;
		return ans;
	}
	bool operator < (BigInteger c){
		if(s.size()!= c.s.size()) return s.size() < c.s.size();
		else{
			for(int i = s.size()-1; i>=0;i--){
				if(s[i] != c.s[i]) return s[i] < c.s[i];
			}
		}
		return false;
	}
};
	ostream & operator << ( ostream &out, const BigInteger &x){
		x.flag? out<<x.s.back() : out<<"-"<<x.s.back();
		for(int i = x.s.size()-2; i>=0; i--){
			char buf[20];
			sprintf(buf, "%08d", x.s[i]);
			out<<buf;
		}
		return out;
	}

	istream& operator >> (istream &in, BigInteger &x){
		string s;
		if(!(in>>s)) return in;
		x = s;
		return in;
	}
	
	
int main(){
	BigInteger a,b;
	cin>>a>>b;
//	cout<<a<<b;
	cout<<a + b;
	return 0;
}
