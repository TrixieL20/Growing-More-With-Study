#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> jew;
int bag[300001];
//�������� ����
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
		//idx�� ���� �������� �۰� ����[idx]�� ù��°(����)�� ������ ���Ժ��� �۰ų� ������
		while (idx < n && jew[idx].first <= bag[i])
			//jew[idx++]�� push(�ش��ϴ°� ���� push)
			pq.push(jew[idx++].second);
		if (!pq.empty()) {
			//�������� �����̶� top���� ���� ���� ���� ���� ������� ��
			result += pq.top();
			pq.pop();
		}
	}
	cout << result << endl;
	return 0;
}