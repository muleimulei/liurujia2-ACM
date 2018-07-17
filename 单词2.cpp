
#include<stdio.h>

#include<string.h>

 

void dfs(int n);

bool euler();

 

int graph[26][26];

int in[26];

int out[26];

int vis[26];

 

int main()

{

  int t;

  scanf("%d",&t);

  while(t-->0)

  {

    memset(in,0,sizeof(in));

    memset(out,0,sizeof(out));

    memset(vis,0,sizeof(vis));

    memset(graph,0,sizeof(graph));

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;++i)

    {

      char str[1010];

      scanf("%s",str);

      int a=str[0]-'a';

      int b=str[strlen(str)-1]-'a';

      out[a]++;   

      in[b]++;    

      graph[a][b]=1;

    }

    if(euler()) printf("Ordering is possible.\n");

    else printf("The door cannot be opened.\n");

  }

  return 0;  

}

 

bool euler()

{

  int cnt=0;

  for(int i=0;i<26;++i)

  {

    if((in[i]||out[i])&&vis[i]==0)

    {

      vis[i]=1;

      dfs(i);

      cnt++;           

    }

  } 

  if(cnt!=1) return false;//不连通 

  

  int num=0;

  int flag=0;

  for(int i=0;i<26;++i)

  {

    if(in[i]==out[i]) continue;

    num++;

    if(num>2) return false;//最多只有两个点的出入度不等 

    if(in[i]==(out[i]+1)) {flag=flag+1; continue;}

    if(in[i]==(out[i]-1)) {flag=flag+2; continue;}

    return false;    

  }

  if(flag!=3 && flag!=0)//flag最后只经过两次加法，正好各一次时flag为3

    return false; //不要忘了flag还可以等于0 

  else return true;

}

 

void dfs(int n)

{

  for(int i=0;i<26;++i)

  {

    if(graph[n][i]||graph[i][n])

    {

      if(vis[i]==0) { vis[i]=1; dfs(i);}                          

    }

  }

}

