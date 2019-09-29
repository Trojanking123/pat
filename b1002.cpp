#include<cstdio>
#include<cstring>
int main(void)
{

	char change[10][5] = {"ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	char num[120];
	int sum = 0;
	int k = 0;
	int code[4] = {0};

	scanf("%s", num);
	int n = strlen(num);
	for(int i = 0; i < n; i++)
	{
		sum += num[i]-'0';
	}
	do
	{
		code[k++] = sum % 10;
		sum /= 10;
	}while(sum != 0);

	for(int i = k - 1; i >= 0; i--)
	{
		printf("%s", change[code[i]]);
		if(i != 0)
		{
			printf(" ");
		}
	}


	return 0;
}