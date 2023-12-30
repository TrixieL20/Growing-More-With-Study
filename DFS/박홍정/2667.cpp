//내가 학원에서 큐 구현한다고 별 난리를 쳤는데 이렇게 편할수가
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//class_time이라는 벡터 생성
vector< pair < int, int > > class_time;
//pq라는 이름의 오름차순 우선순위 큐
priority_queue< int, vector<int>, greater<int> > pq;

int greedy(int class_count)
{
	//class_time[0].second==첫 번째 수업 종료 시간
	pq.push(class_time[0].second);
	for (int i = 1; i < class_count; ++i)
	{
		pq.push(class_time[i].second);
		//만일 top종료시간보다 i번째 수업이 늦게 시작한다면(ex) 2 3/4 5)
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

		//push_back=>벡터 끝부분에 데이터 저장
		//pair 변수에 값을 줄 때엔 make_pair(값1,값2)사용
		class_time.push_back(make_pair(start_time, end_time));
	}
	//sort가 너무 좋음
	sort(class_time.begin(), class_time.end());
	cout << greedy(n) << endl;
	
}