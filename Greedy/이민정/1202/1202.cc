#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, M, V, C;
    long long ret = 0;
    // Vi ≤ 1,000,000, K ≤ 300,000 -> ret 최대 값 3*10^11 over int (4byte)
    
    priority_queue <int> pq;
    vector <int> backpack;
    pair <int, int> jewel;
    vector <pair <int, int>> list;
    
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
    	cin >> M >> V;
    	jewel.first = M;
    	jewel.second = V;
    	list.push_back(jewel);
	}
	
	for (int j = 0; j < K; j++) {
		cin >> C;
		backpack.push_back(C);
	}
	
	sort(list.begin(), list.end());
    sort(backpack.begin(), backpack.end());
	
	int idx = 0;
		
	for (int i = 0; i < K; i++) {
		while (backpack[i] >= list[idx].first && idx < N) {
			pq.push(list[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			ret += pq.top();
			pq.pop();
		}
	}
	cout << ret;
}