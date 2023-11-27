//���� �п����� ť �����Ѵٰ� �� ������ �ƴµ� �̷��� ���Ҽ���
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//class_time�̶�� ���� ����
vector< pair < int, int > > class_time;
//pq��� �̸��� �������� �켱���� ť
priority_queue< int, vector<int>, greater<int> > pq;

int greedy(int class_count)
{
	//class_time[0].second==ù ��° ���� ���� �ð�
	pq.push(class_time[0].second);
	for (int i = 1; i < class_count; ++i)
	{
		pq.push(class_time[i].second);
		//���� top����ð����� i��° ������ �ʰ� �����Ѵٸ�(ex) 2 3/4 5)
		if (pq.top() <= class_time[i].first)
			pq.pop();
	}
	return pq.size();
}

int main()
{
	int n;
	cin >> n;
	int start_time, end_time;
	for (int i = 0; i < n; i++) {
		cin >> start_time >> end_time;

		//push_back=>���� ���κп� ������ ����
		//pair ������ ���� �� ���� make_pair(��1,��2)���
		class_time.push_back(make_pair(start_time, end_time));
	}
	//sort�� �ʹ� ����
	sort(class_time.begin(), class_time.end());
	cout << greedy(n) << endl;
	
}