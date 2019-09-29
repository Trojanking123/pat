#include<cstdio>

int main(void)
{
	int a,b;
	int sum = 0;
	int result[32];

	scanf("%d%d",&a,&b);

	do
	{
		result[sum++] = a%b;
		a /= b;
	}while(a != 0);
	int flag = 1;
	int k = sum--;
	for(int i = 0; i <= k/2; i++)
	{
		if(result[i] != result[k-i])
		{
			flag = 0;
			break;
		}
	}
	if(flag == 1)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	for(int i = sum-1; i >=0; i--)
	{
		printf("%d",result[i] );
	}
	return 0;
}