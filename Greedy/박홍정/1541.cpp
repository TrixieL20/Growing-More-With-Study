#include<stdio.h>
#include<string.h>

int main()//¿Ö
{
	char str[51];
	int arr[51] = { 0 };
	scanf("%s", str);
	int len = strlen(str);
	int sum = 0, tmp = 0, j = 0, result = 0;

	for (int i = 0; i <= len; i++)
	{
		if (str[i] == '-' || i == len) {
			sum += tmp;
			arr[j] = sum;
			j++;
			tmp = 0;
			sum = 0;
		}
		else if (str[i] == '+') {
			sum += tmp;
			tmp = 0;
		}
		else
		{
			tmp = tmp * 10;
			tmp = tmp + str[i] - '0';
		}
	}
	result = arr[0];
	for (int i = 1; i < j; i++) {
		result = result - arr[i];
	}
	printf("%d", result);
}