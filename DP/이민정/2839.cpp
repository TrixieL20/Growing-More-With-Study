#include <bits/stdc++.h>
using namespace std;

int main() {
	int dp[5001] = {0, };
	int n;
	
	cin >> n;
	dp[3] = 1, dp[5] = 1;
	
	for (int i = 6; i <= n; i++) {
		if (dp[i-5]) dp[i] = dp[i-5] + 1;
		if (dp[i-3]) dp[i] = dp[i] ? min(dp[i], dp[i - 3] + 1) : dp[i - 3] + 1;
	}
	
	cout << (dp[n] == 0 ? -1 : dp[n]);
	return 0;
}