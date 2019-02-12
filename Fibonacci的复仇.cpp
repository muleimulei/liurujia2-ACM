#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10000000;
struct node{
	int num;
	node * p[10];
	node(){
		num = -1;
		for(int i = 0; i< 10; i++){
			p[i] = NULL;
		}
	}
} buf[maxn];
int tot = 0;

node * create(){
	return &buf[tot++];
}

string a = "1", b = "1";
node* head = create();

string add(string a, string b){
	int i = a.size()-1, j = b.size()-1;
	int up = 0,x,y,z;
	string s;
	while(i>=0 || j>=0){
		if(i<0) x = 0;
		else x = a[i] - '0';
		if(j<0) y = 0;
		else y = b[j] - '0';
		
		z = x+y+up;
		s += (z%10 + '0');
		up = z / 10;
		
		i--;
		j--;
	}
	if(up>0) s+=(up + '0');
	reverse(s.begin(), s.end());
	return s;
}

void insert(string s, int val){
	node * nn = head;
	for(int i = 0; i < s.size(); i++){
		int m = s[i] - '0';
		if(nn->p[m] == NULL){
			nn->p[m] = create();
		}
		nn = nn->p[m];
		if(nn->num<0) nn->num = val;
	}
}

void init(){
	insert(a, 0);
	insert(b, 1);
	for(int i = 2; i<100000;i++){
		string sum = add(a, b);
		insert(sum.substr(0, 40), i);
		a = b;
		b = sum;
	}
}

int sh(string s){
	node *nn = head;
	for(int i = 0; i<s.size(); i++){
		int v = s[i] - '0';
		if(nn->p[v]){
			nn = nn->p[v];
		}else{
            return -1;
		}
	}
	return nn->num;
}

int main(){
#ifdef LOCAL
	freopen("1.txt","r",stdin);
	freopen("1.out", "w", stdout);
#endif
	int n, kase = 0;
	init();
	cin>>n;
	while(n--){
		string f;
		cin>>f;
		cout<<"Case #"<< ++kase<<": "<<sh(f)<<"\n";
	}
	return 0;
}
