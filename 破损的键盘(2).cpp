#include<list>
#include<cstdio>
#include<cstring>
#define maxn 100000+10

char buf[maxn];

int main(){
	while(scanf("%s", buf)!=EOF){
		int r = 1, len = strlen(buf);
		std::list<char >s;
		int p = 0, m = p;
		for(int i = 0; i< len;i++){
			char c = buf[i];
			if(c =='[') {
				r = -1;
				p = 0;
			}
			else if(c == ']'){
				 r = 1;
				 p = 0;
			}
			else{
				if(r == 1){
					s.insert(s.end(),c);
				}else{
					auto h = s.begin();
					m = p;
					while(p--){
						h++;
//						printf("%c\n", *h);
					}
					
					s.insert(h, c);
					p = m;
					p++;
//					printf("%d\n", p);
				}
			}
		}
		auto beg = s.begin(), end = s.end();
		while(beg!=end){
			printf("%c", *beg);
			beg++;
		}
		printf("\n");
	}
	
	return 0;
}
