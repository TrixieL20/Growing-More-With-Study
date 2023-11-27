#include <bits/stdc++.h>
using namespace std;

int main() {
	int idx, mid, idx_t, pos = 0, res = 0;
	string expr, cal;
	vector <int> idxs;
	
	cin >> expr;
	
	idx = expr.find("-", pos);
	
	// - 기호 위치 파악 
	while (idx != string::npos) {
		idxs.push_back(idx);
		pos = idx + 1;
		idx = expr.find("-", pos);
	}
	
	while(idxs.size() != 0) {
		mid = 0;
		idx = idxs.back();
		idxs.pop_back();
		
		// cal에는 - 이후 계산할 식 저장 
		cal = expr.substr(idx + 1);
		expr = expr.substr(0, idx);
		
		idx = cal.find("+", 0);
		while (idx != string::npos) {
			mid += stoi(cal.substr(0, idx));
			cal = cal.substr(idx + 1);
			idx = cal.find("+", 0);
		}
		
		pos = cal.find("-", 0);
		
		if (pos != string::npos) {
			mid += stoi(cal.substr(0, pos));
			expr = expr + "-" + to_string(mid) + cal.substr(pos);
		}
		else {
			mid += stoi(cal);
			expr = expr + "-" + to_string(mid);
		}
	}
	
	idx = expr.find("-", 0);
	while (idx != string::npos) {
		idxs.push_back(idx);
		pos = idx + 1;
		idx = expr.find("-", pos);
	}
	
	idx = expr.find("+", 0);
	while (idx != string::npos) {
		idxs.push_back(idx);
		pos = idx + 1;
		idx = expr.find("+", pos);
	}
	
	sort(idxs.begin(), idxs.end());
	idxs.push_back(expr.length());
	
	res += stoi(expr.substr(0, idxs[0]));
	for (int i = 0; i < idxs.size() - 1; i++) {
		pos = idxs[i];
		if (expr[pos] == '+') {
			res += stoi(expr.substr(idxs[i] + 1, idxs[i + 1]));
		}
		else if (expr[pos] == '-') {
			res -= stoi(expr.substr(idxs[i] + 1, idxs[i + 1]));
		}
	}
	cout << res;
}