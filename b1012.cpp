#include<cstdio>


int main()
{
  int a[1000];
  int n = 0;
  int a1 = 0,a2 = 0,a3 = 0;
  double a4;
  int sum4 = 0;
  int biggest5 = 0;
  int count2 = 1;
  int count4 = 0;
  int a5 = 0;
  //memset(a,0,sizeof(a));
  scanf("%d",&n);
  int i = 0;
  while(scanf("%d", a+i) == 1)
  {
    i++;
  }
  for(int i = 0; i < n; i++)
  {
    /******************************************************************************/
    if(a[i] % 5 == 0 && a[i] % 2 == 0)
    {
      a1 += a[i];
    }
    /******************************************************************************/
    if(a[i] % 5 == 1)
    {
      if(count2 % 2 == 1)
      {
        a2 += a[i];
      }
      else
      {
        a2 -= a[i];
      }
      count2++;
    }
    /******************************************************************************/
    if(a[i] %5 == 2)
    {
      a3++;
    }
    /******************************************************************************/
    if(a[i] % 5 == 3)
    {
      sum4 += a[i];
      count4++;
    }
    /******************************************************************************/
    if(a[i] % 5 == 4)
    {
      if(a[i]>biggest5)
      {
        biggest5 = a[i];
      }
    
    }
  }
  if(count4>0)
  {
    a4 = (double)sum4/(double)count4;
  }
  a5 = biggest5;
  if(a1 == 0) printf("N ");
  else printf("%d ",a1);
  
  if(count2 == 1) printf("N ");
  else printf("%d ",a2);
  
  if(a3 == 0) printf("N ");
  else printf("%d ",a3);
  
  if(count4 == 0) printf("N ");
  else printf("%.1f ",a4);
  
  if(a5 == 0) printf("N");
  else printf("%d",a5);
  
  
  return 0;
}