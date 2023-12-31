#include <bits/stdc++.h>
using namespace std;

int snail[1000][1000];

int main() {
	int n, f;
	cin >> n >> f;
	
	int num = 1, temp = 1, x = n/2, y = n/2;
	
	snail[x][y] = num;
	while(num < n*n) {
		for (int i = 0; i < temp; i++) {
			snail[--x][y] = ++num;
			if (num == n * n) break;
		}
		if (num == n * n) break;
		for (int i = 0; i < temp; i++) snail[x][++y] = ++num;
		temp++;
		for (int i = 0; i < temp; i++) snail[++x][y] = ++num;
		for (int i = 0; i < temp; i++) snail[x][--y] = ++num;
		temp++;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << snail[i][j] << " ";
		}
		cout << "\n";
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (snail[i][j] == f) {
				cout << i + 1 << " " << j + 1;
				return 0;
			}
		}
	}
}