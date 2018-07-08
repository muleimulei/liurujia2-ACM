#include<stdio.h>
#include<string.h>
#include<iostream> 
#define maxn 1000

int main(){
	char buf1[maxn], buf2[maxn];
	while(std::cin>>buf2>>buf1){
		int len1 = strlen(buf1), len2 = strlen(buf2);
		int pos = 0,i;
		bool f = true;
		for(i = 0; i< len2; ){
			char c = buf2[i];
			while(buf1[pos]){
				if(c!= buf1[pos]) pos++;
				else {
					i++;
					pos++;
					break;
				}
			}
			if(!buf1[pos] && i<len2) {
				f = false;
				break;
			}
		}
		if(f){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}
