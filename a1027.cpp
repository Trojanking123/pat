#include<cstdio>

int main(void)
{
	char output[15] = {"0123456789ABC"};
	int a,b, n;
	int result[3];
	int k = 3;
	printf("#");
	while(k != 0) {
		scanf("%d",&n);
		a = n%13;
		b = n/13;
		printf("%c%c", output[b],output[a]);
		k--;
	}



	return 0;
}