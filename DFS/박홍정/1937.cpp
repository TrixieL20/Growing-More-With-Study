#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, Map[501][501]; 
int dp[501][501]; //������ ĭ �� ����
int ans=0;
// �� �� �� ��
int dy[] = { 0,0,-1,1 }, dx[] = { -1,1,0,0 };

int dfs(int y, int x) {
	if (dp[y][x])//�̹� ���ſ� �ִ�� �̵��� ĭ�� ��������
		return dp[y][x];//����
	dp[y][x] = 1; //�Ǵٴ� �ּ� �� ĭ���� �����ϴ� 1���� ����
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (Map[ny][nx] > Map[y][x])//����ĭ���� �볪���� �� ���ٸ�
			//���� ���� �ٸ� ĭ���� �̵������� �� ��
			dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
	}
	return dp[y][x];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			scanf("%d", &Map[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = max(ans, dfs(i, j));
	printf("%d", ans);
}