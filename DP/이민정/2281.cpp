#include <bits/stdc++.h>
using namespace std;
int dp [1001][1001];
int l[1001];
int n, m;

int DP(int name, int len) {
	if (name >= n)
		return 0;
	int& res = dp[name][len];
	
	if (res != -1) return dp[name][len];
	
	res = (m - len + 1) * (m - len + 1) + DP(name + 1, l[name] + 1);
	
	if (len + l[name] <= m)
		res = min(res, DP(name + 1, len + l[name] + 1));
	return res;
}

int main() {
	vector <int> name;
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) cin >> l[i];
	memset(dp, -1, sizeof(dp));
	cout << DP(0, 0) << "\n";
}