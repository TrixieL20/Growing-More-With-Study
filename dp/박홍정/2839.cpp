#include<stdio.h>
//그리디로 충분히 풀림
int main()
{
	int n;
	int k = 0;
	scanf("%d", &n);
	while (n>=0)
	{
		if (n % 5 == 0)
		{
			k += n / 5;
			printf("%d", k);
			return 0;
		}
		n -= 3;
		k++;
	}
		printf("-1");
}