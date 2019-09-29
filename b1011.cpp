#include<cstdio>

int main()
{
  int n, n1;
  int caseid = 1;
  long long int a, b, c;
  scanf("%d", &n);
  n1 = n;
  bool juge[n];
  while(n--)
  {
    scanf("%lld%lld%lld", &a,&b,&c);
    if(a+b>c)
    {
      juge[caseid - 1] = true;
      caseid++;
    }
    else
    {
      juge[caseid - 1] = false;
      caseid++;

    }
  }
  for(int i = 0; i < n1; i++)
  {
    if(juge[i])
    {
      printf("Case #%d:true\n", i+1);
    }
    else
    {
      printf("Case #%d:false\n",i+1);
    }
  }
  
  return 0;
}
