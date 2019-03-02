#include<cstdio>

/*
	最长路及其字典序：嵌套矩形问题；
		如何求DAG中不固定起点的最长路径呢？，设d(i)表示从节点i出发的最长路长度，第一步只能走到 它的相邻节点
		因此：d(i) = 1 + max(d(j)) ,(i,j)属于E。其中，E为边集。最终答案是所有d(i)中的最大值。接下来编写记忆化搜索程序
		(调用前需初始化d数组的所有值为0)
		int dp(int k){
			int &ans = d[k];
			if(ans>0) return ans;
			ans = 1;
			for(int i = 0; i < n; i++){
				if(G[k][i]) ans  = max(ans, 1 + dp(i));
			}
			return ans;
		}
		void print_ans(int i){
			printf("%d ", i);
			for(int j = 1; j <= n; j++){
				if(G[i][j] && d[i] == d[j]+1){
					print_ans();
					break;
				}
			}
		}
	固定终点的最长路和最短路:
		int dp(int S){
			int &ans = d[S];
			if(ans!=-1) return ans;
			ans = -(1<<30);
			for(int i = 1; i <= n; i++){
				if(S>= v[i]){
					ans = max(ans, 1 + dp(S-v[i]));
				}
			}
			return ans;
		}
	递推方法：
		minv[0] = maxv[0] = 0;
		for(int i = 1; i<=S; i++){
			minv[i] = INF; maxv[i] = -INF;
		}
		
		for(int i = 1; i<=S; i++){
			for(int j = 1; j<= n; j++){
				if(i >= V[j]){
					minv[i] = min(minv[i], minv[i- v[j]]+1);
					maxv[i] = max(maxv[i], maxv[i- v[j]]+1);
				}
			}
		}
		printf("%d %d\n", minv[S], maxv[S]);
	
		输出字典序最小的方案：
			void print_ans(int *d, int s){
				for(int i = 1; i <= n; i++){
					if(s>=v[i] && d[s]==d[s-v[i]]+1){
						print_ans(d, i);
						break;
					}
				}
			}
*/
