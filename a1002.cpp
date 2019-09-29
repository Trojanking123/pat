#include<cstdio>
int main(void)
{
  const int maxn = 1111;
  int n;
  double a[maxn] = {0};
  int e;
  double coe;
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d%lf",&e,&coe);
    a[e] = coe;
  }
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    scanf("%d%lf",&e,&coe);
    a[e] += coe;
  }
  int count = 0;
  for(int i = 0; i< maxn; i++)
  {
    if(a[i] != 0)
    {
      count++;
    }
  }
  printf("%d",count);
  for(int i = maxn-1; i >= 0; i--)
  {
    if(a[i] != 0)
    {
      printf(" %d %.1f",i,a[i]);
    }
  }
  
  return 0;
}