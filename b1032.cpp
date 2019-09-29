#include<cstdio>

const int maxn = 100001;

int main()
{
  int n,id, score, temp = 0,sum = 0;
  int t_score[maxn]={0};
  
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d%d", &id, &score);
    t_score[id] += score;
  }
  for(int i = 0; i < maxn; i++)
  {
    sum += t_score[i];
    if(t_score[i]>=temp)
    {
      temp = t_score[i];
    }
  }
  printf("%d %d",temp,sum);
  
}