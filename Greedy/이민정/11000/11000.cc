#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, S, T;
	vector <pair <int, int>> list;
	pair <int, int> t;
	priority_queue <int, vector<int>, greater<int>> pq;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		t.first = S;
		t.second = T;
		list.push_back(t);
	}
	sort(list.begin(), list.end());
	
	pq.push(list[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() <= list[i].first) {
			pq.pop();
			pq.push(list[i].second);
		}
		else
			pq.push(list[i].second);
	}
	cout << pq.size();
} 