#include<cstdio>

int main(void)
{
  int n;
  int wina[3] = {0},winb[3] = {0};
  int handa[3] = {0}, handb[3] = {0};
  char map[3] = {'B', 'C','J'};
  char c1,c2;
  scanf("%d",&n);

  while(n--)
  {
    getchar();
    scanf("%c %c", &c1, &c2);
    switch(c1)
    {
      case 'C':
        {
          switch(c2)
          {
            case 'C':
              wina[1]++;
              winb[1]++;
              break;
            case 'J':
              wina[0]++;
              winb[2]++;
              handa[1]++;
              break;
            case 'B':
              wina[2]++;
              winb[0]++;
              handb[0]++;
              break;
          }
          break;
        }
      case 'J':
        {
          switch(c2)
          {
            case 'C':
              wina[2]++;
              winb[0]++;
              handb[1]++;
              break;
            case 'J':
              wina[1]++;
              winb[1]++;
              break;
              
            case 'B':
              wina[0]++;
              winb[2]++;
              handa[2]++;
              break;
              
          }
          break;
        }

      case 'B':
        {
          switch(c2)
          {
            case 'C':
              wina[0]++;
              winb[2]++;
              handa[0]++;
              break;
            case 'J':
              wina[2]++;
              winb[0]++;
              handb[2]++;
              break;
            case 'B':
              wina[1]++;
              winb[1]++;
              break;
              
          }
          break;
        }
    }
  }
  printf("%d %d %d\n",wina[0],wina[1], wina[2]);
  printf("%d %d %d\n",winb[0],winb[1], winb[2]);
  int ka = 0, kb = 0;
  for(int i = 0; i < 3; i++)
  {
    if(handa[i] > handa[ka])
    {
      ka = i;
    }
    if(handb[i] > handb[kb])
    {
      kb =i;
    }
  }
  printf("%c %c",map[ka],map[kb]);
  
  
  return 0;
}





