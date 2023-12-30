#include <bits/stdc++.h>
using namespace std;

int forest[501][501];
int dp[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

int bigger(int a, int b) { return a > b ? a : b; }

int search(int x, int y) {
	if (dp[x][y] != 0) return dp[x][y];
	dp[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (forest[x][y] < forest[nx][ny])
				dp[x][y] = bigger(dp[x][y], search(nx, ny) + 1);
		}
	}
	return dp[x][y];
}

int main() {
	int ans = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> forest[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = bigger(ans, search(i, j));
		}
	}
	
	cout << ans;
}