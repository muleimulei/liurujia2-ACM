#include<cstdio>
#include<cmath>
#include<algorithm>
const int maxn = 55;
double x[maxn], y[maxn], d[maxn][maxn];
int n;

double dist(int i, int j){
	return sqrt( (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}

double solve(int i, int j){
	double &ans  = d[i][j];
	if(ans>0) return ans;
	if(i==n-1) ans =  dist(n-1, n) + dist(j, n);
	else ans = std::min(solve(i+1, j)+ dist(i, i+1), solve(i+1, i)+dist(j, i+1));
	return ans;
}

int main(){
	while(scanf("%d", &n)==1){
		for(int i = 1; i<=n; i++){
			scanf("%lf %lf", &x[i], &y[i]);
		}
		for(int i = 1; i<=n; i++){
			for(int j = 1; j<=i; j++){
				d[i][j] = -1;
			}
		}
		printf("%.2lf\n", solve(2, 1) + dist(1,2));
	}	
	return 0;
}
