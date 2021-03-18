#include <stdio.h>
//#include <vector>
#include <string.h>
#include <algorithm>

long long books[510];
int num,k;

int solve(int m)
{
	int ans = 0;
	long long tot = 0;
	for(int i = 0; i < num; i++)
	{
		if(tot + books[i] > m)
		{
			ans++;
			tot = books[i];
		}
		else
		{
			tot += books[i];
		}
	}
	
	return ans + 1;
}


//Ì°ÐÄËã·¨ 
int last[503];
void print(long long ans) {
  long long done = 0;
  memset(last, 0, sizeof(last));
  int remain = k;
  for(int i = num-1; i >= 0; i--) {
    if(done + books[i] > ans || i+1 < remain) {
      last[i] = 1; remain--; done = books[i];
    }
    else {
      done += books[i];
    }
  }
  for(int i = 0; i < num-1; i++) {
    printf("%d ", books[i]);
    if(last[i]) printf("/ ");
  }
  printf("%d\n", books[num-1]);
}


int main()
{
	#ifdef LOCAL
		freopen("1.txt", "r", stdin);
	#endif
	int n;
	scanf("%d", &n);
	while(n--)
	{
		
		scanf("%d%d", &num, &k);
		
		memset(books, 0, sizeof(books));
		long long s = -1, total = 0;
		
		for(int i = 0; i < num; i++)
		{
			int m;
			scanf("%d", &m);
			books[i] = m;
			total += m;
			s = std::max(s, books[i]);
		}
		
		long long  l = s, r = total;
		
		while(l < r)
		{
			long long m = l + (r-l)/2;
			if(solve(m) <= k)
			{
				r = m;
			}
			else
			{
				l = m+1;
			}
		}
		print(l);
	}
	return 0;
}
