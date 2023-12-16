#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int student[401][4];
int map[21][21]; // ��ü �� ũ��
int N; // �Է¹��� N 
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

// ������ ��Ƶ� ����ü
struct Info {
    int x;
    int y;
    int empty;
    int match;
};

// ���� ��Ģ ������ �Լ�
bool compare(Info a, Info b) {
    // ��Ī ���� ���ٸ�
    if (a.match == b.match) {
        // ��ĭ ���� ���ٸ�
        if (a.empty == b.empty) {
            // ���� ���ٸ�
            if (a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        }
        return a.empty > b.empty;
    }
    return a.match > b.match;
}

// key : �ڸ��� �ɴ� �л� ��ȣ, x: ��, y: ��
Info bfs(int key, int x, int y) {
    Info tmp = { x,y,0,0 };
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
        // �ش� �ڸ��� ��������� ��ĭ+1
        if (map[nx][ny] == 0) {
            tmp.empty++;
            continue;
        }
        // �ش� �ڸ��� �����ϴ� �л��� �ɾ��ִٸ� ��Ī+1
        for (int j = 0; j < 4; j++) {
            if (student[key][j] == map[nx][ny]) tmp.match++;
        }
    }
    return tmp; // ���ŵ� Info ��ȯ
}

// �ش� �л� �ڸ� ���� ���μ��� ����(key : �л� ��ȣ)
void matching(int key) {
    vector<Info> list; // �ش� ĭ�� Info ������ ����
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0) list.push_back(bfs(key, i, j));
        }
    }
    sort(list.begin(), list.end(), compare); // ���� ��Ģ�� ���� ����
    map[list[0].x][list[0].y] = key; // �ֿ켱���� �ڸ��� ����
}

// ���� ���
int getScore() {
    int sum = 0;
    // k : �л� ��ȣ
    for (int k = 1; k <= N * N; k++) {
        for (int i = 1; i <= N; i++) {
            bool endFlag = false;
            for (int j = 1; j <= N; j++) {
                if (map[i][j] == k) {
                    Info tmp = bfs(k, i, j);
                    sum += pow(10, tmp.match - 1);
                    endFlag = true;
                    break;
                }
            }
            if (endFlag) break;
        }
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    vector<int> order; // �ڸ��� �ɴ� ����
    for (int i = 1; i <= N * N; i++) {
        int key;
        scanf("%d", &key);
        order.push_back(key);
        for (int j = 0; j < 4; j++) {
            int num;
            scanf("%d", &num);
            student[key][j] = num;
        }
    }
    // ������� �ڸ��� ������ ����
    for (int i = 0; i < order.size(); i++) {
        matching(order[i]);
    }
    cout << getScore() << "\n";
}