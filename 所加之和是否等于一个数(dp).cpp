#include<cstdio>
#include<cstring>
/*

opt(i, ans) = opt(i-1, ans-arr[i]) || opt(i-1, ans)

决策到i位置时，和为ans , 答案为opt(6, ans) 

*/
int arr[] = {2,4,6,9,8,5,1,11};
int d[10][100];

bool solve(int pos, int ans){
	int &a = d[pos][ans];
	if(a!=-1) return a;
	
	if(pos==0) return arr[pos]==ans;
	if(ans==0) return 1;
	if(arr[pos] > ans) return solve(pos-1, ans);
	else{
		return a = solve(pos-1, ans-arr[pos]) || solve(pos-1, ans);
	}
}
int main(){
	int ans;
	while(scanf("%d", &ans)==1){
		memset(d, -1, sizeof(d));
		printf("%d\n", solve(6, ans));
	}
	return 0;
}
