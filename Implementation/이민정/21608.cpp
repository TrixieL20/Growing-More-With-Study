#include <bits/stdc++.h>
using namespace std;
int seat[20][20];
bool compare(vector <int> a, vector <int> b) {
	if (a[0] == b[0]) {
		if (a[1] == b[1]) {
			if (a[2] == b[2]) {
				return a[3] < b[3];
			}
			return a[2] < b[2];
		}
		return a[1] > b[1];
	}
	return a[0] > b[0];
}

int main() {
	vector <vector <int>> student;
	int n, a, ret = 0;
	cin >> n;
	int N = n * n;
	
	for (int i = 0; i < N; i++) {
		vector <int> like;
		for (int j = 0; j < 5; j++) {
			cin >> a;
			like.push_back(a);
		}
		student.push_back(like);
	}
	
	for (int s = 0; s < N; s++) {
		int n_s = student[s][0];
		vector <vector <int>> infos;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (seat[i][j] != 0) continue;
				vector <int> info;
				int cnt = 0;
				if (i - 1 >= 0 && (seat[i - 1][j] == student[s][1] || seat[i - 1][j] == student[s][2]
				|| seat[i - 1][j] == student[s][3] || seat[i - 1][j] == student[s][4])) cnt++;
				if (i + 1 < n && (seat[i + 1][j] == student[s][1] || seat[i + 1][j] == student[s][2]
				|| seat[i + 1][j] == student[s][3] || seat[i + 1][j] == student[s][4])) cnt++;
				if (j - 1 >= 0 && (seat[i][j - 1] == student[s][1] || seat[i][j - 1] == student[s][2]
				|| seat[i][j - 1] == student[s][3] || seat[i][j - 1] == student[s][4])) cnt++;
				if (j + 1 < n && (seat[i][j + 1] == student[s][1] || seat[i][j + 1] == student[s][2]
				|| seat[i][j + 1] == student[s][3] || seat[i][j + 1] == student[s][4])) cnt++;
				info.push_back(cnt);
				
				// 빈자리 확인 
				cnt = 0;
				if (i - 1 >= 0 && seat[i - 1][j] == 0) cnt++;
				if (i + 1 < n && seat[i + 1][j] == 0) cnt++;
				if (j - 1 >= 0 && seat[i][j - 1] == 0) cnt++;
				if (j + 1 < n && seat[i][j + 1] == 0) cnt++;
				info.push_back(cnt);
				info.push_back(i);
				info.push_back(j); 
				infos.push_back(info);
			}
		}
		sort(infos.begin(), infos.end(), compare);
		seat[infos[0][2]][infos[0][3]] = n_s;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int s;
			for (int l = 0; l < N; l++) {
				if (student[l][0] == seat[i][j])
				s = l;
			}
			
			int cnt = 0;
			if (i - 1 >= 0 && (seat[i - 1][j] == student[s][1] || seat[i - 1][j] == student[s][2]
			|| seat[i - 1][j] == student[s][3] || seat[i - 1][j] == student[s][4])) cnt++;
			if (i + 1 < n && (seat[i + 1][j] == student[s][1] || seat[i + 1][j] == student[s][2]
			|| seat[i + 1][j] == student[s][3] || seat[i + 1][j] == student[s][4])) cnt++;
			if (j - 1 >= 0 && (seat[i][j - 1] == student[s][1] || seat[i][j - 1] == student[s][2]
			|| seat[i][j - 1] == student[s][3] || seat[i][j - 1] == student[s][4])) cnt++;
			if (j + 1 < n && (seat[i][j + 1] == student[s][1] || seat[i][j + 1] == student[s][2]
			|| seat[i][j + 1] == student[s][3] || seat[i][j + 1] == student[s][4])) cnt++;
			
			if (cnt == 1) ret += 1;
			else if (cnt == 2) ret += 10;
			else if (cnt == 3) ret += 100;
			else if (cnt == 4) ret += 1000;
		}
	}
	
	cout << ret;
}