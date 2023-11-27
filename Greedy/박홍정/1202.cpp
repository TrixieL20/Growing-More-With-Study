#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> jew;
int bag[300001];
//내림차순 정렬
priority_queue< int, vector<int>, less<int> > pq;

int main()
{
	int n, k, m, v;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jew.push_back(make_pair(m, v));
	}

	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}
	sort(jew.begin(), jew.end());
	sort(bag, bag + k);

	int idx = 0;
	long long int result = 0;
	for (int i = 0; i < k; i++) {
		//idx가 보석 갯수보다 작고 벡터[idx]의 첫번째(무게)가 가방의 무게보다 작거나 같으면
		while (idx < n && jew[idx].first <= bag[i])
			//jew[idx++]에 push(해당하는거 전부 push)
			pq.push(jew[idx++].second);
		if (!pq.empty()) {
			//내림차순 정렬이라 top에는 가장 가격 높은 것이 들어있을 것
			result += pq.top();
			pq.pop();
		}
	}
	cout << result << endl;
	return 0;
}