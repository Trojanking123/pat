#include<cstdio>

int main(void)
{
  int n;
  scanf("%d", &n);
  int sum = 0;
  int dist[n];
  for(int i = 0; i < n; i++)
  {
    scanf("%d",dist + i);
    sum += dist[i];
    
  }
  
  int k ;
  scanf("%d",&k);
  int a,b,suma = 0,sumb = 0;
  int sumk = 0;
  while(k--)
  {
    scanf("%d%d",&a,&b);
    if(a>b)
    {
      int temp = a;
      a = b;
      b = temp;
    }
    if((b-a)>n/2)
    {
      for(int i = a-1; i != b-1; i = (i+n-1)%n)
      {
        sumk += dist[(i+n-1)%n];
      }
    }
    else
    {
      for(int i = a-1; i != b-1; i = (i+1)%n)
      {
        sumk += dist[i];
      }
    }
    printf("%d\n",(sum-sumk>sumk)?sumb:sum-sumk );
    //printf("%d\n",(suma>sumb)?sumb:suma );
    suma = 0;
    sumb = 0;
    sumk = 0;
    
  }
  
  return 0;
}