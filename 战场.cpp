#include<cstdio>
#include<cstring>
#include<cmath>

#include<algorithm>
const int maxn = 1000+10;
const double w = 1000.0;
int vis[maxn];

double x[maxn], y[maxn], r[maxn];
int n; //敌人个数 
double left,right;

bool intersect(int a, int b){ // 判断两圆是否相交 
	return sqrt( (x[a]-x[b])*(x[a]-x[b]) + (y[a] - y[b])*(y[a]-y[b]) ) < r[a]+r[b];
}

void check(int i){
	if(x[i]-r[i]<0){
		left = std::min(left, y[i] - sqrt(r[i]*r[i] - x[i]*x[i]));
	}
	if(x[i] + r[i] >w){
		right = std::min(right, y[i] -  sqrt( r[i]*r[i] - (w - x[i])*(w-x[i]) ));
	}
}

bool dfs(int i){
//	if(vis[i]) return false;
	vis[i] = 1;
	if(y[i] - r[i]<0) return true;
	for(int k = 0; k<n;k++){
		if(!vis[k] && intersect(i, k) && dfs(k) ){
			return true;
		}
	}
	check(i);
	return false;
}

int main(){
	while(scanf("%d", &n)!=EOF){
		memset(vis, 0, sizeof(vis));
		left = right = w;
		bool f = true;
		for(int i = 0; i<n;i++){
			scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
		}
		for(int i = 0; i<n;i++){
			if(y[i]+r[i] >= w &&!vis[i] && dfs(i)){
				f = 0;
				break;
			}
		}
		if(f) printf("0.00 %.2lf %.2lf %.2lf\n", left, w, right);
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}

