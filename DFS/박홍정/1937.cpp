#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;
int n, Map[501][501]; 
int dp[501][501]; //움직인 칸 수 저장
int ans=0;
// 왼 오 아 위
int dy[] = { 0,0,-1,1 }, dx[] = { -1,1,0,0 };

int dfs(int y, int x) {
	if (dp[y][x])//이미 과거에 최대로 이동한 칸을 구했으면
		return dp[y][x];//리턴
	dp[y][x] = 1; //판다는 최소 한 칸에는 존재하니 1에서 시작
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (Map[ny][nx] > Map[y][x])//현재칸보다 대나무가 더 많다면
			//기존 값과 다른 칸으로 이동했을때 값 비교
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