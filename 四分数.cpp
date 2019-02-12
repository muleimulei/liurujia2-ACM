#include<cstdio>
#include<cstring>

const int len = 32;
const int maxn = 1024+10;

char s[maxn];
int buf[len][len], cnt;

/*
2	1
3   4
把字符串s[p...] 导出到以(r,c)位左上角，边长为w的缓冲区
*/

void draw(char * s, int &pos, int r, int c, int w){
	char f = s[pos++];
	if(f == 'p'){
		draw(s, pos, r, c + w/2, w/2);
		draw(s, pos, r, c, w/2);
		draw(s,pos,r+w/2, c, w/2);
		draw(s,pos, r+w/2,c+w/2,w/2);
	}else if(f == 'f'){
		for(int i = r; i<r+w; i++){
			for(int j = c; j<c+w;j++){
				if(buf[i][j] == 0){
					buf[i][j] = 1;
					cnt++;
				}
			}
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		memset(buf, 0, sizeof(buf));
		cnt = 0;
		for(int i = 0; i<2;i++){
			scanf("%s", s);
			int pos = 0;
			draw(s, pos, 0, 0, len);
		}
		printf("There are %d black pixels.\n", cnt);
	}
	return 0; 
}
