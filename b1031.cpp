#include<cstdio>

int main(void)
{
	int n;
	char id[20];
	int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char code[12]={"10X98765432"};
	int sum = 0;
	
	int flag = 0;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%s",id);
		for(int i = 0; i < 17; i++)
		{
			sum += (id[i]-'0') * weight[i];

		}
		if(code[sum%11] != id[17])
		{
			flag = 1;
			printf("%s\n",id);
		}
		sum = 0;
		n--;
	}
	if(flag == 0)
	{
		printf("All passed");
	}
	return 0;
}