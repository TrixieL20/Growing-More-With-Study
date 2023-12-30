#include <bits/stdc++.h>
using namespace std;

string house[26];
int visited[26][26]; // 0으로 알아서 초기화 됨
int dir_y[4] = {1, -1, 0, 0};
int dir_x[4] = {0, 0, 1, -1};
vector <int> result;
int N, cnt = 0;

void DFS(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int cur_y = y + dir_y[i], cur_x = x + dir_x[i];
		if (cur_y <= N && cur_y > 0 && cur_x <= N && cur_x > 0 && visited[cur_y][cur_x] == 0 && house[cur_y][cur_x] == '1') {
			visited[cur_y][cur_x] = 1;
			cnt++;
			DFS(cur_y, cur_x);
		}
	}
}

int main() {
	string line;
	
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> line;
		house[i] = " " + line;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (house[i][j] == '1' && visited[i][j] == 0) {
				visited[i][j] = 1;
				cnt = 1;
				DFS(i, j);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
}