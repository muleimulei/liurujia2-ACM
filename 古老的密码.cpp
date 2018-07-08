#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
	char buf1[101], buf2[101];
	while(scanf("%s %s", buf1, buf2)!=EOF){
		int len = strlen(buf1);
		
		int n1[26]={0}, n2[26]={0};
		
		for(int i = 0; i< len; i++){
			char c1 = buf1[i];
			char c2 = buf2[i];
			
			n1[c1-'A'] ++;
			n2[c2-'A'] ++;
		}
		vector<int> v1, v2;
		for(int i = 0; i< 26; i++){
			if(n1[i]!=0){
				v1.push_back(n1[i]);
			}
			if(n2[i]!=0){
				v2.push_back(n2[i]);
			}
		}
		
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		
		v1==v2? puts("YES") : puts("NO");
	}
	return 0;
}
