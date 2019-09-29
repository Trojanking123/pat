#include<cstdio>
int main()
{
  int n, m;
  scanf("%d%d",&n,&m);
  int a[n];
  m = m%n;
  for(int i = 0; i < n; i++)
  {
    scanf("%d", a+i);
  }
  for(int i = n - m; i < n; i++)
  {
    printf("%d ",a[i]);
  }
  for(int i = 0; i< n-m; i++)
  {
    printf("%d",a[i]);
    if(i != n-m-1)
    {
      printf(" ");
    }
  }
  
  return 0;
}