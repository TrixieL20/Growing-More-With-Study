#include <bits/stdc++.h>
using namespace std;

int n, m, blue = 0, white = 0, dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool visited[101][101];
char war[101][101];

void BFS(int y, int x, char team) {
	queue <pair<int, int>> q;
	q.push({y, x});
	visited[y][x] = true;
	int count = 0;
	
	while (!q.empty()) {
		pair <int, int> now = q.front();
		q.pop();
		count++;
		
		for (int i = 0; i < 4; i++) {
			int ny = now.first + dir[i][0], nx = now.second + dir[i][1];
			if (ny <= m && ny >= 1 && nx <= n && nx >= 1 && !visited[ny][nx] && war[ny][nx] == team) {
				visited[ny][nx] = true;
				q.push({ny, nx});
			}
		}
	}
	if (team == 'W')
		white += count * count;
	else
		blue += count * count;
}

int main(void)
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> war[i][j];

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (!visited[i][j])
				BFS(i, j, war[i][j]);

	cout << white << ' ' << blue;
	return 0;
}